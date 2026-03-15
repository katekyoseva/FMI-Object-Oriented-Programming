/*
* @author Ekaterina Kyoseva
* @idnumber 7MI0700412
* @compiler VC
*/

#include <iostream>
#include <fstream>

const int MAX_SIZE = 129;
const int MAX_USERS = 100;
const int MAX_COMMAND_LEN = 30;

const char* USERS_FILE = "users.txt";
const char* STATS_FILE = "stats.txt";
const char* LAST_SESSION_FILE = "last_session.txt";

System mySystem;

int totalRegistrations = 0;
int successfulLogins = 0;
int failedLogins = 0;
void saveStats();

void saveLastSession(const char* email);

struct User {
    char name[MAX_SIZE]{};
    char email[MAX_SIZE]{};
    char password[MAX_SIZE]{};
};

struct System {
    User users[MAX_USERS];
    unsigned userCount = 0;
};

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

// save and print user - not used
/*
void saveUser(const User& user, const char* fileName) {
    std::ofstream ofs(fileName, std::ios::app);

    if (!ofs.is_open())
    {
        std::cout << "Cannot open file for writing: " << fileName << std::endl;
        return;
    }

    ofs << user.name << " "
        << user.email << " "
        << user.password << '\n';

    ofs.close();
}

void readUser(User& user, const char* fileName) {
    std::ifstream ifs(fileName);

    if (!ifs.is_open())
    {
        std::cout << "Cannot open file for reading: " << fileName << std::endl;
        return;
    }

    ifs >> user.name;
    ifs >> user.email;
    ifs >> user.password;

    ifs.close();
} 
*/

void saveSystem(const System& system, const char* fileName)
{
    std::ofstream ofs(fileName);

    if (!ofs.is_open())
    {
        std::cout << "Cannot open file for writing: " << fileName << std::endl;
        return;
    }

    ofs << system.userCount << '\n';

    for (unsigned i = 0; i < system.userCount; i++)
    {
        ofs << system.users[i].name << " "
            << system.users[i].email << " "
            << system.users[i].password << '\n';
    }

    ofs.close();
}

void loadSystem(System& system, const char* fileName) {
    std::ifstream ifs(fileName);

    if (!ifs.is_open())
    {
        //std::cout << "Cannot open file for reading: " << fileName << std::endl;
        system.userCount = 0;
        return;
    }

    ifs >> system.userCount;

    for (unsigned i = 0; i < system.userCount; i++)
    {
        ifs >> system.users[i].name
            >> system.users[i].email
            >> system.users[i].password;
    }
    
    ifs.close();
}

void registerUser(System& system)
{
    if (system.userCount >= 100)
    {
        std::cout << "System full\n";
        return;
    }

    User user;

    std::cout << "Enter name:\n\\>";
    std::cin >> user.name;

    std::cout << "Enter email:\n\\>";
    std::cin >> user.email;

    std::cout << "Enter password:\n\\>";
    std::cin >> user.password;

    system.users[system.userCount++] = user;
    totalRegistrations++;
    saveStats();

    std::cout << "Registration successful\n";
}

void login(System& system)
{
    char email[MAX_SIZE];
    char password[MAX_SIZE];

    std::cout << "Enter email:\n\\>";
    std::cin >> email;

    for (size_t i = 0; i < system.userCount; i++)
    {
        if (areEqualStr(system.users[i].email, email))
        {
            std::cout << "Enter password:\n\\>";
            std::cin >> password;

            if (areEqualStr(system.users[i].password, password))
            {
                std::cout << "Login successful\n";
                successfulLogins++;
                saveStats();

                saveLastSession(email);
                return;
            }
        }
    }

    std::cout << "Login failed\n";
    failedLogins++;
    saveStats();
}

// stats
void saveStats()
{
    std::ofstream ofs(STATS_FILE);

    if (!ofs.is_open())
    {
        std::cout << "Cannot open file for writing: " << STATS_FILE << std::endl;
        return;
    }

    ofs << "Registrations: " << totalRegistrations << '\n';
    ofs << "Successful logins: " << successfulLogins << '\n';
    ofs << "Failed logins: " << failedLogins << '\n';

    ofs.close();
}

void loadStats()
{
    std::ifstream ifs(STATS_FILE);

    if (!ifs.is_open())
    {
        std::cout << "Cannot open file for reading: " << STATS_FILE << std::endl;
        return;
    }

    char temp[MAX_COMMAND_LEN];

    ifs >> temp >> totalRegistrations;
    ifs >> temp >> temp >> successfulLogins;
    ifs >> temp >> temp >> failedLogins;

    ifs.close();
}

void printStats()
{
    std::cout << "Registrations: " << totalRegistrations << std::endl;
    std::cout << "Successful logins: " << successfulLogins << std::endl;
    std::cout << "Failed logins: " << failedLogins << std::endl;
}

// last session
void saveLastSession(const char* email)
{
    std::ofstream ofs(LAST_SESSION_FILE);

    if (!ofs.is_open())
    {
        std::cout << "Cannot open file for writing: " << STATS_FILE << std::endl;
        return;
    }

    ofs << email;

    ofs.close();
}

void showLastSession()
{
    std::ifstream ifs(LAST_SESSION_FILE);

    if (!ifs.is_open())
    {
        std::cout << "Cannot open file for reading: " << STATS_FILE << std::endl;
        return;
    }

    char email[MAX_SIZE];

    ifs >> email;

    std::cout << "Last logged user: " << email << '\n';

    ifs.close();
}


int main()
{
    if (std::ifstream(STATS_FILE))
        loadStats();

    loadSystem(mySystem, USERS_FILE);
    if (std::ifstream(LAST_SESSION_FILE))
        showLastSession();

    char command[MAX_COMMAND_LEN];

    while (true)
    {
        std::cout << "\nEnter command:\n\\>";
        std::cin >> command;

        if (areEqualStr(command, "register"))
            registerUser(mySystem);
        else if (areEqualStr(command, "login"))
            login(mySystem);
        else if (areEqualStr(command, "statistics"))
            printStats();
        else if (areEqualStr(command, "exit"))
            break;
    }

    saveSystem(mySystem, USERS_FILE);

    return 0;
}
