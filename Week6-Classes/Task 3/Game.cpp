#include "Game.h"
#include <iostream>
#include <cstring>

Game::Game()
{
	strcpy_s(title, "Unknown");
	price = 0;
	isAvailable = false;
}

const char* Game::getTitle() const
{
	return title;
}

double Game::getPrice() const
{
	return price;
}

bool Game::getAvailability() const
{
	return isAvailable;
}

void Game::setTitle(const char* title)
{
	if (!title || strlen(title) == 0)
	{
		std::cout << "Invalid title";
		return;
	}

	strncpy_s(this->title, title, 64);
	this->title[64] = '\0';
}

void Game::setPrice(double price)
{
	if (price < 0)
	{
		std::cout << "Invalid price";
		return;
	}

	this->price = price;
}

void Game::setAvailability(bool available)
{
	isAvailable = available;
}

void Game::print() const
{
	std::cout << "Title: " << title << '\n' 
		<< "Price: " << price << '\n' 
		<< "The game is available: " << std::boolalpha << isAvailable << '\n';
}

bool Game::isFree() const
{
	return price == 0;
}
