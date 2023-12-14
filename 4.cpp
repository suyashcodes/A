#include <iostream>
#include <fstream>
using namespace std;
class Employee
{
public:
    string name;
    int id;
    double salary;
    void accept()
    {
        cout << "Name : ";
        cin.ignore();
        getline(cin, name);
        cout << "ID : ";
        cin >> id;
        cout << "Salary : ";
        cin >> salary;
    }
    void display()
    {
        cout << "\nName : " << name;
        cout << "\nID : " << id;
        cout << "\nSalary : " << salary;
    }
};

int main()
{
    int n;
    cout << "Enter total number of employees ";
    cin >> n;
    Employee e[n];
    fstream f;
    f.open("4prfile.txt", ios::out);
    for (int i = 0; i < n; i++)
    {
        e[i].accept();
        f.write((char *)&e[i], sizeof(e[i]));
    }
    f.close();
    Employee ewrite[n];
    f.open("4prfile.txt", ios::in);

    if (!f)
    {
        cout << "File not found!";
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            f.read((char *)&ewrite[i], sizeof(ewrite[i]));
            ewrite[i].display();
        }
    }

    f.close();
}