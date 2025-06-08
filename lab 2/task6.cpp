#include <iostream>
#include <string>
using namespace std;

// Grade Class
class Grade {
private:
    int mark;
    char the_grade;

public:
    Grade() {
        mark = 0;
        the_grade = 'E';
    }

    void set_mark(int m) {
        mark = m;
    }

    int get_mark() const {
        return mark;
    }

    void calculate_grade() {
        if (mark > 69)
            the_grade = 'A';
        else if (mark > 59)
            the_grade = 'B';
        else if (mark > 49)
            the_grade = 'C';
        else if (mark > 39)
            the_grade = 'D';
        else
            the_grade = 'E';
    }

    char get_grade() const {
        return the_grade;
    }
};

// Course Class
class Course {
private:
    string course_code;
    string course_name;

public:
    Course() {
        course_code = "";
        course_name = "";
    }

    Course(string code, string name) {
        course_code = code;
        course_name = name;
    }

    void set_course_code(string code) {
        course_code = code;
    }

    string get_course_code() const {
        return course_code;
    }

    void set_course_name(string name) {
        course_name = name;
    }

    string get_course_name() const {
        return course_name;
    }
};

// Student Class
class Student {
private:
    string regNo;
    string name;
    int age;
    Course course;
    Grade grade;

public:
    Student() {
        regNo = "";
        name = "";
        age = 0;
    }

    Student(string reg, string nm, int a, Course c) {
        regNo = reg;
        name = nm;
        age = a;
        course = c;
    }

    void set_regNo(string r) {
        regNo = r;
    }

    string get_regNo() const {
        return regNo;
    }

    void set_name(string n) {
        name = n;
    }

    string get_name() const {
        return name;
    }

    void set_age(int a) {
        age = a;
    }

    int get_age() const {
        return age;
    }

    void set_course(Course c) {
        course = c;
    }

    Course get_course() const {
        return course;
    }

    void set_mark(int m) {
        grade.set_mark(m);
    }

    int get_mark() const {
        return grade.get_mark();
    }

    void calculate_grade() {
        grade.calculate_grade();
    }

    void set_grade(Grade g) {
        grade = g;
    }

    Grade get_grade() const {
        return grade;
    }

    void display() const {
        cout << "Reg No: " << regNo
             << ", Name: " << name
             << ", Age: " << age
             << ", Course: " << course.get_course_code()
             << " - " << course.get_course_name()
             << ", Mark: " << grade.get_mark()
             << ", Grade: " << grade.get_grade() << endl;
    }
};

// Main Program (Client Code)
int main() {
    const int SIZE = 15;
    Student students[SIZE];

    for (int i = 0; i < SIZE; i++) {
        string reg, name, code, cname;
        int age, mark;
        cout << "Enter RegNo for student " << i+1 << ": ";
        cin >> reg;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Course Code: ";
        cin >> code;
        cout << "Enter Course Name: ";
        cin.ignore();
        getline(cin, cname);
        cout << "Enter Marks: ";
        cin >> mark;

        Course course(code, cname);
        Student s(reg, name, age, course);
        s.set_mark(mark);
        s.calculate_grade();

        students[i] = s;
        cout << endl;
    }

    cout << "\n=== Students and Grades ===\n";
    for (int i = 0; i < SIZE; i++) {
        students[i].display();
    }

    return 0;
}
