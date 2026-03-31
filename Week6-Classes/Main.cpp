#include <iostream>
#include "Student.h"
#include "Date.h"
#include "Time.h"
#include "Game.h"
#include "GamePlatform.h"

int main()
{
	// Task 1
    /*Student s;

    s.setName("Ivan");
    s.setYear(2004);
    s.setGrade(5.50);

    s.printStudent();

    std::cout << "Name: " << s.getName() << std::endl;
    std::cout << "Year: " << s.getYear() << std::endl;
    std::cout << "Grade: " << s.getGrade() << std::endl;

    if (s.canGetScholarship(5.00))
        std::cout << "Gets scholarship\n";
    else
        std::cout << "No scholarship\n";

    std::cout << "Year in uni: " << s.getYearInUni(2026) << std::endl;
	*/

	// Task 2
    /*Date d;

    d.setDay(31);
    d.setMonth(12);
    d.setYear(2025);

    std::cout << "Initial date: ";
    d.print();

    d.nextDay();
    std::cout << "Next day: ";
    d.print();

    d.nextMonth();
    std::cout << "Next month: ";
    d.print();

    d.nextYear();
    std::cout << "Next year: ";
    d.print();

    if (d.isDuringSummer())
        std::cout << "Summer\n";
    else
        std::cout << "Not summer\n";

    Time t;

    t.setHours(23);
    t.setMinutes(59);
    t.setSeconds(58);

    std::cout << "\nInitial time: ";
    t.print();

    t.nextSecond();
    t.print();

    t.nextSecond();
    t.print();

    t.nextHour();
    t.print();

    if (t.isNight())
        std::cout << "Night\n";
    else
        std::cout << "Day\n";
    */

    // Task 3
    Game g1, g2, g3;

    g1.setTitle("CS2");
    g1.setPrice(0);
    g1.setAvailability(true);

    g2.setTitle("FIFA");
    g2.setPrice(120);
    g2.setAvailability(true);

    g3.setTitle("Minecraft");
    g3.setPrice(60);
    g3.setAvailability(false);

    GamePlatform gp;

    gp.addGame(g1);
    gp.addGame(g2);
    gp.addGame(g3);

    std::cout << "All games in platform:\n";
    gp.printAll();

    std::cout << "\nCheapest game:\n";
    gp.cheapest();

    std::cout << "\nMost expensive game:\n";
    gp.mostExpensive();

    std::cout << "\nFree games:\n";
    gp.printFree();

    std::cout << "\nRemoving game at index 1:\n";
    gp.remove(1);
    gp.printAll();

    std::cout << "\nSaving platform to text file 'gamesT.txt'...\n";
    gp.saveText("gamesT.txt");

    GamePlatform gpText;
    std::cout << "\nLoading platform from text file 'gamesT.txt'...\n";
    gpText.loadText("gamesT.txt");

    std::cout << "\nGames loaded from text file:\n";
    gpText.printAll();

    std::cout << "\nSaving platform to binary 'gamesB.bin'...\n";
    gp.saveTextToBinary("gamesB.bin");

    GamePlatform gp2;
    std::cout << "\nLoading platform from binary 'gamesB.bin'...\n";
    gp2.loadTextFromBinary("gamesB.bin");

    std::cout << "\nGames loaded from binary:\n";
    gp2.printAll();

    return 0;
}

