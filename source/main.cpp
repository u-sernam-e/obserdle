#include <vector>
#include <string>
#include "rayextended.h" 
#include "basedata.h"
#include "wordlist.h"
#include "wordinput.h"
#include "button.h"
#if defined(PLATFORM_WEB)
	#include <emscripten/emscripten.h>
#endif

// update clipboard text to have proper #day and link

struct GameData
{
	BaseData base;
	std::string word;
	WordInput wrdInput;
	std::vector<std::string> guessedWords{};
	bool win{false};
	Button copyButt;
};

GameData data;

Color letterState(char letter, int pos, std::string guess) // what a mess
{
	if (letter == data.word[pos]) return GREEN;

	std::vector<int> lettersInWord{};
	std::vector<int> lettersInGuess{};
	for (int i{}; i < data.word.size(); ++i)
	{
		if (data.word[i] == letter) lettersInWord.push_back(i);
	}
	for (int i{}; i < guess.size(); ++i)
	{
		if (guess[i] == letter) lettersInGuess.push_back(i);
	}
	
	if (lettersInWord.empty()) return GRAY;

	if (lettersInGuess.size() <= lettersInWord.size()) return GOLD;

	int correctGuesses{};
	for (int i{}; i < data.word.size(); ++i)
		if (guess[i] == data.word[i] == letter) correctGuesses += 1;
	
	int possibleYellows{lettersInWord.size() - correctGuesses};

	for (int i{}; i < lettersInGuess.size(); ++i)
	{
		if (possibleYellows <= 0)
		{
			lettersInGuess.erase(lettersInGuess.begin() + i);
			--i;
		}
		--possibleYellows;
	}

	for (int i{}; i < lettersInGuess.size(); ++i)
	{
		if (pos == lettersInGuess[i])
		{
			if (i < lettersInWord.size()) return GOLD;
			else return GRAY;
		}
	}

	return GRAY;
}

bool youWon()
{
	if (data.guessedWords.size() > 0)
	{
		for (int i{}; i < data.guessedWords[data.guessedWords.size()-1].size(); ++i)
		{
			Color letterColor{letterState(data.guessedWords[data.guessedWords.size()-1][i], i, data.guessedWords[data.guessedWords.size()-1])};
			if (letterColor != GREEN)
				return false;
		}
		return true;
	}
	return false;
}

bool youLost()
{
	return data.guessedWords.size() == 6 && !data.win;
}

void init()
{
	initBD(data.base);
	data.copyButt = Button{{188, 528}, {184, 69}, LIGHTGRAY, Color{190, 190, 190, 255}, Color{210, 210, 210, 255}, "COPY RESULTS", WHITE, false, false, false, {}, false, &data.base.fs, "res/Roboto.ttf"};
	data.wrdInput.init(&data.base);
	data.word = getTodaysWord();
}

void setObserdleClipboardText()
{
	std::string text{"🦅Daily Obserdle🦅 #"};
	text.append(std::to_string(getTheDay() - 19698));
	if (youLost())
		text.append(" 😢/6\n\n");
	else
		text.append(" " + std::to_string(data.guessedWords.size()) + "/6\n\n");

	for (int i{}; i < data.guessedWords.size(); ++i)
	{
		for (int j{}; j < data.guessedWords[i].size(); ++j)
		{
			Color stateCol = letterState(data.guessedWords[i][j], j, data.guessedWords[i]);
			if (stateCol == GRAY) text.append("⬛");
			if (stateCol == GOLD) text.append("🟨");
			if (stateCol == GREEN) text.append("🟩");

		}
		text.append("\n");
	}
	text.append("\n(link to observer website)");

	SetClipboardText(text.c_str());
}

void update()
{
	updateBD(data.base);
	data.wrdInput.update();
	if (data.wrdInput.isSubmitting())
	{
		data.guessedWords.push_back(data.wrdInput.getWord());
	}
	if (youWon())
	{
		data.win = true;
		data.wrdInput.win();
	}
	if (data.win || youLost())
	{
		data.copyButt.update();
		if (data.copyButt.pressed())
			setObserdleClipboardText();
	}
}

void drawObserdleText()
{
	DrawTextEx(data.base.fs.get("res/Roboto.ttf", 75), "Obserdle!", {45, 7}, 75, 1, BLACK);
}

void drawSquares()
{
	for (int i{}; i < 6; ++i)
	{
		for (int j{}; j < 5; ++j)
		{
			DrawRectangle(j*75+2, i*75+79, 71, 71, Color{10, 30, 20, 100});
		}
	}
}

void drawColoredSquares()
{
	for (int i{}; i < data.guessedWords.size(); ++i)
	{
		for (int j{}; j < data.guessedWords[i].size(); ++j)
		{
			DrawRectangle(j*75+2, i*75+79, 71, 71, letterState(data.guessedWords[i][j], j, data.guessedWords[i]));
		}
	}
}

void drawGuessedWords()
{
	for (int i{}; i < data.guessedWords.size(); ++i)
	{
		for (int j{}; j < data.guessedWords[i].size(); ++j)
		{
			DrawTextEx(data.base.fs.get("res/Roboto.ttf", 75), data.guessedWords[i].substr(j, 1).c_str(), {15 + 75*j, 75 + 75*i}, 75, 0, BLACK);
		}
	}
}

void drawWin()
{
	DrawTextEx(data.base.fs.get("res/Roboto.ttf", 20), "Great work eagle!", {25, 600-47}, 20, 0, BLACK);
}

void drawLoss()
{
	DrawTextEx(data.base.fs.get("res/Roboto.ttf", 20), (std::string("Nice try!\nCorrect word: " + data.word)).c_str(), {15, 600-62}, 20, 0, BLACK);
}

void draw()
{
	ClearBackground(Color{245, 242, 240, 255});

	drawObserdleText();
	drawSquares();
	drawColoredSquares();
	drawGuessedWords();
	data.wrdInput.draw();
	drawBD(data.base);
	if (data.win) drawWin();
	if (youLost()) drawLoss();
	if (data.win || youLost()) data.copyButt.draw();
}

void updateDrawFrame()
{
	//UPDATE
	update();
	//DRAW
	BeginDrawing();
	draw();
	EndDrawing();
}

int main()
{
	InitWindow(375, 600, "Obserdle");
    InitAudioDevice();
	init();

#if defined(PLATFORM_WEB)
	emscripten_set_main_loop(updateDrawFrame, 0, 1);
#else
	while (!WindowShouldClose() || IsKeyPressed(KEY_ESCAPE))
	{
		updateDrawFrame();
	}
#endif
	return 0;
}