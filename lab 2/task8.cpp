#include <iostream>
#include <vector>
#include <string>
using namespace std;

// === Assume the Grade, Course, and Student class definitions here are as defined earlier ===

// Reuse existing classes: Grade, Course, and Student
// Here is just the DRIVER (main) part as per your request

int main() {
    vector<Student> student_list;

    // Define the common course for all students
    Course course("ICS2105", "Data Structures and Algorithms");

    // Add at least 15 students
    for (int i = 1; i <= 15; ++i) {
        string reg = "CT123-" + to_string(1000 + i) + "/2023";
        string name = "Student_" + to_string(i);
        int age = 18 + (i % 5);  // age between 18 and 22

        Student s(reg, name, age, course);

        // Set marks (simulate variety in performance)
        int mark = 30 + (i * 4); // e.g., 34, 38, 42, ..., up to 90
        s.set_mark(mark);

        // Calculate grade
        s.calculate_grade();

        // Add student to the list
        student_list.push_back(s);
    }

    // Display all students' info
    cout << "---- Student Records ----\n";
    for (Student& s : student_list) {
        s.display();
    }

    return 0;
}
