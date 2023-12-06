#ifndef WORDINPUT
#define WORDINPUT
#include "basedata.h"
#include <string>

class WordInput : public Ob
{
private:
    BaseData* base;
    int cursorPos{0}; // 0-4
    std::string currentWord{};

    int currentLine{0}; // if they get to 6 then they lose

    bool submit{false};

    bool won{false};
public:
    void init(BaseData* b);
    void update() override;
    void draw() override;

    bool isSubmitting() { return submit; }
    std::string getWord() { return currentWord; }

    void win() { won=true; }
};

#endif