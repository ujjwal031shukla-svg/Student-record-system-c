#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int roll;
    char name[50];
    char branch[50];
    float marks;
};


void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
int isDuplicateRoll(int roll);


int main() {
    int choice;

    do {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student Marks\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: printf("Exiting program...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}

int isDuplicateRoll(int roll) {
    FILE *fp;
    struct student s;

    fp = fopen("students.dat", "rb");
    if (fp == NULL)
        return 0;   

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll == roll) {
            fclose(fp);
            return 1;   
        }
    }

    fclose(fp);
    return 0;   
}
void addStudent() {
    FILE *fp;
    struct student s;

    printf("Enter roll number: ");
    scanf("%d", &s.roll);

    if (isDuplicateRoll(s.roll)) {
        printf("Error: Roll number already exists!\n");
        return;
    }

    printf("Enter name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter branch: ");
    scanf(" %[^\n]", s.branch);

    printf("Enter marks: ");
    scanf("%f", &s.marks);

    fp = fopen("students.dat", "ab");
    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);

    printf("Student added successfully.\n");
}


void displayStudents() {
    FILE *fp;
    struct student s;
    int found = 0;

    fp = fopen("students.dat", "rb");
    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }

    while (fread(&s, sizeof(s), 1, fp)) {
        printf("\nRoll: %d", s.roll);
        printf("\nName: %s", s.name);
        printf("\nBranch: %s", s.branch);
        printf("\nMarks: %.2f\n", s.marks);
        found = 1;
    }

    if (!found)
        printf("No students available.\n");

    fclose(fp);
}


void searchStudent() {
    FILE *fp;
    struct student s;
    int roll, found = 0;

    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    fp = fopen("students.dat", "rb");
    if (fp == NULL) {
        printf("File not found.\n");
        return;
    }

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll == roll) {
            printf("\nStudent Found:");
            printf("\nName: %s", s.name);
            printf("\nBranch: %s", s.branch);
            printf("\nMarks: %.2f\n", s.marks);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found.\n");

    fclose(fp);
}


void updateStudent() {
    FILE *fp;
    struct student s;
    int roll, found = 0;

    printf("Enter roll number to update: ");
    scanf("%d", &roll);

    fp = fopen("students.dat", "rb+");
    if (fp == NULL) {
        printf("File not found.\n");
        return;
    }

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll == roll) {
            printf("Enter new marks: ");
            scanf("%f", &s.marks);

            fseek(fp, -sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, fp);

            printf("Record updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found.\n");

    fclose(fp);
}


void deleteStudent() {
    FILE *fp, *temp;
    struct student s;
    int roll, found = 0;

    printf("Enter roll number to delete: ");
    scanf("%d", &roll);

    fp = fopen("students.dat", "rb");
    temp = fopen("temp.dat", "wb");

    if (fp == NULL || temp == NULL) {
        printf("File error.\n");
        return;
    }

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll == roll) {
            found = 1;
        } else {
            fwrite(&s, sizeof(s), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found)
        printf("Student deleted successfully.\n");
    else
        printf("Student not found.\n");
}
