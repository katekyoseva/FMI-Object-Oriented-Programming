#pragma once
#include "Game.h"

class GamePlatform
{
public:
    GamePlatform();

    void addGame(const Game& game);
    void printGame(unsigned index) const;
    void printAll() const;

    void cheapest() const;
    void mostExpensive() const;
    void printFree() const;

    void remove(unsigned index);

    void saveText(const char* file);
    void loadText(const char* file);

    void saveTextToBinary(const char* file);
    void loadTextFromBinary(const char* file);

private:
    Game games[32];
    unsigned count;
};