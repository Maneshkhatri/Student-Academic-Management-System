
#include <stdio.h>
#include <string.h>
#include "gpa.h"

char gpaStudentIDs[100][30];
float studentGPAs[100];

int gpaCount = 0;

void calculateGPA()
{
    if (gpaCount >= 100)
    {
        printf("\nGPA records are full!\n");
        return;
    }

    char studentID[30];
    int courses;
    float totalPoints = 0;
    int totalCredits = 0;

    printf("\nEnter Student ID: ");
    scanf("%29s", studentID);

    for (int i = 0; i < gpaCount; i++)
    {
        if (strcmp(gpaStudentIDs[i], studentID) == 0)
        {
            printf("\nGPA record already exists for this student!\n");
            return;
        }
    }

    printf("Enter number of courses: ");
    scanf("%d", &courses);

    if (courses <= 0)
    {
        printf("\nInvalid number of courses!\n");
        return;
    }

    for (int i = 0; i < courses; i++)
    {
        float gradePoints;
        int creditHours;

        printf("\nCourse %d\n", i + 1);

        printf("Enter Grade Points (0.00 - 4.00): ");
        scanf("%f", &gradePoints);

        printf("Enter Credit Hours: ");
        scanf("%d", &creditHours);

        if (gradePoints < 0 || gradePoints > 4 ||
            creditHours <= 0)
        {
            printf("\nInvalid course information!\n");
            return;
        }

        totalPoints += gradePoints * creditHours;
        totalCredits += creditHours;
    }

    studentGPAs[gpaCount] = totalPoints / totalCredits;

    strcpy(gpaStudentIDs[gpaCount], studentID);

    printf("\nSemester GPA: %.2f\n", studentGPAs[gpaCount]);

    gpaCount++;
}

void viewGPARecords()
{
    if (gpaCount == 0)
    {
        printf("\nNo GPA records found!\n");
        return;
    }

    printf("\n===== GPA RECORDS =====\n");

    for (int i = 0; i < gpaCount; i++)
    {
        printf("\nStudent ID: %s", gpaStudentIDs[i]);
        printf("\nGPA: %.2f\n", studentGPAs[i]);
    }
}

void searchGPA()
{
    char searchID[30];
    int found = 0;

    printf("\nEnter Student ID: ");
    scanf("%29s", searchID);

    for (int i = 0; i < gpaCount; i++)
    {
        if (strcmp(gpaStudentIDs[i], searchID) == 0)
        {
            printf("\nStudent ID: %s", gpaStudentIDs[i]);
            printf("\nSemester GPA: %.2f\n", studentGPAs[i]);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nGPA record not found!\n");
    }
}

void gpaMenu()
{
    int choice;

    do
    {
        printf("\n===== GPA MANAGEMENT =====\n");
        printf("1. Calculate GPA\n");
        printf("2. View GPA Records\n");
        printf("3. Search GPA\n");
        printf("4. Return to Main Menu\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                calculateGPA();
                break;

            case 2:
                viewGPARecords();
                break;

            case 3:
                searchGPA();
                break;

            case 4:
                printf("\nReturning to Main Menu...\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while (choice != 4);
}
