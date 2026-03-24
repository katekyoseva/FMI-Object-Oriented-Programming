#include <iostream>
#include <fstream>
#include <cstring>

const unsigned MAX_NAME = 32;
const unsigned MAX_SIZE = 256;

//Task 3
void stringCopy(char* destination, const char* source)
{
    int i;
    for (i = 0; source[i] != '\0'; i++)
    {
        destination[i] = source[i];
    }
    destination[i] = '\0';
}

struct Student
{
    //char name[MAX_NAME] {};
    char* name;             // bonus task - dynamic name
    unsigned year = 0;
    float grade = 0;
};

void createStudent(Student& student)
{
    char temp[MAX_NAME];
    std::cin.ignore();
    std::cin.getline(temp, MAX_NAME);
    stringCopy(student.name, temp);

    std::cin >> student.year;
    std::cin >> student.grade;
}

void writeStudentsToFile(const char* fileName, Student* students, int size)
{
    std::ofstream ofs(fileName, std::ios::binary);
    if (!ofs.is_open())
    {
        std::cout << "Cannot open file: " << fileName << std::endl;
        return;
    }

    ofs.write((char*)&size, sizeof(size));

    for (int i = 0; i < size; i++)
    {
        ofs.write((char*)&students[i], sizeof(Student));
    }

    ofs.close();
}

void readStudentsFromFile(const char* fileName, Student* students, int& size)
{
    std::ifstream ifs(fileName, std::ios::binary);
    if (!ifs)
    {
        std::cout << "Cannot open file: " << fileName << std::endl;
        size = 0;
        return;
    }

    ifs.read((char*)&size, sizeof(size));
    ifs.read((char*)students, size * sizeof(Student));

    ifs.close();
}

void printStudents(Student arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i].name << " "
            << arr[i].year << " "
            << arr[i].grade << "\n";
    }
}

// Bonus 
void createStudentDynamic(Student& student)
{
    char buffer[MAX_SIZE]{};
    std::cin.ignore();
    std::cin.getline(buffer, MAX_SIZE);
    char* name = new (std::nothrow) char[strlen(buffer) + 1] {};

    if (!name)
        return;
    stringCopy(name, buffer);
    student.name = name;

    std::cin >> student.year;
    std::cin >> student.grade;
}

void writeStudentsToFileDynamic(const char* fileName, Student* students, int size)
{
    std::ofstream ofs(fileName, std::ios::binary);
    if (!ofs.is_open())
    {
        std::cout << "Cannot open file: " << fileName << std::endl;
        return;
    }

    ofs.write((char*)&size, sizeof(size));

    for (int i = 0; i < size; i++) 
    {
        int nameLen = strlen(students[i].name) + 1;
        ofs.write((char*)&nameLen, sizeof(int));
        ofs.write(students[i].name, nameLen);

        ofs.write((char*)&students[i].year, sizeof(unsigned));
        ofs.write((char*)&students[i].grade, sizeof(float));
    }
    ofs.close();
}

void readStudentsFromFileDynamic(const char* fileName, Student* students, int& size)
{
    std::ifstream ifs(fileName, std::ios::binary);
    if (!ifs)
    {
        std::cout << "Cannot open file: " << fileName << std::endl;
        size = 0;
        return;
    }

    ifs.read((char*)&size, sizeof(size));

    for (int i = 0; i < size; i++) 
    {
        int nameLen;
        ifs.read((char*)&nameLen, sizeof(int));

        students[i].name = new char[nameLen];
        ifs.read(students[i].name, nameLen);

        ifs.read((char*)&students[i].year, sizeof(unsigned));
        ifs.read((char*)&students[i].grade, sizeof(float));
    }
    ifs.close();
}

// Task 4
int* arr = nullptr;
int size = 0;

int getSum(const unsigned i, const unsigned j)
{
    if (i >= size || j >= size) {
        std::cout << "Invalid indices!" << std::endl;
        return 0;
    }
    return arr[i] + arr[j];
}

int main()
{
    // Task 1
    /*int n;
    std::cin >> n;
    
    int* arr = new (std::nothrow) int[n];

    if (!arr)
        return -1;

    for (size_t i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    char fileName[] = "numbers.dat";
    std::ofstream ofs(fileName, std::ios::binary);

    if (!ofs.is_open())
    {
        std::cout << "Cannot open file: " << fileName << std::endl;
        return 0;
    }

    ofs.write((const char*)&n, sizeof(n));

    ofs.write((const char*)arr, n * sizeof(int));

    ofs.close();
    delete[] arr;
    */

    //Task 2
    /*char fileName[] = "numbers.dat";
    std::ifstream ifs(fileName, std::ios::binary);

    if (!ifs.is_open())
    {
        std::cout << "Cannot open file: " << fileName << std::endl;
        return 0;
    }

    int size;

    ifs.read((char*)&size, sizeof(size));

    int* arr = new (std::nothrow) int[size];
    if (!arr)
        return -1;

    ifs.read((char*)arr, size * sizeof(int));

    ifs.close();

    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ' ';
    }

    delete[] arr;
    */

    // Task 3
    /*int n;
    std::cin >> n;

    Student* studentsToSign = new (std::nothrow) Student[n];
    if (!studentsToSign)
        return -1;

    for (size_t i = 0; i < n; i++)
    {
        std::cout << "Student " << i + 1 << ":\n";
        //createStudent(studentsToSign[i]);
        createStudentDynamic(studentsToSign[i]);
    }

    //char fileName[] = "students.dat";
    //writeStudentsToFile(fileName, studentsToSign, n);
    
    char fileName[] = "studentsDynamic.dat";
    writeStudentsToFileDynamic(fileName, studentsToSign, n);
   
    // delete dynamic name
    for (int i = 0; i < n; ++i) {
        delete[] studentsToSign[i].name;
    }

    delete[] studentsToSign;

    Student* readArr = new (std::nothrow) Student[n];
    int readCount;
    //readStudentsFromFile(fileName, readArr, readCount);;
    
    readStudentsFromFileDynamic(fileName, readArr, readCount);;
    
    printStudents(readArr, readCount);
    
    delete[] readArr;*/
    
    // Task 4
    //const char fileName[] = "file.dat";
    //std::ifstream ifs(fileName, std::ios::binary);

    //if (!ifs.is_open()) 
    //{
    //    std::cout << "Cannot open file : " << fileName << std::endl;
    //    return 1;
    //}

    //ifs.seekg(0, std::ios::end);
    //std::streampos fileSize = ifs.tellg();
    //ifs.seekg(0, std::ios::beg);

    //size = fileSize / sizeof(int);

    //arr = new (std::nothrow) int[size];

    //if (!arr)
    //    return 1;

    //ifs.read(reinterpret_cast<char*>(arr), fileSize);

    //ifs.close();

    //for (int i = 0; i < size; i++) {
    //    std::cout << arr[i] << " ";
    //}

    //std::cout << std::endl;

    //std::cout << "Sum of arr[0] and arr[1]: " << getSum(0, 1) << std::endl;

    //delete[] arr;
}
