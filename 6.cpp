#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Student{
    public:
    string name;
    string roll;
    bool operator==(Student s){
        return roll==s.roll;
    }
    bool operator<(Student s){
        return roll<s.roll;
    }
};

vector<Student> s;

void insert(){
    Student obj;
    cin.ignore();
    cout<<"Enter a name : ";
    getline(cin, obj.name);
    cout<<"Enter a roll : ";
    getline(cin, obj.roll);
    s.push_back(obj);
}

void displayRecord(Student obj){
    cout<<"\nName : "<<obj.name<<"\nRoll : "<<obj.roll<<"\n\n";
}
void display(){
    for_each(s.begin(),s.end(),displayRecord);
}

void deleteRecord(){
    Student rec;
    cout<<"Enter roll no to delete : ";
    cin>>rec.roll;
    vector<Student>::iterator i=find(s.begin(),s.end(),rec);
    if(i==s.end()) cout<<"\nNot found\n";
    else{
        s.erase(i);
        cout<<"\nRecords after deletion\n";
        display();
    }
}
void sort(){
    sort(s.begin(),s.end());
    cout<<"\nSorted Records\n";
    display();
}
void search(){
    Student rec;
    cout<<"Enter roll no to search : ";
    cin>>rec.roll;
    vector<Student>::iterator i=find(s.begin(),s.end(),rec);
    if(i==s.end()) cout<<"\nNot found\n";
    else{
        cout<<"\nfound\n";
        displayRecord(*i);
    }
}

int main(){
    int choice;
    do{
        cout<<"\n1.Insert"
            <<"\n2.Display"
            <<"\n3.Search"
            <<"\n4.Sort"
            <<"\n5.Delete"
            <<"\n6.Exit"
            <<"\nEnter choice : "
            <<endl;
            cin>>choice;
            switch (choice)
            {
            case 1:
            insert();
            break;
            case 2:
            display();
            break;
            case 3:
            search();
            break;
            case 4:
            sort();
            break;
            case 5:
            deleteRecord();
            break;
            default:
                break;
            }
    }while(choice!=6);
    return 0;
}