#include<iostream>
#include<cstring>
using namespace std;

class Student{
private:
    char *name;
    int rollNumber;
    char *className;
    char division;
    char *dob;
    char *bloodGroup;
    char *contactAddress;
    char *telephoneNumber;
    char *licenseNumber;
    static int totalStudents;

public:
    static int getTotalStudents();
    friend class studentDB;

    Student():name(NULL),rollNumber(0),className(NULL),division('\0'),dob(NULL),bloodGroup(NULL),contactAddress(NULL),telephoneNumber(NULL),licenseNumber(NULL){totalStudents++;}

    Student (const char* name, int rollNumber, const char* className,const char division,const char* dob, const char* bloodGroup, const char* contactAddress, const char* telephoneNumber, const char* licenseNumber){
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);

        this->className = new char[strlen(className)+1];
        strcpy(this->className, className);

        this->bloodGroup = new char[strlen(bloodGroup)+1];
        strcpy(this->bloodGroup,bloodGroup);

        this->dob = new char[strlen(dob)+1];
        strcpy(this->dob, dob);

        this->contactAddress = new char[strlen(contactAddress)+1];
        strcpy(this->contactAddress, contactAddress);

        this->telephoneNumber = new char[strlen(telephoneNumber)+1];
        strcpy(this->telephoneNumber, telephoneNumber);

        this->licenseNumber = new char[strlen(licenseNumber)+1];
        strcpy(this->licenseNumber, licenseNumber);

        this->rollNumber=rollNumber;
        this->division=division;
        totalStudents++;
    }

    Student(Student &obj){
        this->name = new char[strlen(obj.name)+1];
        strcpy(this->name, obj.name);
        this->className = new char[strlen(obj.className)+1];
        strcpy(this->className, obj.className);
        this->bloodGroup = new char[strlen(obj.bloodGroup)+1];
        strcpy(this->bloodGroup, obj.bloodGroup);
        this->contactAddress = new char[strlen(obj.contactAddress)+1];
        strcpy(this->contactAddress, obj.contactAddress);
        this->telephoneNumber = new char[strlen(obj.telephoneNumber)+1];
        strcpy(this->telephoneNumber, obj.telephoneNumber);
        this->licenseNumber = new char[strlen(obj.licenseNumber)+1];
        strcpy(this->licenseNumber, obj.licenseNumber);
        this->rollNumber=obj.rollNumber;
        this->division=obj.division;
        totalStudents++;
    }

    void accept(){
        cout<<"Enter name: ";
        this->name = new char[100];
        cin.getline(this->name, 100);

        cout<<"Enter roll : ";
        cin>>this->rollNumber;
        cout<<"Enter Divison : ";
        cin>>this->division;
        
        cin.ignore();
        cout<<"Enter Class Name : ";
        this->className = new char[50];
        cin.getline(this->className,50);

        cout<<"Enter address : ";
        this->contactAddress = new char[100];
        cin.getline(this->contactAddress,100);

        cout<<"Enter bloodgrp : ";
        this->bloodGroup = new char[5];
        cin.getline(this->bloodGroup,5);

        cout<<"Enter tele : ";
        this->telephoneNumber = new char[20];
        cin.getline(this->telephoneNumber,20);
        cout<<"Enter dob : ";
        this->dob = new char[20];
        cin.getline(this->dob,20);

        cout<<"Enter lociense Name : ";
        this->licenseNumber = new char[20];
        cin.getline(this->licenseNumber,20);
        
        
    }

    void displayInfo() const
    {
        cout << "\nName: " << name << "\nRoll Number: " << rollNumber << "\nClass: " << className << "\nDivision: " << division
             << "\nDate of Birth: " << dob << "\nBlood Group: " << bloodGroup << "\nContact Address: " << contactAddress
             << "\nTelephone Number: " << telephoneNumber << "\nDriving License: " << licenseNumber << "\n\n";
    }

    ~Student(){
        totalStudents--;
    }


};
int Student:: totalStudents = 0;
int Student::getTotalStudents(){
    return Student::totalStudents;
}

class studentDB{
    public:
    static void returnTotal(){
        cout<<"\nNumber of total students : "<<Student::getTotalStudents()<<endl;
    }
};

int main(int argc, char const *argv[])
{
    try
    {
        Student student1("John Doe", 101, "12A", 'A', "01-01-2000", "A+", "123 Main St", "1234567890", "DL123456");
        Student student2;
        student2.accept();

        student1.displayInfo();
        Student s3(student2);
        s3.displayInfo();
        student2.displayInfo();

        studentDB::returnTotal();

    }
    catch (const exception &e)
    {
        cout << "Error: " << e.what() << "\n";
    }

    return 0;
}