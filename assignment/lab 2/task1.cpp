#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 40;

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

    void display() const {
        cout << "Reg No: " << reg_no
             << ", Name: " << name
             << ", Age: " << age
             << ", Course: " << course.course_code << " - " << course.course_name
             << ", Mark: " << grade.getMark()
             << ", Grade: " << grade.getGrade() << endl;
    }

    bool operator==(const Student& other) const {
        return reg_no == other.reg_no;
    }
};

class StudentList {
private:
    Student students[MAX_SIZE];
    int size;

public:
    // Constructor: empty list
    StudentList() {
        size = 0;
    }

    // Constructor: initialize with one student
    StudentList(Student s) {
        size = 1;
        students[0] = s;
    }

    // Constructor: copy from another list
    StudentList(const StudentList& other) {
        size = other.size;
        for (int i = 0; i < size; i++) {
            students[i] = other.students[i];
        }
    }

    // Add student at end
    void addStudent(Student s) {
        if (size >= MAX_SIZE) {
            cout << "List is full.\n";
            return;
        }
        students[size++] = s;
    }

    // Add student at specific position
    void addStudentAt(Student s, int pos) {
        if (size >= MAX_SIZE) {
            cout << "List is full.\n";
            return;
        }
        if (pos < 0 || pos > size) {
            cout << "Invalid position.\n";
            return;
        }
        for (int i = size; i > pos; i--) {
            students[i] = students[i - 1];
        }
        students[pos] = s;
        size++;
    }

    // Remove student by object
    void removeStudent(Student s) {
        for (int i = 0; i < size; i++) {
            if (students[i] == s) {
                for (int j = i; j < size - 1; j++) {
                    students[j] = students[j + 1];
                }
                size--;
                cout << "Student removed.\n";
                return;
            }
        }
        cout << "Student not found.\n";
    }

    // Remove student at position
    void removeAt(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid position.\n";
            return;
        }
        for (int i = pos; i < size - 1; i++) {
            students[i] = students[i + 1];
        }
        size--;
        cout << "Student removed at position " << pos << ".\n";
    }

    // Get current size of list
    int getSize() const {
        return size;
    }

    // Destroy the list
    void destroyList() {
        size = 0;
        cout << "List destroyed.\n";
    }

    // Display all students
    void displayList() const {
        if (size == 0) {
            cout << "List is empty.\n";
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << i + 1 << ". ";
            students[i].display();
        }
    }
};

// === Sample Test ===
int main() {
    Student s1 = {"S01", "Alice", 20, {"CS101", "Intro to CS"}, {}};
    s1.grade.setMark(85);

    Student s2 = {"S02", "Bob", 21, {"CS102", "Data Structures"}, {}};
    s2.grade.setMark(67);

    Student s3 = {"S03", "Carol", 19, {"CS103", "Algorithms"}, {}};
    s3.grade.setMark(73);

    StudentList list;
    list.addStudent(s1);
    list.addStudent(s2);
    list.addStudentAt(s3, 1);

    cout << "\n-- Student List --\n";
    list.displayList();

    cout << "\n-- Removing Bob --\n";
    list.removeStudent(s2);
    list.displayList();

    cout << "\n-- List Size: " << list.getSize() << " --\n";

    cout << "\n-- Destroying List --\n";
    list.destroyList();
    list.displayList();

    return 0;
}
