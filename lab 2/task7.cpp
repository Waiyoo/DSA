#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ----- Grade Class -----
class Grade {
private:
    int mark;
    char the_grade;

public:
    Grade() : mark(0), the_grade('E') {}

    void set_mark(int m) {
        mark = m;
    }

    int get_mark() const {
        return mark;
    }

    char get_the_grade() const {
        return the_grade;
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
};

// ----- Course Class -----
class Course {
private:
    string course_code;
    string course_name;

public:
    Course() : course_code(""), course_name("") {}

    Course(string code, string name) : course_code(code), course_name(name) {}

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

// ----- Student Class -----
class Student {
private:
    string reg_no;
    string name;
    int age;
    Course course;
    Grade grade;

public:
    Student() : reg_no(""), name(""), age(0) {}

    Student(string reg, string n, int a, Course c) : reg_no(reg), name(n), age(a), course(c) {}

    void set_regNo(string reg) {
        reg_no = reg;
    }

    string get_regNo() const {
        return reg_no;
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

    Grade get_grade() const {
        return grade;
    }

    void display() const {
        cout << "Reg No: " << reg_no << ", Name: " << name
             << ", Age: " << age
             << ", Course: " << course.get_course_code() << " - " << course.get_course_name()
             << ", Mark: " << grade.get_mark()
             << ", Grade: " << grade.get_the_grade() << endl;
    }
};

// ----- Main Driver -----
int main() {
    vector<Student> student_list;

    // Create a course
    Course course("ICS 2105", "Data Structures");

    // Create and store 15 students
    for (int i = 1; i <= 15; ++i) {
        string reg = "CT123-" + to_string(4500 + i) + "/2023";
        string name = "Student" + to_string(i);
        int age = 20 + (i % 3);

        Student s(reg, name, age, course);
        s.set_mark(35 + i * 3); // Set different marks
        s.calculate_grade();
        student_list.push_back(s);
    }

    // Display student records
    cout << "Student Records:\n";
    for (const Student& s : student_list) {
        s.display();
    }

    return 0;
}
