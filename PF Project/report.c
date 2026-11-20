#include <stdio.h>
#include <string.h>

#include "report.h"

// Student module data
extern char ids[100][30];
extern int ages[100];
extern int count;

// Course module data
extern int courseCodes[100];
extern int creditHours[100];
extern int courseCount;

// Attendance module data
extern char studentIDs[100][30];
extern int totalClasses[100];
extern int presentClasses[100];
extern int attendanceCount;

// Fees module data
extern char feeStudentIDs[100][30];
extern float totalFees[100];
extern float paidFees[100];
extern int feeCount;

// GPA module data
extern char gpaStudentIDs[100][30];
extern float studentGPAs[100];
extern int gpaCount;

void generateReport()
{
    char searchID[30];
    int found = 0;

    printf("\nEnter Student ID: ");
    scanf("%29s", searchID);

    printf("\n====================================\n");
    printf("          STUDENT ACADEMIC REPORT\n");
    printf("====================================\n");

    // Student information
    for (int i = 0; i < count; i++)
    {
        if (strcmp(ids[i], searchID) == 0)
        {
            printf("\nStudent ID: %s", ids[i]);
            printf("\nAge: %d\n", ages[i]);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nStudent record not found!\n");
        return;
    }

    // Course information
    printf("\n--- Registered Courses ---\n");

    if (courseCount == 0)
    {
        printf("No course records available.\n");
    }
    else
    {
        for (int i = 0; i < courseCount; i++)
        {
            printf("Course Code: %d | Credit Hours: %d\n",
                   courseCodes[i], creditHours[i]);
        }
    }

    // Attendance information
    printf("\n--- Attendance Details ---\n");

    found = 0;

    for (int i = 0; i < attendanceCount; i++)
    {
        if (strcmp(studentIDs[i], searchID) == 0)
        {
            float percentage =
                (float)presentClasses[i] / totalClasses[i] * 100;

            printf("Total Classes: %d\n", totalClasses[i]);
            printf("Present Classes: %d\n", presentClasses[i]);
            printf("Attendance: %.2f%%\n", percentage);

            found = 1;
            break;
        }
    }

    if (!found)
        printf("Attendance record not available.\n");

    // Fee information
    printf("\n--- Fee Details ---\n");

    found = 0;

    for (int i = 0; i < feeCount; i++)
    {
        if (strcmp(feeStudentIDs[i], searchID) == 0)
        {
            printf("Total Fee: %.2f\n", totalFees[i]);
            printf("Paid Fee: %.2f\n", paidFees[i]);
            printf("Remaining Fee: %.2f\n",
                   totalFees[i] - paidFees[i]);

            found = 1;
            break;
        }
    }

    if (!found)
        printf("Fee record not available.\n");

    // GPA information
    printf("\n--- GPA Details ---\n");

    found = 0;

    for (int i = 0; i < gpaCount; i++)
    {
        if (strcmp(gpaStudentIDs[i], searchID) == 0)
        {
            printf("Semester GPA: %.2f\n", studentGPAs[i]);

            found = 1;
            break;
        }
    }

    if (!found)
        printf("GPA record not available.\n");

    printf("\n====================================\n");
    printf("          END OF REPORT\n");
    printf("====================================\n");
}

void reportMenu()
{
    int choice;

    do
    {
        printf("\n===== ACADEMIC REPORT =====\n");
        printf("1. Generate Student Report\n");
        printf("2. Return to Main Menu\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                generateReport();
                break;

            case 2:
                printf("\nReturning to Main Menu...\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while (choice != 2);
}
