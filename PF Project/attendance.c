
#include <stdio.h>
#include <string.h>
#include "attendance.h"

char studentIDs[100][30];
int totalClasses[100];
int presentClasses[100];

int attendanceCount = 0;

void addAttendance()
{
    if (attendanceCount >= 100)
    {
        printf("\nAttendance records are full!\n");
        return;
    }

    printf("\nEnter Student ID: ");
    scanf("%29s", studentIDs[attendanceCount]);

    printf("Enter Total Classes: ");
    scanf("%d", &totalClasses[attendanceCount]);

    printf("Enter Present Classes: ");
    scanf("%d", &presentClasses[attendanceCount]);

    if (totalClasses[attendanceCount] <= 0 ||
        presentClasses[attendanceCount] < 0 ||
        presentClasses[attendanceCount] > totalClasses[attendanceCount])
    {
        printf("\nInvalid attendance information!\n");
        return;
    }

    attendanceCount++;

    printf("\nAttendance record added successfully!\n");
}

void viewAttendance()
{
    if (attendanceCount == 0)
    {
        printf("\nNo attendance records found!\n");
        return;
    }

    printf("\n--- Attendance Records ---\n");

    for (int i = 0; i < attendanceCount; i++)
    {
        float percentage =
            (float)presentClasses[i] / totalClasses[i] * 100;

        printf("\nStudent ID: %s", studentIDs[i]);
        printf("\nTotal Classes: %d", totalClasses[i]);
        printf("\nPresent Classes: %d", presentClasses[i]);
        printf("\nAttendance: %.2f%%\n", percentage);
    }
}

void searchAttendance()
{
    char searchID[30];
    int found = 0;

    printf("\nEnter Student ID to search: ");
    scanf("%29s", searchID);

    for (int i = 0; i < attendanceCount; i++)
    {
        if (strcmp(studentIDs[i], searchID) == 0)
        {
            float percentage =
                (float)presentClasses[i] / totalClasses[i] * 100;

            printf("\nAttendance Record Found!");
            printf("\nStudent ID: %s", studentIDs[i]);
            printf("\nTotal Classes: %d", totalClasses[i]);
            printf("\nPresent Classes: %d", presentClasses[i]);
            printf("\nAttendance Percentage: %.2f%%\n", percentage);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nStudent attendance record not found!\n");
    }
}

void attendanceMenu()
{
    int choice;

    do
    {
        printf("\n===== ATTENDANCE MANAGEMENT =====\n");
        printf("1. Add Attendance\n");
        printf("2. View Attendance\n");
        printf("3. Search Attendance\n");
        printf("4. Return to Main Menu\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addAttendance();
                break;

            case 2:
                viewAttendance();
                break;

            case 3:
                searchAttendance();
                break;

            case 4:
                printf("\nReturning to Main Menu...\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while (choice != 4);
}
