#include <iostream>
#include <cstring>
using namespace std;

// ------------------ COURSE CLASS ------------------
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

// ------------------ GRADE CLASS ------------------
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

// ------------------ STUDENT CLASS ------------------
class Student {
private:
    char reg_no[20];
    char name[50];
    int age;
    Course course;
    Grade grade;

public:
    Student() {}

    Student(const char* reg, const char* nm, int a, Course c, int mark) {
        strcpy(reg_no, reg);
        strcpy(name, nm);
        age = a;
        course = c;
        grade.mark = mark;
        grade.calculate_grade();
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
        cout << "Reg: " << reg_no
             << ", Name: " << name
             << ", Age: " << age
             << ", Course: " << course.course_code << " - " << course.course_name
             << ", Mark: " << grade.mark
             << ", Grade: " << grade.the_grade << endl;
    }
};

// ------------------ STUDENT LIST (ARRAY-BASED) ------------------
class StudentArrayList {
private:
    int size;
    int capacity;
    Student* students;

    void resize() {
        capacity *= 2;
        Student* new_array = new Student[capacity];
        for (int i = 0; i < size; i++) {
            new_array[i] = students[i];
        }
        delete[] students;
        students = new_array;
    }

public:
    // Constructor: empty list
    StudentArrayList(int cap = 10) {
        size = 0;
        capacity = cap;
        students = new Student[capacity];
    }

    // Constructor: list with one student
    StudentArrayList(Student s) {
        size = 1;
        capacity = 10;
        students = new Student[capacity];
        students[0] = s;
    }

    // Constructor: copy list
    StudentArrayList(const StudentArrayList& other) {
        size = other.size;
        capacity = other.capacity;
        students = new Student[capacity];
        for (int i = 0; i < size; ++i) {
            students[i] = other.students[i];
        }
    }

    // Add student at end
    void add(Student s) {
        if (size >= capacity)
            resize();
        students[size++] = s;
    }

    // Add student at position
    void add(Student s, int position) {
        if (position < 0 || position > size) {
            cout << "Invalid position.\n";
            return;
        }
        if (size >= capacity)
            resize();
        for (int i = size; i > position; --i)
            students[i] = students[i - 1];
        students[position] = s;
        size++;
    }

    // Remove student by object (reg_no match)
    void remove(Student s) {
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (strcmp(students[i].get_reg_no(), s.get_reg_no()) == 0) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            cout << "Student not found.\n";
            return;
        }
        for (int i = index; i < size - 1; i++) {
            students[i] = students[i + 1];
        }
        size--;
    }

    // Remove student at position
    void remove_at(int position) {
        if (position < 0 || position >= size) {
            cout << "Invalid position.\n";
            return;
        }
        for (int i = position; i < size - 1; i++) {
            students[i] = students[i + 1];
        }
        size--;
    }

    // Return current size
    int get_size() const {
        return size;
    }

    // Destroy the list
    void destroy() {
        delete[] students;
        students = nullptr;
        size = 0;
        capacity = 0;
    }

    // Display all students
    void display_all() const {
        for (int i = 0; i < size; ++i) {
            students[i].print();
        }
    }

    // Destructor
    ~StudentArrayList() {
        destroy();
    }
};

// ------------------ MAIN DRIVER ------------------
int main() {
    Course c1("ICS2105", "Data Structures");

    Student s1("CT123-4501/2023", "Alice", 21, c1, 78);
    Student s2("CT123-4502/2023", "Brian", 22, c1, 61);
    Student s3("CT123-4503/2023", "Cynthia", 23, c1, 49);

    StudentArrayList list;
    list.add(s1);
    list.add(s2);
    list.add(s3, 1);  // Add Cynthia at position 1

    cout << "List after additions:\n";
    list.display_all();

    list.remove_at(1);  // Remove Cynthia
    cout << "\nList after removing student at position 1:\n";
    list.display_all();

    cout << "\nSize of list: " << list.get_size() << endl;

    list.destroy();
    cout << "List destroyed. Size: " << list.get_size() << endl;

    return 0;
}
