#include <iostream>
#include <cstring>
using namespace std;

// ----------- COURSE CLASS -----------
class Course {
public:
    char course_code[20];
    char course_name[50];

    Course() {
        strcpy(course_code, "");
        strcpy(course_name, "");
    }

    Course(const char* code, const char* name) {
        strcpy(course_code, code);
        strcpy(course_name, name);
    }
};

// ----------- GRADE CLASS -----------
class Grade {
public:
    int mark;
    char the_grade;

    Grade() : mark(0), the_grade('E') {}

    void calculate_grade() {
        if (mark > 69) the_grade = 'A';
        else if (mark > 59) the_grade = 'B';
        else if (mark > 49) the_grade = 'C';
        else if (mark > 39) the_grade = 'D';
        else the_grade = 'E';
    }
};

// ----------- STUDENT CLASS -----------
class Student {
private:
    char reg_no[20];
    char name[50];
    int age;
    Course course;
    Grade grade;

public:
    Student* next;

    Student(const char* reg, const char* nm, int a, Course c, int mark) {
        strcpy(reg_no, reg);
        strcpy(name, nm);
        age = a;
        course = c;
        grade.mark = mark;
        grade.calculate_grade();
        next = nullptr;
    }

    void set_mark(int mark) {
        grade.mark = mark;
        grade.calculate_grade();
    }

    const char* get_reg_no() { return reg_no; }
    const char* get_name() { return name; }
    int get_age() { return age; }
    Course get_course() { return course; }
    Grade get_grade() { return grade; }

    void print() {
        cout << "Reg No: " << reg_no
             << ", Name: " << name
             << ", Age: " << age
             << ", Course: " << course.course_code << " - " << course.course_name
             << ", Mark: " << grade.mark
             << ", Grade: " << grade.the_grade << endl;
    }
};

// ----------- LINKED LIST CLASS -----------
class StudentList {
private:
    Student* head;

public:
    StudentList() {
        head = nullptr;
    }

    void add_student(Student* new_student) {
        if (!head) {
            head = new_student;
        } else {
            Student* current = head;
            while (current->next)
                current = current->next;
            current->next = new_student;
        }
    }

    void update_mark(const char* reg_no, int new_mark) {
        Student* current = head;
        while (current) {
            if (strcmp(current->get_reg_no(), reg_no) == 0) {
                current->set_mark(new_mark);
                break;
            }
            current = current->next;
        }
    }

    void display_all() {
        Student* current = head;
        while (current) {
            current->print();
            current = current->next;
        }
    }

    ~StudentList() {
        while (head) {
            Student* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// ----------- MAIN DRIVER CODE -----------
int main() {
    StudentList list;
    Course course("ICS2105", "Data Structures");

    const char* names[] = {
        "Alice", "Brian", "Cynthia", "Daniel", "Esther",
        "Felix", "Grace", "Henry", "Ivy", "James",
        "Karen", "Leon", "Maria", "Nathan", "Olivia"
    };

    for (int i = 0; i < 15; ++i) {
        char reg[20];
        sprintf(reg, "CT123-45%02d/2023", i + 1);
        int mark = 30 + (i * 3); // sample marks
        Student* s = new Student(reg, names[i], 20 + (i % 5), course, mark);
        list.add_student(s);
    }

    list.update_mark("CT123-4503/2023", 87); // Cynthia
    list.update_mark("CT123-4506/2023", 74); // Felix
    list.update_mark("CT123-4510/2023", 61); // Karen

    list.display_all();

    return 0;
}
