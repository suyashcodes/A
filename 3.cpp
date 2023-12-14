#include <iostream>
#include <vector>
using namespace std;

class Publication
{
protected:
    string title;
    float price;

public:
    void add()
    {
        cout << "\nEnter title : ";
        cin.ignore();
        getline(cin, title);
        try
        {
            cout << "Enter a privce : ";
            cin >> price;
            if (cin.fail())
            {
                throw "Price must be numeric";
            }
        }
        catch (exception &e)
        {
            title = "";
            price = 0;
        }
    }
    void display()
    {
        cout << "\nTitle : " << title << "\nPrice : " << price << endl;
    }
};
class Book : public Publication
{
protected:
    int pagecount;

public:
    void addBook()
    {
        add();
        cout << "\nEnter a pagecount";
        try
        {
            cin >> pagecount;
            if (cin.fail())
            {
                throw "Invalid pagecount";
            }
        }
        catch (exception &e)
        {
        	cout<<e.what();
            pagecount = 0;
        }
    }
    void displayBook()
    {
        display();
        cout << "Pagecount : " << pagecount << endl;
    }
};
class Tape : public Publication
{
protected:
    int playTime;

public:
    void addTape()
    {
        add();
        cout << "\nAdd Playtime : ";
        try
        {
            cin >> playTime;
            if (cin.fail())
            {
                throw "Invlaide playtime";
            }
        }
        catch (exception &e)
        {
            playTime = 0;
        }
    }
    void displayTape()
    {
        display();
        cout << "Playtime : " << playTime << endl;
    }
};

int main()
{
    vector<Book> b;
    vector<Tape> t;
    cout<<"Enter the total number of books : ";
    int numb;
    cin>>numb;
    cout<<"Enter the total number of tapes : ";
    int numt;
    cin>>numt;
    b.resize(numb);
    t.resize(numt);
    int bcnt, tcnt, choice;
    do
    {
        cout << "\n1. Add Book"
             << "\n2. Add Tape"
             << "\n3. Display Book"
             << "\n4. Display Tape"
             << "\n5. Exit"
             << "\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            b[bcnt].addBook();
            bcnt++;
            break;
        case 2:
            t[tcnt].addTape();
            tcnt++;
            break;
        case 3:
            cout << "\nBooks : \n";
            for (int i = 0; i < bcnt; i++)
            {
                b[i].displayBook();
            }
            break;
        case 4:
            cout << "\nTape : \n";
            for (int i = 0; i < tcnt; i++)
            {
                t[i].displayTape();
            }
            break;
        case 5:
            cout << "Exiting..";
            break;
        default:
            break;
        }
    } while (choice != 5);
}
