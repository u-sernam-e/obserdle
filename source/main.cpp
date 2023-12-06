#include "rayextended.h" 
#include <vector>
#include <string>
#include "basedata.h"
#include "wordlist.h"
#include "wordinput.h"
#if defined(PLATFORM_WEB)
	#include <emscripten/emscripten.h>
#endif

/*
checklist:
only allow real words (HARD)
victory/defeat screen
copy and past prompt at bottom*/

struct GameData
{
	BaseData base;
	std::string word;
	WordInput wrdInput;
	std::vector<std::string> guessedWords{};
	bool win{false};
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
		if (guess[i] == data.word[i]) correctGuesses += 1;
	
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
			if (letterColor.r != 0 || letterColor.g != 228 || letterColor.b != 48)
				return false;
		}
		return true;
	}
	return false;
}

void init()
{
	initBD(data.base);
	data.wrdInput.init(&data.base);
	data.word = getTodaysWord();
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
}

void drawObserdleText()
{
	DrawTextEx(data.base.fs.get("res/Roboto.ttf", false), "Obserdle!", {50, 10}, 100, 1, BLACK);
}

void drawSquares()
{
	for (int i{}; i < 6; ++i)
	{
		for (int j{}; j < 5; ++j)
		{
			DrawRectangle(j*100+5, i*100+105, 90, 90, Color{10, 30, 20, 100});
		}
	}
}

void drawColoredSquares()
{
	for (int i{}; i < data.guessedWords.size(); ++i)
	{
		for (int j{}; j < data.guessedWords[i].size(); ++j)
		{
			DrawRectangle(j*100+5, i*100+105, 90, 90, letterState(data.guessedWords[i][j], j, data.guessedWords[i]));
		}
	}
}

void drawGuessedWords()
{
	for (int i{}; i < data.guessedWords.size(); ++i)
	{
		for (int j{}; j < data.guessedWords[i].size(); ++j)
		{
			DrawTextEx(data.base.fs.get("res/Roboto.ttf", false), data.guessedWords[i].substr(j, 1).c_str(), {20 + 100*j, 100 + 100*i}, 100, 0, BLACK);
		}
	}
}

void drawWin()
{
	DrawRectangle(250 - 170, 400 - 50, 340, 100, DARKGREEN);
	DrawTextEx(data.base.fs.get("res/Roboto.ttf", false), "You Won!", {250 - 160, 400 - 40}, 90, 0, WHITE);
}

void drawLoss()
{
	DrawRectangle(250 - 170, 400 - 50, 340, 100, MAROON);
	DrawTextEx(data.base.fs.get("res/Roboto.ttf", false), "You Lost!", {250 - 160, 400 - 40}, 90, 0, WHITE);
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
	if (data.guessedWords.size() == 6) drawLoss();
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
	InitWindow(500, 800, "Obserdle");
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