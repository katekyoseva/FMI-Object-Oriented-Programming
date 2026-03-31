#include "GamePlatform.h"
#include <iostream>
#include <fstream>

GamePlatform::GamePlatform()
{
	count = 0;
}

void GamePlatform::addGame(const Game& game)
{
	if (count >= 32)
	{
		std::cout << "Full game platform, cannot add game!";
		return;
	}
	games[count++] = game;
}

void GamePlatform::printGame(unsigned index) const
{
	if (index < count)
		games[index].print();
	else
		std::cout << "Invalid index or no game under that index!";
}

void GamePlatform::printAll() const
{
	for (unsigned i = 0; i < count; i++)
		games[i].print();
}

void GamePlatform::cheapest() const
{
	if (count == 0) 
		return;

	int index = 0;
	for (unsigned i = 1; i < count; i++)
		if (games[i].getPrice() < games[index].getPrice())
			index = i;

	games[index].print();
}

void GamePlatform::mostExpensive() const
{
	if (count == 0) 
		return;

	int index = 0;
	for (unsigned i = 1; i < count; i++)
		if (games[i].getPrice() > games[index].getPrice())
			index = i;

	games[index].print();
}

void GamePlatform::printFree() const
{
	for (unsigned i = 0; i < count; i++)
		if (games[i].isFree())
			games[i].print();
}

void GamePlatform::remove(unsigned index)
{
	if (index >= count)
	{
		std::cout << "Invalid index or no game under that index!";
		return;
	}

	for (unsigned i = index; i < count - 1; i++)
		games[i] = games[i + 1];

	games[count - 1] = Game();
	count--;
}

void GamePlatform::saveText(const char* file)
{
	std::ofstream ofs(file);
	if (!ofs.is_open())
	{
		std::cout << "Cannot open " << file << " for writing\n";
		return;
	}

	ofs << count << '\n';

	for (unsigned i = 0; i < count; i++)
		ofs << games[i].getTitle() << " "
		<< games[i].getPrice() << " "
		<< games[i].getAvailability() << '\n';
	
	ofs.close();
}

void GamePlatform::loadText(const char* file)
{
	std::ifstream ifs(file);
	if (!ifs.is_open())
	{
		std::cout << "Cannot open " << file << " for reading\n";
		return;
	}

	ifs >> count;

	for (unsigned i = 0; i < count; i++)
	{
		char title[65];
		double price;
		bool available;

		ifs >> title >> price >> available;

		games[i].setTitle(title);
		games[i].setPrice(price);
		games[i].setAvailability(available);
	}

	ifs.close();
}

void GamePlatform::saveTextToBinary(const char* file)
{
	std::ofstream ofs(file, std::ios::binary);
	if (!ofs.is_open())
	{
		std::cout << "Cannot open " << file << " for writing\n";
		return;
	}

	ofs.write(reinterpret_cast<char*>(&count), sizeof(count));

	for (unsigned i = 0; i < count; i++)
		ofs.write(reinterpret_cast<char*>(&games[i]), sizeof(Game));

	ofs.close();
}

void GamePlatform::loadTextFromBinary(const char* file)
{
	std::ifstream ifs(file, std::ios::binary);

	if (!ifs.is_open())
	{
		std::cout << "Cannot open " << file << " for reading\n";
		return;
	}

	unsigned gamesCount;
	ifs.read(reinterpret_cast<char*>(&gamesCount), sizeof(gamesCount));
	if (gamesCount > 32) 
		gamesCount = 32;

	for (unsigned i = 0; i < gamesCount; i++)
		ifs.read(reinterpret_cast<char*>(&games[i]), sizeof(Game));

	count = gamesCount;

	for (unsigned i = count; i < 32; i++)
		games[i] = Game();

	ifs.close();
}