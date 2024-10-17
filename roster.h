#ifndef roster
#define roster

#include "student.h"
#include <array>

class Roster {
    public:
        int getNumStudents() {
            return this->numStudents;
        }

        std::string getStudentId(int index) {
            if (index < 0 || index >= this->numStudents) {
                return "";
            }

            return this->classRosterArray[index]->getStudentID();
        }

        void add(string studentID, string firstName, string lastName, string emailAddress, int age, 
            int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

        void remove(string studentID);
        void printAll();
        void printAverageDaysInCourse(string studentID);
        void printInvalidEmails();
        void printByDegreeProgram(DegreeProgram degreeProgram);
        void parseStudentInfo(string studentInfo);

        Roster() : classRosterArray(nullptr), numStudents(0), capacity(0) {};
        ~Roster();

    private:

        void ensureSize();

        Student** classRosterArray;
        int numStudents;
        int capacity;
};

#endif