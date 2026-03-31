#pragma once

class Game
{
public:
    Game();

    const char* getTitle() const;
    double getPrice() const;
    bool getAvailability() const;

    void setTitle(const char* title);
    void setPrice(double price);
    void setAvailability(bool isAvailable);

    void print() const;
    bool isFree() const;

private:
    char title[65];
    double price;
    bool isAvailable;
};