/*
Program name: VirtualFunction.cpp
Programmer: Tyler Davies
Date: 10-3-21
Version: 1.0
Description: This program contains and tests a base class named Student, and a derived class
             named Undergraduate. The Student class is an abstract class that has two pure
             virtual functions. The main program tests both classes by instantiating an Undergraduate
             object, prompting the user/updating the object's members, and printing a formatted report.
*/

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

//Student class is a base abstract class containing two pure virtual functions.
//It contains other functions for updating and getting the student's information.
class Student
{
private:
    string studentName, studentID, emailAddress;
public:
    Student();
    string getName()
        { return studentName; }
    string getID()
        { return studentID; }
    string getEmail()
        { return emailAddress; }
    void updateName(string name)
        { studentName = name; }
    void updateID(string id)
        { studentID = id; }
    void updateEmail(string email)
        { emailAddress = email; }
    virtual void calcGPA(int) = 0;
    virtual void printReport() = 0;
    virtual ~Student(){}
};

//Student class default constructor.
Student::Student()
{
    studentName = "First M.I. Last";
    studentID = "000000";
    emailAddress = "last_name@school.edu";
}

//This derived class adds more student information, and updates/defines the two virtual functions.
//It also contains other functions for updating and getting the student's additional information.
class Undergraduate : public Student
{
private:
    string phoneNumber, mailingAddress;
    float studentGPA;
public:
    Undergraduate() : Student()
    {
        phoneNumber = "###-###-####";
        mailingAddress = "Mailing Address";
        studentGPA = 0.0;
    }
    string getPhoneNumber()
        { return phoneNumber; }
    string getAddress()
        { return mailingAddress; }
    float getGPA()
        { return studentGPA; }
    void updatePhoneNumber(string number)
        { phoneNumber = number; }
    void updateAddress(string address)
        { mailingAddress = address; }
    void updateGPA(float gpa)
        { studentGPA = gpa; }
    virtual void calcGPA(int);
    virtual void printReport();
    virtual ~Undergraduate(){}
};

//This function takes an integer score and calculates/updates the studentGPA variable.
void Undergraduate::calcGPA(int score)
{
    if (score <= 100 && score >= 93)
        studentGPA = (float)4.0;        //Tells the compiler this number is a float not a double.
    else if (score <= 92 && score >= 90)
        studentGPA = (float)3.7;
    else if (score <= 89 && score >= 87)
        studentGPA = (float)3.3;
    else if (score <= 86 && score >= 83)
        studentGPA = (float)3.0;
    else if (score <= 82 && score >= 80)
        studentGPA = (float)2.7;
    else if (score <= 79 && score >= 77)
        studentGPA = (float)2.3;
    else if (score <= 76 && score >= 73)
        studentGPA = (float)2.0;
    else if (score <= 72 && score >= 70)
        studentGPA = (float)1.7;
    else if (score <= 69 && score >= 67)
        studentGPA = (float)1.3;
    else if (score <= 66 && score >= 65)
        studentGPA = (float)1.0;
    else if (score <= 64 && score >= 0)
        studentGPA = (float)0.0;
    else
    {
        cout << left << setw(8) << "Error: " << "score entered is not recognized!" << endl;
        cout << setw(8) << "The student's GPA will not be updated." << endl;
    }
}

//This functions prints all of the student's information in a formatted report.
void Undergraduate::printReport()
{
    cout << endl;
    cout << left << setw(20) << "Student Name: " << this->getName() << endl;
    cout << setw(20) << "Student ID: " << this->getID() << endl;
    cout << fixed << setprecision(1) << setw(20) << "Student GPA: " << studentGPA << endl;
    cout << setw(20) << "Mailing Address: " << mailingAddress << endl;
    cout << setw(20) << "Phone Number: " << phoneNumber << endl;
    cout << setw(20) << "Email: " << this->getEmail() << endl;
}

//The main program instantiates an Undergraduate object. It then prompts the user, while updating
//the object's members. The object then uses its functions to update the GPA and print a report.
int main()
{
    Undergraduate student;
    string name, id, address, email, phone;
    int score;

    cout << "Enter student's name: ";
    getline(cin, name);
    student.updateName(name);

    cout << "Enter student's ID: ";
    getline(cin, id);
    student.updateID(id);

    cout << "Enter mailing address (one line): ";
    getline(cin, address);
    student.updateAddress(address);

    cout << "Enter phone number: ";
    getline(cin, phone);
    student.updatePhoneNumber(phone);

    cout << "Enter email address: ";
    getline(cin, email);
    student.updateEmail(email);

    cout << "Enter final grade percentage (without percent sign): ";
    cin >> score;
    student.calcGPA(score);

    student.printReport();

    exit(0);
}