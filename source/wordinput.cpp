#include "wordinput.h"

std::string wordleGetKeysPressed(std::string whiteList)
{
    for (char& c : whiteList)
    {
        if (IsKeyPressed(c))
            return std::string{c};
    }
    return std::string{};
}

void WordInput::init(BaseData* b)
{
    base = b;
}

void WordInput::update()
{
    if (submit) // cleanup after it has submitted
    {
        submit = false;
        cursorPos = 0;
        currentWord = "";
        currentLine += 1;
    }

    if (!won)
    {
        std::string charPressed{wordleGetKeysPressed("QWERTYUIOPASDFGHJKLZXCVBNM")};
        if (charPressed != "" && cursorPos < 5) // type letter
        {
            currentWord.push_back(charPressed[0]);
            ++cursorPos;
        }
        if (IsKeyPressed(KEY_BACKSPACE) && cursorPos > 0) // backspace
        {
            currentWord.pop_back();
            --cursorPos;
        }
        if (IsKeyPressed(KEY_ENTER) && cursorPos == 5) // submit word
        {
            submit = true;
        }
    }
}

void WordInput::draw()
{
    if (!won)
    {
        int yPos{100};
        for (int i{}; i < currentLine; ++i)
        {
            yPos += 100;
        }

        for (int i{}; i < currentWord.size(); ++i)
        {
            DrawTextEx(base->fs.get("res/Roboto.ttf", false), currentWord.substr(i, 1).c_str(), {20 + 100*i, yPos}, 100, 0, BLACK);
        }
    }
}