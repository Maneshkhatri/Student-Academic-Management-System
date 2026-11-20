#include <stdio.h>
#include <string.h>
#include "Marks.h"

char markStudentIDs[100][30];

int quiz[100];
int assignment[100];
int midterm[100];
int finalExam[100];
int total[100];

int marksCount = 0;

void enterMarks()
{
    char id[30];
    int found = 0;

    if (marksCount >= 100)
    {
        printf("\nMarks record limit reached.\n");
        return;
    }

    printf("\nEnter Student ID: ");
    scanf("%29s", id);

    for (int i = 0; i < marksCount; i++)
    {
        if (strcmp(markStudentIDs[i], id) == 0)
        {
            found = 1;
            break;
        }
    }

    if (found)
    {
        printf("\nMarks already entered for this ID.\n");
        return;
    }

    printf("Enter Quiz Marks (0-100): ");
    scanf("%d", &quiz[marksCount]);

    printf("Enter Assignment Marks (0-100): ");
    scanf("%d", &assignment[marksCount]);

    printf("Enter Midterm Marks (0-100): ");
    scanf("%d", &midterm[marksCount]);

    printf("Enter Final Exam Marks (0-100): ");
    scanf("%d", &finalExam[marksCount]);

    if (quiz[marksCount] < 0 || quiz[marksCount] > 100 ||
        assignment[marksCount] < 0 || assignment[marksCount] > 100 ||
        midterm[marksCount] < 0 || midterm[marksCount] > 100 ||
        finalExam[marksCount] < 0 || finalExam[marksCount] > 100)
    {
        printf("\nMarks must be between 0 and 100.\n");
        return;
    }

    strcpy(markStudentIDs[marksCount], id);

    total[marksCount] = quiz[marksCount] +
                        assignment[marksCount] +
                        midterm[marksCount] +
                        finalExam[marksCount];

    marksCount++;

    printf("\nMarks entered successfully!\n");
}

void displayResult(int i)
{
    float percentage = total[i] / 4.0f;

    printf("\nStudent ID: %s\n", markStudentIDs[i]);
    printf("Quiz: %d\n", quiz[i]);
    printf("Assignment: %d\n", assignment[i]);
    printf("Midterm: %d\n", midterm[i]);
    printf("Final Exam: %d\n", finalExam[i]);
    printf("Total: %d / 400\n", total[i]);
    printf("Percentage: %.2f%%\n", percentage);

    if (percentage >= 90)
        printf("Grade: A\n");
    else if (percentage >= 80)
        printf("Grade: B\n");
    else if (percentage >= 70)
        printf("Grade: C\n");
    else if (percentage >= 60)
        printf("Grade: D\n");
    else
        printf("Grade: F\n");
}

void viewAllResults()
{
    if (marksCount == 0)
    {
        printf("\nNo results available.\n");
        return;
    }

    printf("\n===== ALL STUDENT RESULTS =====\n");

    for (int i = 0; i < marksCount; i++)
    {
        displayResult(i);
    }
}

void searchResult()
{
    char searchID[30];
    int found = 0;

    printf("\nEnter Student ID to search: ");
    scanf("%29s", searchID);

    for (int i = 0; i < marksCount; i++)
    {
        if (strcmp(markStudentIDs[i], searchID) == 0)
        {
            displayResult(i);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nResult not found.\n");
    }
}

void marksMenu()
{
    int choice;

    do
    {
        printf("\n===== MARKS MANAGEMENT =====\n");
        printf("1. Enter Marks\n");
        printf("2. View All Results\n");
        printf("3. Search Result\n");
        printf("4. Return to Main Menu\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enterMarks();
                break;

            case 2:
                viewAllResults();
                break;

            case 3:
                searchResult();
                break;

            case 4:
                printf("\nReturning to Main Menu...\n");
                break;

            default:
                printf("\nInvalid choice! Enter 1 to 4.\n");
        }

    } while (choice != 4);
}
