#include <iostream>
#include <fstream>
//#include <cstring>

const int MAX_SIZE = 1024;
const int MAX_NAME_SIZE = 32;

// Task 2
int getWordCount(const char* fileName)
{
	int counter = 0;

	std::ifstream ifs(fileName);
	if (!ifs.is_open())
	{
		std::cout << "Couldn't open input file: " << fileName;
		return -1;
	}

	char word[MAX_SIZE];

	while (ifs >> word)
	{
		counter++;
	}

	ifs.close();

	return counter;
}
// Task 3
int getLineCount(const char* fileName)
{
	std::ifstream ifs(fileName);
	if (!ifs.is_open())
	{
		std::cout << "Couldn't open input file: " << fileName;
		return -1;
	}

	int counter = 0;
	char buffer[MAX_SIZE];

	while (ifs.getline(buffer, MAX_SIZE))
	{
		counter++;
	}

	ifs.close();

	return counter;
}

// Task 4
struct Student
{
	char name[MAX_NAME_SIZE] {};
	unsigned year = 0;
	float grade = 0;
};

void readStudent(std::istream& is, Student& student)
{
	is >> student.name >> student.year >> student.grade;
}

void printStudent(const Student& student)
{
	std::cout << "Name: " << student.name << '\n';
	std::cout << "Year: " << student.year << '\n';
	std::cout << "Grade: " << student.grade << "\n\n";
}

void readFromFile(const char* fileName, Student* students, int count)
{
	std::ifstream ifs(fileName);

	if (!ifs.is_open())
	{
		std::cout << "Couldn't open input file: " << fileName;
		return;
	}

	for (int i = 0; i < count; i++)
	{
		readStudent(ifs, students[i]);
	}

	ifs.close();
}

// dynamic
void writeToFile(const char* fileName, Student* students, int n)
{
	std::ofstream ofs(fileName);

	if (!ofs.is_open())
	{
		std::cout << "Couldn't open output file: " << fileName;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		ofs << students[i].name << " " << students[i].year << " " << students[i].grade << '\n';
	}

	ofs.close();
}

Student* readFromFile(const char* fileName, unsigned& n)
{
	std::ifstream ifs(fileName);

	if (!ifs.is_open())
	{
		std::cout << "Couldn't open input file: " << fileName;
		return nullptr;
	}

	//ifs >> n;

	Student* students = new (std::nothrow) Student[n];

	if (!students)
	{
		return nullptr;
	}

	for (int i = 0; i < n; i++)
	{
		readStudent(ifs, students[i]);
	}

	ifs.close();
	return students;
}

// Task 5
bool areEqualStr(const char* a, const char* b)
{
	int i = 0;

	while (a[i] != '\0' && b[i] != '\0')
	{
		if (a[i] != b[i])
		{
			return false;
		}

		i++;
	}

	return a[i] == b[i];
}

int getSpecificWordCount(const char* word, const char* fileName)
{
	std::ifstream ifs(fileName);
	if (!ifs.is_open())
	{
		std::cout << "Couldn't open input file: " << fileName;
		return -1;
	}

	char currentWord[MAX_SIZE];
	int count = 0;

	while (ifs >> currentWord)
	{
		//if (strcmp(currentWord, word) == 0)
		if(areEqualStr(currentWord, word))
		{
			count++;
		}
	}

	ifs.close();
	return count;
}

// Task 6
void replace(const char* fileName, const char* newFileName, const char* find, const char* replacement)
{
	std::ifstream ifs(fileName);
	std::ofstream ofs(newFileName);

	if (!ifs.is_open())
	{
		std::cout << "Couldn't open input file: " << fileName;
		return;
	}

	if (!ofs.is_open())
	{
		std::cout << "Couldn't open output file: " << newFileName;
		return;
	}

	char word[MAX_SIZE];

	while (ifs >> word)
	{
		//if (strcmp(word, find) == 0)
		if (areEqualStr(word, find))
		{
			ofs << replacement << " ";
		}
		else
		{
			ofs << word << " ";
		}
	}

	ifs.close();
	ofs.close();

	//std::cout << "Replacing Word finished successfully!";
}

// Task 7
void compareFiles(const char* file1, const char* file2)
{
	std::ifstream if1(file1);
	std::ifstream if2(file2);

	if (!if1.is_open())
	{
		std::cout << "Couldn't open input file: " << file1;
		return;
	}

	if (!if2.is_open())
	{
		std::cout << "Couldn't open input file: " << file2;
		return;
	}

	char line1[MAX_SIZE];
	char line2[MAX_SIZE];
	int line = 1;

	while (true)
	{
		if1.getline(line1, MAX_SIZE);
		if2.getline(line2, MAX_SIZE);

		//if (strcmp(line1, line2) != 0)
		if(!areEqualStr(line1, line2))
		{
			std::cout << "Mismatch on line " << line << ":\n";
			std::cout << line1 << '\n';
			std::cout << line2 << '\n';
			return;
		}

		if (if1.eof() && if2.eof())
			break;

		line++;
	}

	std::cout << "Files are identical.\n";
}
// Task 8
void replaceChar(const char* fileName, const char* newFileName, char find, char replace)
{
	std::ifstream ifs(fileName);
	std::ofstream ofs(newFileName);

	if (!ifs.is_open())
	{
		std::cout << "Couldn't open input file: " << fileName;
		return;
	}

	if (!ofs.is_open())
	{
		std::cout << "Couldn't open output file: " << newFileName;
		return;
	}

	char ch;

	while (ifs.get(ch))
	{
		if (ch == find)
		{
			ofs.put(replace);
		}
		else
		{
			ofs.put(ch);
		}
	}

	ifs.close();
	ofs.close();
	//std::cout << "Replacing Char finished successfully!";
}

// Task 9
void concatFiles(const char* files[], unsigned count, const char* newFileName)
{
	std::ofstream ofs(newFileName);

	if (!ofs.is_open())
	{
		std::cout << "Couldn't open output file: " << newFileName;
		return;
	}

	for (unsigned i = 0; i < count; i++)
	{
		std::ifstream ifs(files[i]);

		if (!ifs.is_open())
		{
			std::cout << "Couldn't open input file: " << files[i] << '\n';
			continue;
		}

		char ch;
		while (ifs.get(ch))
		{
			ofs.put(ch);
		}
		ofs << '\n';
		ifs.close();
	}

	ofs.close();
	//std::cout << "Concatenating Files finished successfully!";
}

void concatFileNames(const char* files[], unsigned count, const char* newFileName)
{
	std::ofstream ofs(newFileName);

	if (!ofs.is_open())
	{
		std::cout << "Couldn't open output file: " << newFileName;
		return;
	}

	for (unsigned i = 0; i < count; i++)
	{
		ofs << files[i];
	}

	ofs.close();
	//std::cout << "Concatenating File Names finished successfully!";
}
// Task 10
char toLower(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
	{
		return ch + ('a' - 'A');
	}
	return ch;
}

bool containsWord(const char* line, const char* word)
{
	int i = 0;
	while (line[i] != '\0')
	{
		int j = 0;
		while (word[j] != '\0' && line[i + j] != '\0' && toLower(line[i + j]) == toLower(word[j]))
		{
			j++;
		}
		if (word[j] == '\0')
			return true;
		i++;
	}
	return false;
}

void grep(const char* fileName, const char* word)
{
	std::ifstream ifs(fileName);

	if (!ifs.is_open())
	{
		std::cout << "Couldn't open input file: " << fileName;
		return;
	}

	char line[MAX_SIZE];
	int lineNumber = 1;

	while (ifs.getline(line, MAX_SIZE))
	{
		if (containsWord(line, word))
		{
			std::cout << lineNumber << ": " << line << std::endl;
		}

		lineNumber++;
	}

	ifs.close();
}

int main()
{
	//Task 1
	/*std::ifstream ifs("Solutions.cpp");
	if (!ifs.is_open())
	{
		std::cout << "Error...";
		return -1;
	}

	while (!ifs.eof())
	{
		char buffer[100];
		ifs.getline(buffer, 100);
		std::cout << buffer << '\n';
	}

	if (!ifs.good())
	{
		std::cout << "Error...";
		return -1;
	}

	ifs.close();*/

	//Task 2
	//char fileName[] = "Test.txt";
	//std::cout << getWordCount(fileName);

	//Task 3
	//char fileName[] = "Solutions.cpp";
	//std::cout << getLineCount(fileName);

	//Task 4
	//Student s1 = { "Ivan", 1, 3.50 };
	//Student s2 = { "Maria", 2, 4.80 };
	//Student s3 = { "Georgi", 3, 5.60 };

	//char studentsFile[] = "students.txt";

	//std::ofstream ofs(studentsFile);

	//ofs << s1.name << " " << s1.year << " " << s1.grade << '\n';
	//ofs << s2.name << " " << s2.year << " " << s2.grade << '\n';
	//ofs << s3.name << " " << s3.year << " " << s3.grade << '\n';

	//ofs.close();

	//Student students[3];

	//readFromFile(studentsFile, students, 3);

	//for (int i = 0; i < 3; i++)
	//{
	//	printStudent(students[i]);
	//}
	
	// dynamic
	//int n;
	//std::cout << "Enter number of students you want to add: ";
	//std::cin >> n;

	//Student* students = new (std::nothrow) Student[n];

	// if(!students)
	// return -1;

	//char studentsFile[] = "students2.txt";

	//for (int i = 0; i < n; i++)
	//{
	//	std::cout << "Student No: " << i + 1 << ": ";
	//	readStudent(std::cin, students[i]);
	//}

	//writeToFile(studentsFile, students, n);
	//delete[] students;

	//unsigned count;
	//std::cout << '\n' << "How many student entries do you want to see? (0 - " << n << " )\n";
	//std::cin >> count;
	//if (count > n)
	//	std::cout << "Invalid number! Please enter a number between 0 and " << n << '\n';

	//Student* fromFile = readFromFile(studentsFile, count);

	//for (int i = 0; i < count; i++)
	//{
	//	printStudent(fromFile[i]);
	//}

	//delete[] fromFile;

	// Task 5
	//std::cout << getSpecificWordCount("cat", "text.txt");

	// Task 6
	//replace("sometext.txt", "somecooltext.txt", "geometriq", "OOP");

	// Task 7
	//compareFiles("file1.txt", "file2.txt");
	//compareFiles("file1.txt", "file1.txt");

	//Task 8
	//replaceChar("text1.txt", "newText.txt", 'a', 'x');

	// Task 9
	//const char* files[] = { "file1.txt", "file2.txt", "file3.txt" };
	//concatFiles(files, 3, "result.txt");
	//concatFileNames(files, 3, "allFileNames.txt");
	
	// Task 10
	//grep("file.txt", "program");
}