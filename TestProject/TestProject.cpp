#include <iostream>
#include <string>

using namespace std;
bool isIntegerA(const std::string& str);

enum class position
{
    LABORANT,
    MANAGER,
    SECRETARY,
    OTHER
};

class Employee
{
public:
    int number;
    float salary;
    char date[50];
    position position;
    void inputemployee()
    {
        cout << "Number of employee: ";
        cin >> number;
        cout << "Salary ";
        cin >> salary;
        cout << "Date: ";
        cin >> date;
        int pos;
        cout << "Position: 0-LABORANT 1-MANAGER 2-SECRETARY 3-OTHER: ";
        string pos1;

        bool validInput = false;
        //checking of input postion
        while (!validInput) {
            cin >> pos1;
            if (isIntegerA(pos1)) {
                pos = stoi(pos1);
                if (pos == 0 or pos == 1 or pos == 2 or pos == 3) validInput = true;
                else cout << "Wrong number. Try again:";
            }
            else
            {
                cout << "Wrong numer. Try again:" << endl;
            }
        }

        switch (pos)
        {
        case 0: position::LABORANT;
        case 1: position::MANAGER;
        case 2: position::SECRETARY;
        case 3: position::OTHER;
        }
    }
};


int main()
{
    while (true)
    {
        cout << "Would you like to continue?\n1-Yes\n2-Exit ";
        int c;
        string c1;
        bool validInput = false;
        while (!validInput) {
            std::cin >> c;
            if (isIntegerA(c1)) {
                c = std::stoi(c1);
                if (c == 1 or c == 2) validInput = true;
                else cout << "Wrong number. Try again:";
            }
            else
            {
                cout << "Wrong numer. Try again:" << std::endl;
            }
        }

        if (c == 1)
        {
            cout << "Input number of employees\n";
            int i, n;
            cin >> n;
            Employee* e = new Employee[n];
            for (i = 0; i < n; i++)
            {
                cout << "Employee " << i + 1 << ":\n";
                e[i].inputemployee();
            }
            break;
        }
        if (c == 2) break;
    }
}

bool isIntegerA(const std::string& str)
{
    if (str.empty()) {
        return false;
    }

    size_t start = 0;
    if (str[0] == '-') {
        start = 1;
    }

    for (size_t i = start; i < str.length(); ++i) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}