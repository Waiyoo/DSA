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

    void set_regNo(string r) { reg_no = r; }
    void set_name(string n) { name = n; }
    void set_age(int a) { age = a; }
    void set_course(Course c) { course = c; }
    void set_grade(Grade g) { grade = g; }

    string get_regNo() const { return reg_no; }
    string get_name() const { return name; }
    int get_age() const { return age; }
    Course get_course() const { return course; }
    Grade get_grade() const { return grade; }

    void calculate_grade() {
        int mark = grade.getMark();
        Grade g;
        g.setMark(mark);
        grade = g;
    }

    void update_mark(int new_mark) {
        grade.setMark(new_mark);
    }

    void display() const {
        cout << "Reg No: " << reg_no
             << ", Name: " << name
             << ", Age: " << age
             << ", Course: ";
        course.display();
        cout << ", Mark: " << grade.getMark()
             << ", Grade: " << grade.getGrade() << endl;
    }
};

// ===== STUDENT LIST CLASS =====
class StudentList {
private:
    Student students[40];
    int size;

public:
    StudentList() : size(0) {}

    void add_student(const Student& s) {
        if (size < 40) {
            students[size++] = s;
        }
    }

    void update_student_mark(int index, int mark) {
        if (index >= 0 && index < size) {
            students[index].update_mark(mark);
        }
    }

    void calculate_all_grades() {
        for (int i = 0; i < size; ++i) {
            students[i].calculate_grade();
        }
    }

    void display_all_students() const {
        for (int i = 0; i < size; ++i) {
            students[i].display();
        }
    }
};

// ===== DRIVER CODE =====
int main() {
    StudentList list;
    Course course("ICS2105", "Data Structures and Algorithms");

    string names[15] = {
        "Alice", "Brian", "Cynthia", "Daniel", "Esther",
        "Felix", "Grace", "Henry", "Ivy", "James",
        "Karen", "Leon", "Maria", "Nathan", "Olivia"
    };

    for (int i = 0; i < 15; i++) {
        string reg = "CT123-45" + to_string(i + 1) + "/2023";
        Grade g;
        g.setMark(30 + (i * 3)); // Varying marks
        Student s(reg, names[i], 20 + (i % 5), course, g);
        list.add_student(s);
    }

    // Update marks for demonstration
    list.update_student_mark(2, 88);  // Cynthia
    list.update_student_mark(5, 77);  // Felix
    list.update_student_mark(10, 64); // Karen

    // Calculate all grades and display all students
    list.calculate_all_grades();
    list.display_all_students();

    return 0;
}
