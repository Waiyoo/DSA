#include <iostream>
#include <string>
using namespace std;

// ===== COURSE ADT =====
class Course {
private:
    string course_code;
    string course_name;

public:
    Course() : course_code(""), course_name("") {}
    Course(string code, string name) : course_code(code), course_name(name) {}

    void setCourseCode(string code) { course_code = code; }
    void setCourseName(string name) { course_name = name; }

    string getCourseCode() const { return course_code; }
    string getCourseName() const { return course_name; }

    void display() const {
        cout << course_code << " - " << course_name;
    }
};

// ===== GRADE ADT =====
class Grade {
private:
    int mark;
    char the_grade;

public:
    Grade() : mark(0), the_grade('E') {}

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

// ===== STUDENT ADT =====
class Student {
private:
    string reg_no;
    string name;
    int age;
    Course course;
    Grade grade;

public:
    Student() : reg_no(""), name(""), age(0) {}

    Student(string r, string n, int a, Course c, Grade g)
        : reg_no(r), name(n), age(a), course(c), grade(g) {}

    // Setters
    void set_regNo(string r) { reg_no = r; }
    void set_name(string n) { name = n; }
    void set_age(int a) { age = a; }
    void set_course(Course c) { course = c; }
    void set_grade(Grade g) { grade = g; }

    // Getters
    string get_regNo() const { return reg_no; }
    string get_name() const { return name; }
    int get_age() const { return age; }
    Course get_course() const { return course; }
    Grade get_grade() const { return grade; }

    void display() const {
        cout << "Reg No: " << reg_no
             << ", Name: " << name
             << ", Age: " << age
             << ", Course: ";
        course.display();
        cout << ", Mark: " << grade.getMark()
             << ", Grade: " << grade.getGrade() << endl;
    }

    bool operator==(const Student& other) const {
        return reg_no == other.reg_no;
    }
};
