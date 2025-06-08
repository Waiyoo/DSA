#include <iostream>
#include <vector>
using namespace std;

class Course {
public:
    string course_code;
    string course_name;
};

class Grade {
private:
    int mark;
    char the_grade;

public:
    void setMark(int m) {
        mark = m;
        if (mark > 69) the_grade = 'A';
        else if (mark > 59) the_grade = 'B';
        else if (mark > 49) the_grade = 'C';
        else if (mark > 39) the_grade = 'D';
        else the_grade = 'E';
    }

    int getMark() const { return mark; }
    char getGrade() const { return the_grade; }
};

class Student {
public:
    string reg_no;
    string name;
    int age;
    Course course;
    Grade grade;

    void inputDetails() {
        cout << "Enter Reg No: ";
        cin >> reg_no;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Course Code: ";
        cin >> course.course_code;
        cout << "Enter Course Name: ";
        cin.ignore();
        getline(cin, course.course_name);
    }

    void assignMark(int mark) {
        grade.setMark(mark);
    }

    void display() const {
        cout << "\nReg No: " << reg_no << "\nName: " << name
             << "\nAge: " << age << "\nCourse Code: " << course.course_code
             << "\nCourse Name: " << course.course_name
             << "\nMark: " << grade.getMark()
             << "\nGrade: " << grade.getGrade() << endl;
    }
};

int main() {
    vector<Student> students;
    int choice;

    while (true) {
        cout << "\n1. Add Student\n2. Assign Marks\n3. Display Students\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            Student s;
            s.inputDetails();
            students.push_back(s);
        } else if (choice == 2) {
            string reg;
            int mark;
            cout << "Enter Reg No: ";
            cin >> reg;
            bool found = false;
            for (auto &s : students) {
                if (s.reg_no == reg) {
                    cout << "Enter Mark: ";
                    cin >> mark;
                    s.assignMark(mark);
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Student not found!" << endl;
        } else if (choice == 3) {
            for (const auto &s : students) s.display();
        } else {
            break;
        }
    }
}
