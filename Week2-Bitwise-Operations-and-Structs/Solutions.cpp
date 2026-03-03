#include <iostream>
const unsigned MAX_YEAR = 4095;

// Task 1
bool isEven(int num)
{
	return !(num & 1);
	//return !(num | 0)
}

//Task 2
void setBit(unsigned char& num, unsigned short bitPos)
{
	 num = num | (1 << bitPos);
}

void clearBit(unsigned char& num, unsigned short bitPos)
{
	num = num & ~(1 << bitPos);
}

void flipBit(unsigned char& num, unsigned short bitPos)
{
	num = num ^ (1 << bitPos);
}

bool checkBit(unsigned char num, unsigned short bitPos)
{
	 return num & (1 << bitPos);
}
// Task 3
bool isPowerOf2(unsigned num)
{
	if (num == 0) 
		return false;

	while (num != 1)
	{
		if (num & 1) 
			return false;
		num = num >> 1;
	}
	return true;
}

// Task 4
struct ComplexNumber
{
	double realPart;
	double imaginaryPart;
};

ComplexNumber initialize(const double realPart, const double imPart)
{
	ComplexNumber num{ realPart, imPart };
	return num;
}

void printComplex(const ComplexNumber& num)
{
	std::cout << '(' << num.realPart << " + " << num.imaginaryPart << "i)" << '\n';
}

ComplexNumber sumComplex(const ComplexNumber& num1, const ComplexNumber& num2)
{
	ComplexNumber result = { num1.realPart + num2.realPart, num1.imaginaryPart + num2.imaginaryPart };
	return result;
}
double mod(const ComplexNumber& num)
{
	return sqrt(num.realPart * num.realPart + num.imaginaryPart * num.imaginaryPart);
}

ComplexNumber prodComplexNums(const ComplexNumber& num1, const ComplexNumber& num2)
{
	ComplexNumber prod = {
		num1.realPart* num2.realPart - num1.imaginaryPart * num2.imaginaryPart,
		num1.realPart* num2.imaginaryPart + num1.imaginaryPart * num2.realPart
	};
	return prod;
}

// Task 5
enum class Major
{
	UNKNOWN_MAJOR = -1,

	SOFTWARE_ENGENEERING,
	COMPUTER_SCIENCE,
	INFORMATION_SYSTEMS,
	INFORMATICS,
	APPLIED_MATHEMATICS,
	MATHEMATICS,
	STATISTICS,
	DATA_SCIENCE,
	MATHEMATICS_AND_INFORMATICS_TEACHING,

	COUNT_MAJORS
};

const char* majorToText(Major major)
{
	switch (major)
	{
	case Major::UNKNOWN_MAJOR:
		return "Unknown";
	case Major::SOFTWARE_ENGENEERING:
		return "Software Engineering";
	case Major::COMPUTER_SCIENCE:
		return "Computer Science";
	case Major::INFORMATION_SYSTEMS:
		return "Information Systems";
	case Major::INFORMATICS:
		return "Informatics";
	case Major::APPLIED_MATHEMATICS:
		return "Applied Mathematics";
	case Major::MATHEMATICS:
		return "Mathematics";
	case Major::STATISTICS:
		return "Statistics";
	case Major::DATA_SCIENCE:
		return "Data Science";
	case Major::MATHEMATICS_AND_INFORMATICS_TEACHING:
		return "Mathematics and Informatics Teaching";
	default:
		return "Invalid";
	}
}

struct Student
{
	char name[32]{};
	double avrGrade = 0;
	unsigned int year = 0;
	Major major = Major::UNKNOWN_MAJOR;
};

bool isValidMajor(int value)
{
	return value >= 0 && value < (int)Major::COUNT_MAJORS;
}

void readStudent(Student& student)
{
	int majorInput;

	std::cin >> student.name >> student.year >> majorInput >> student.avrGrade;

	student.major = isValidMajor(majorInput) ? (Major) majorInput : Major::UNKNOWN_MAJOR;
}

void printStudent(const Student& s)
{
	std::cout << "Name: " << s.name << std::endl;
	std::cout << "Year: " << s.year << std::endl;
	std::cout << "Major: " << majorToText(s.major) << std::endl;
	std::cout << "Grade: " << s.avrGrade << std::endl;
	std::cout << std::endl;
}

float getAvgGrade(const Student students[], int studentCount)
{
	double sum = 0;
	for (int i = 0; i < studentCount; i++)
	{
		sum += students[i].avrGrade;
	}
	return sum / studentCount;
}

//Task 6
struct Date
{
	unsigned day : 5;
	unsigned month : 4;
	unsigned year : 12; 
};
bool isLeapYear(unsigned year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

unsigned daysInMonth(unsigned month, unsigned year)
{
	switch (month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31;
	case 4: case 6: case 9: case 11:
		return 30;
	case 2:
		return isLeapYear(year) ? 29 : 28;
	default:
		return 0;
	}
}

bool isValidDate(unsigned day, unsigned month, unsigned year)
{
	if (month < 1 || month > 12 || year > MAX_YEAR)
		return false;

	unsigned maxDays = daysInMonth(month, year);
	return day >= 1 && day <= maxDays;
}

void readDate(Date& d)
{
	unsigned day, month, year;

	do
	{
		std::cout << "Enter date (day month year): ";
		std::cin >> day >> month >> year;

		if (!isValidDate(day, month, year))
			std::cout << "Invalid date! Please try again.\n";

	} while (!isValidDate(day, month, year));

	d.day = day;
	d.month = month;
	d.year = year;
}

void printDate(const Date& d)
{
	if (d.day < 10)
		std::cout << '0' << d.day << ".";
	else
		std::cout << d.day << ".";
	if (d.month < 10)
		std::cout << '0' << d.month << ".";
	else
		std::cout << d.month << ".";
	std::cout << d.year;
}

// Task 7
unsigned stringLength(const char* str)
{
	unsigned length = 0;
	for (unsigned i = 0; str[i] != '\0'; i++)
	{
		length++;
	}
	return length;
}

void stringCopy(char* destination, const char* source)
{
	int i;
	for (i = 0; source[i] != '\0'; i++)
	{
		destination[i] = source[i];
	}
	destination[i] = '\0';
}

enum class Genre
{
	UNKNOWN_GENRE = -1,

	ACTION,
	RPG,
	STRATEGY,
	SPORTS,
	ADVENTURE,
	HORROR,

	COUNT_GENRES
};

const char* genreToText(Genre game)
{
	switch (game)
	{
	case Genre::ACTION: 
		return "Action";
	case Genre::RPG: 
		return "RPG";
	case Genre::STRATEGY: 
		return "Strategy";
	case Genre::SPORTS: 
		return "Sports";
	case Genre::ADVENTURE: 
		return "Adventure";
	case Genre::HORROR: 
		return "Horror";
	default: 
		return "Unknown";
	}
}

struct Game
{
	char* name{};
	double price = 0;
	Date releaseDate = {1, 1, 1};
	unsigned ageRating = 0;
	Genre genre = Genre::UNKNOWN_GENRE;
};

void readGame(Game& game)
{
	std::cin.ignore();
	char buffer[256];
	std::cout << "Enter game name: ";
	std::cin.getline(buffer, 256);

	int length = stringLength(buffer);

	game.name = new char[length + 1];
	stringCopy(game.name, buffer);

	std::cout << "Enter release date:\n";
	readDate(game.releaseDate);

	std::cout << "Enter age rating: ";
	std::cin >> game.ageRating;

	int genreInput;
	std::cout << "Enter genre (0-Action,1-RPG,2-Strategy,3-Sports,4-Adventure,5-Horror): ";
	std::cin >> genreInput;
	if (genreInput >= 0 && genreInput <= (int)Genre::COUNT_GENRES)
		game.genre = (Genre) genreInput;

	std::cout << "Enter price: ";
	std::cin >> game.price;
}

void printGame(const Game& game)
{
	std::cout << "Name: " << game.name << "\n";
	std::cout << "Release date: "; printDate(game.releaseDate); std::cout << "\n";
	std::cout << "Age rating: " << game.ageRating << "\n";
	std::cout << "Genre: " << genreToText(game.genre) << "\n";
	std::cout << "Price: " << game.price << "\n";
}

void freeGame(Game& game)
{
	delete[] game.name;
	game.name = nullptr;
}
// Bonus task
void printMostExpensive(const Game* games, int N)
{
	if (N == 0) 
		return;

	int index = 0;
	for (int i = 1; i < N; i++)
		if (games[index].price < games[i].price)
			index = i;

	std::cout << "\nMost expensive game:\n";
	printGame(games[index]);
}

void printAdultsOnly(const Game* games, int N)
{
	std::cout << "\nGames for 18+:\n";
	for (int i = 0; i < N; i++)
	{
		if (games[i].ageRating >= 18)
			printGame(games[i]);
	}
}

void printByYear(const Game* games, int N, unsigned year)
{
	std::cout << "\nGames released in " << year << ":\n";
	for (int i = 0; i < N; i++)
		if (games[i].releaseDate.year == year)
			printGame(games[i]);
}

void printByGenre(const Game* games, int N, Genre genre)
{
	std::cout << "\nGames of genre " << genreToText(genre) << ":\n";
	for (int i = 0; i < N; i++)
		if (games[i].genre == genre)
			printGame(games[i]);
}

int main()
{
	// Task 1
	/*std::cout << isEven(3) << '\n';
	std::cout << isEven(8);*/

	//Task 2
	/*unsigned char num = 0;
	unsigned short bit = 2;*/

	/*unsigned char num = 3;
	unsigned short bit = 1;*/

	/*unsigned char num = 5;
	unsigned short bit = 2;*/

	/*unsigned char num = 5;
	unsigned short bit = 1;*/

	//setBit(num, bit);
	//clearBit(num, bit);
	//flipBit(num, bit);

	/*std::cout << (int)num << '\n';
	std::cout << checkBit(num, bit);*/

	//Task 3
	/*std::cout << std::boolalpha << isPowerOf2(2) << '\n';
	std::cout << isPowerOf2(11);*/

	//Task 4
	/*ComplexNumber num = initialize(1.2, 2.4);
	ComplexNumber num2 = initialize(1.2, 2.4);
	printComplex(num);
	
	ComplexNumber sum = sumComplex(num, num2);
	printComplex(sum);
	std::cout << mod(num) <<'\n';
	ComplexNumber product = prodComplexNums(num, num2);
	printComplex(product);*/

	//Task 5
	/*const int SIZE = 3;
	Student students[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		readStudent(students[i]);
	}

	for (int i = 0; i < SIZE; i++)
	{
		printStudent(students[i]);
	}

	std::cout << "Average grade: " << getAvgGrade(students, SIZE);*/

	//Task 6
	/*Date date;
	readDate(date);
	printDate(date);*/

	//Task 7
	/*Game game;
	readGame(game);
	printGame(game);
	freeGame(game);*/

	//Bonus Task
	/*int N;
	std::cout << "Enter number of games: ";
	std::cin >> N;

	Game* games = new Game[N];

	for (int i = 0; i < N; i++)
	{
		std::cout << "\nGame " << i + 1 << ":\n";
		readGame(games[i]);
	}

	printMostExpensive(games, N);
	printAdultsOnly(games, N);

	unsigned year;
	std::cout << "\nEnter year to filter: ";
	std::cin >> year;
	printByYear(games, N, year);

	int genreInput;
	std::cout << "\nEnter genre to filter (0-Action,1-RPG,2-Strategy,3-Sports,4-Adventure,5-Horror): ";
	std::cin >> genreInput;
	Genre g;
	if (genreInput >= 0 && genreInput <= (int)Genre::COUNT_GENRES)
		g = (Genre)genreInput;
	else
		g = Genre::UNKNOWN_GENRE;
	printByGenre(games, N, g);

	for (int i = 0; i < N; i++)
		freeGame(games[i]);

	delete[] games;*/
}
