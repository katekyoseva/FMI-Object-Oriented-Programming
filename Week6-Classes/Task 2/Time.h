#pragma once

class Time
{
public:
    Time();

    unsigned getHours() const;
    unsigned getMinutes() const;
    unsigned getSeconds() const;

    void setHours(unsigned hours);
    void setMinutes(unsigned minutes);
    void setSeconds(unsigned seconds);

    void print() const;

    void nextSecond();
    void nextMinute();
    void nextHour();

    bool isNight() const;

private:
    unsigned hours;
    unsigned minutes;
    unsigned seconds;
};

