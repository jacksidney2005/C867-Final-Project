#ifndef student
#define student

#include "degree.h"
#include <string>

using namespace std;

class Student {
    // D1 variable declerations
    private:
        string studentID;
        string firstName;
        string lastName;
        string emailAddress;
        int age;
        int daysToComplete[3];
        DegreeProgram degreeProgram;

    public:
        // Accessors
        string getStudentID() const;
        string getFirstName() const;
        string getLastName() const;
        string getEmailAddress() const;
        int getAge() const;
        int (&getDaysToComplete())[3];
        DegreeProgram getDegree() const;

        // Mutators
        void setStudentID(string studentID);
        void setFirstName(string firstName);
        void setLastName(string lastName);
        void setEmailAddress(string emailAddress);
        void setAge(int age);
        void setDaysToComplete(int (&newDaysToComplete)[3]);
        void setDegree(DegreeProgram degreeProgram);
        void print();

        // Constructors
        Student();
        Student(string studentID, string firstName, string lastName, string emailAddress,
        int age, int (&daysToComplete)[3], DegreeProgram degreeProgram);

        ~Student();
};

#endif