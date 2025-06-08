#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ----------- STRUCT DEFINITIONS -----------

typedef struct {
    char course_code[20];
    char course_name[50];
} Course;

typedef struct {
    int mark;
    char the_grade;
} Grade;

typedef struct {
    char reg_no[20];
    char name[50];
    int age;
    Course course;
    Grade grade;
} Student;

typedef struct Node {
    Student student;
    struct Node* next;
} Node;

// ----------- FUNCTION DECLARATIONS -----------

Grade calculate_grade(int mark);
void add_student(Node** head, Student s);
void update_student_mark(Node* head, char reg_no[], int new_mark);
void calculate_all_grades(Node* head);
void display_students(Node* head);
Student create_student(char reg_no[], char name[], int age, Course course, int mark);

// ----------- FUNCTION IMPLEMENTATIONS -----------

Grade calculate_grade(int mark) {
    Grade g;
    g.mark = mark;
    if (mark > 69) g.the_grade = 'A';
    else if (mark > 59) g.the_grade = 'B';
    else if (mark > 49) g.the_grade = 'C';
    else if (mark > 39) g.the_grade = 'D';
    else g.the_grade = 'E';
    return g;
}

Student create_student(char reg_no[], char name[], int age, Course course, int mark) {
    Student s;
    strcpy(s.reg_no, reg_no);
    strcpy(s.name, name);
    s.age = age;
    s.course = course;
    s.grade = calculate_grade(mark);
    return s;
}

void add_student(Node** head, Student s) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->student = s;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        Node* curr = *head;
        while (curr->next != NULL)
            curr = curr->next;
        curr->next = new_node;
    }
}

void update_student_mark(Node* head, char reg_no[], int new_mark) {
    Node* curr = head;
    while (curr != NULL) {
        if (strcmp(curr->student.reg_no, reg_no) == 0) {
            curr->student.grade = calculate_grade(new_mark);
            curr->student.grade.mark = new_mark;
            break;
        }
        curr = curr->next;
    }
}

void calculate_all_grades(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        curr->student.grade = calculate_grade(curr->student.grade.mark);
        curr = curr->next;
    }
}

void display_students(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        Student s = curr->student;
        printf("Reg No: %s, Name: %s, Age: %d, Course: %s - %s, Mark: %d, Grade: %c\n",
               s.reg_no, s.name, s.age, s.course.course_code, s.course.course_name,
               s.grade.mark, s.grade.the_grade);
        curr = curr->next;
    }
}

// ----------- MAIN DRIVER CODE -----------

int main() {
    Node* student_list = NULL;
    Course course = {"ICS2105", "Data Structures"};

    char* names[] = {
        "Alice", "Brian", "Cynthia", "Daniel", "Esther",
        "Felix", "Grace", "Henry", "Ivy", "James",
        "Karen", "Leon", "Maria", "Nathan", "Olivia"
    };

    for (int i = 0; i < 15; ++i) {
        char reg[20];
        sprintf(reg, "CT123-45%02d/2023", i + 1);
        int mark = 30 + (i * 3); // sample marks
        Student s = create_student(reg, names[i], 20 + (i % 5), course, mark);
        add_student(&student_list, s);
    }

    // Update some marks
    update_student_mark(student_list, "CT123-4503/2023", 87); // Cynthia
    update_student_mark(student_list, "CT123-4506/2023", 74); // Felix
    update_student_mark(student_list, "CT123-4510/2023", 61); // Karen

    calculate_all_grades(student_list);
    display_students(student_list);

    return 0;
}
