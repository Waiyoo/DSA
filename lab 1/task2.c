#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 40

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

Student students[MAX_STUDENTS];
int student_count = 0;

char computeGrade(int mark) {
    if (mark > 69) return 'A';
    else if (mark > 59) return 'B';
    else if (mark > 49) return 'C';
    else if (mark > 39) return 'D';
    else return 'E';
}

void addStudent() {
    if (student_count >= MAX_STUDENTS) {
        printf("Student list is full!\n");
        return;
    }

    Student s;

    printf("Enter registration number: ");
    scanf("%s", s.reg_no);
    printf("Enter name: ");
    getchar(); // to consume newline character
    fgets(s.name, 50, stdin);
    s.name[strcspn(s.name, "\n")] = '\0';
    printf("Enter age: ");
    scanf("%d", &s.age);
    printf("Enter course code: ");
    scanf("%s", s.course.course_code);
    printf("Enter course name: ");
    getchar();
    fgets(s.course.course_name, 50, stdin);
    s.course.course_name[strcspn(s.course.course_name, "\n")] = '\0';

    students[student_count++] = s;
    printf("Student added successfully.\n");
}

void editStudent() {
    char reg_no[20];
    printf("Enter registration number of student to edit: ");
    scanf("%s", reg_no);

    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].reg_no, reg_no) == 0) {
            printf("Editing details for %s\n", students[i].name);
            printf("Enter new name: ");
            getchar();
            fgets(students[i].name, 50, stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0';
            printf("Enter new age: ");
            scanf("%d", &students[i].age);
            return;
        }
    }
    printf("Student not found.\n");
}

void assignMarks() {
    char reg_no[20];
    printf("Enter registration number of student: ");
    scanf("%s", reg_no);

    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].reg_no, reg_no) == 0) {
            int mark;
            printf("Enter mark (0-100): ");
            scanf("%d", &mark);
            students[i].grade.mark = mark;
            students[i].grade.the_grade = computeGrade(mark);
            printf("Grade calculated and saved as %c\n", students[i].grade.the_grade);
            return;
        }
    }
    printf("Student not found.\n");
}

void displayStudents() {
    for (int i = 0; i < student_count; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Reg No: %s\n", students[i].reg_no);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Course Code: %s\n", students[i].course.course_code);
        printf("Course Name: %s\n", students[i].course.course_name);
        printf("Mark: %d\n", students[i].grade.mark);
        printf("Grade: %c\n", students[i].grade.the_grade);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nMenu:\n1. Add Student\n2. Edit Student\n3. Assign Marks\n4. Display Students\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addStudent(); break;
            case 2: editStudent(); break;
            case 3: assignMarks(); break;
            case 4: displayStudents(); break;
            case 5: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}



