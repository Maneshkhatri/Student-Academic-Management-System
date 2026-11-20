
#include <stdio.h>
#include <string.h>
#include "student.h"

char ids[100][30];
int ages[100];
int count = 0;

void registerStudent()
{
    char id[30];
    int age, i, found = 0;

    if (count >= 100)
    {
        printf("Student limit reached.\n");
        return;
    }

    printf("Enter student ID: ");
    scanf("%29s", id);

    for (i = 0; i < count; i++)
    {
        if (strcmp(ids[i], id) == 0)
        {
            found = 1;
            break;
        }
    }

    if (found == 1)
    {
        printf("This ID already exists.\n");
        return;
    }

    printf("Enter student age: ");

    if (scanf("%d", &age) != 1)
    {
        printf("Invalid age input.\n");
        return;
    }

    if (age <= 0)
    {
        printf("Age must be positive.\n");
        return;
    }

    strcpy(ids[count], id);
    ages[count] = age;
    count++;

    printf("Student registered successfully!\n");
}

void viewStudents()
{
    int i;

    if (count == 0)
    {
        printf("No student records found.\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        printf("\nStudent ID: %s\n", ids[i]);
        printf("Student Age: %d\n", ages[i]);
    }
}

void searchStudent()
{
    char id[30];
    int i, found = 0;

    printf("Enter ID to search: ");
    scanf("%29s", id);

    for (i = 0; i < count; i++)
    {
        if (strcmp(ids[i], id) == 0)
        {
            printf("Student found!\n");
            printf("ID: %s\n", ids[i]);
            printf("Age: %d\n", ages[i]);
            found = 1;
            break;
        }
    }

    if (found == 0)
        printf("Student not found.\n");
}

void updateStudent()
{
    char id[30];
    int age, i, found = 0;

    printf("Enter ID to update: ");
    scanf("%29s", id);

    for (i = 0; i < count; i++)
    {
        if (strcmp(ids[i], id) == 0)
        {
            found = 1;

            printf("Enter new age: ");

            if (scanf("%d", &age) != 1)
            {
                printf("Invalid age input.\n");
                return;
            }

            if (age <= 0)
            {
                printf("Age must be positive.\n");
                return;
            }

            ages[i] = age;
            printf("Student updated successfully!\n");
            break;
        }
    }

    if (found == 0)
        printf("Student not found.\n");
}

void deleteStudent()
{
    char id[30];
    int i, j, found = 0;

    printf("Enter ID to delete: ");
    scanf("%29s", id);

    for (i = 0; i < count; i++)
    {
        if (strcmp(ids[i], id) == 0)
        {
            for (j = i; j < count - 1; j++)
            {
                strcpy(ids[j], ids[j + 1]);
                ages[j] = ages[j + 1];
            }

            count--;
            found = 1;

            printf("Student deleted successfully!\n");
            break;
        }
    }

    if (found == 0)
        printf("Student not found.\n");
}

void studentMenu()
{
    int choice;

    do
    {
        printf("\n===== STUDENT MANAGEMENT =====\n");
        printf("1. Register Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student Age\n");
        printf("5. Delete Student\n");
        printf("6. Back to Main Menu\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input!\n");
            return;
        }

        switch (choice)
        {
            case 1:
                registerStudent();
                break;

            case 2:
                viewStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                printf("Returning to Main Menu.\n");
                break;

            default:
                printf("Invalid choice! Enter 1 to 6.\n");
        }

    } while (choice != 6);
}
