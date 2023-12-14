#include<iostream>
#include<cstring>
using namespace std;
class Student{
    private:
    string name;
    int rollno;
    char div;
    string address;
    static int totalStudents;
    friend class studentDB;
    public:
    static int getTotalStudents();
    Student():rollno(0),div('\0'){totalStudents++;}
    Student(string name,int rollno,char div,string address){
        this->name=name;
        this->address=address;
        this->div=div;
        this->rollno=rollno;
        totalStudents++;
    }
    Student(Student &obj){
        this->name=obj.name;
        this->address=obj.address;
        this->div=obj.div;
        this->rollno=obj.rollno;
        totalStudents++;
    }
    void display(){
        cout<<"Name : "<<name<<endl;
        cout<<"Roll No : "<<rollno<<endl;
        cout<<"Division : "<<div<<endl;
        cout<<"Address : "<<address<<endl;
    }
    void accept(){
        cout<<"Enter the name : ";
        getline(cin,name);
        cout<<"Enter the Roll No : ";
        cin>>rollno;
        cout<<"Enter the Division (A/B/C) : ";
        cin>>div;
        cin.ignore();
        cout<<"Enter the Address : ";
        getline(cin,address);
    }
};
int Student::totalStudents=0;
int Student::getTotalStudents(){
    return Student::totalStudents;
}

class studentDB{
    public:
    static void returnTotal(){
        cout<<"\nTotal students : "<<Student::getTotalStudents()<<endl;
    }
};

int main(){
    Student s1("Suyash Dashputre",76,'A',"Nashuk Phata");
    s1.display();

    Student s2;
    s2.accept();
    s2.display();

    Student s3(s2);
    s3.display();

    studentDB::returnTotal();
    return 0;
}
