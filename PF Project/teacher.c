
#include <stdio.h>
#include <string.h>
#include "teacher.h"

char teacherIDs[100][30];
char teacherNames[100][50];
char teacherSubjects[100][50];

int teacherCount = 0;

char feedbackStudentIDs[100][30];
char feedbackTeacherIDs[100][30];
char feedbackMessages[100][200];

int feedbackCount = 0;

void addTeacher()
{
    if (teacherCount >= 100)
    {
        printf("\nTeacher records are full!\n");
        return;
    }

    printf("\nEnter Teacher ID: ");
    scanf("%29s", teacherIDs[teacherCount]);

    for (int i = 0; i < teacherCount; i++)
    {
        if (strcmp(teacherIDs[i], teacherIDs[teacherCount]) == 0)
        {
            printf("\nTeacher ID already exists!\n");
            return;
        }
    }

    printf("Enter Teacher Name: ");
    scanf(" %49[^\n]", teacherNames[teacherCount]);

    printf("Enter Subject: ");
    scanf(" %49[^\n]", teacherSubjects[teacherCount]);

    teacherCount++;

    printf("\nTeacher added successfully!\n");
}

void viewTeachers()
{
    if (teacherCount == 0)
    {
        printf("\nNo teacher records found!\n");
        return;
    }

    printf("\n===== TEACHER RECORDS =====\n");

    for (int i = 0; i < teacherCount; i++)
    {
        printf("\nTeacher ID: %s", teacherIDs[i]);
        printf("\nName: %s", teacherNames[i]);
        printf("\nSubject: %s\n", teacherSubjects[i]);
    }
}

void searchTeacher()
{
    char searchID[30];
    int found = 0;

    printf("\nEnter Teacher ID: ");
    scanf("%29s", searchID);

    for (int i = 0; i < teacherCount; i++)
    {
        if (strcmp(teacherIDs[i], searchID) == 0)
        {
            printf("\nTeacher Found!\n");
            printf("Teacher ID: %s\n", teacherIDs[i]);
            printf("Name: %s\n", teacherNames[i]);
            printf("Subject: %s\n", teacherSubjects[i]);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nTeacher not found!\n");
    }
}

void addFeedback()
{
    if (feedbackCount >= 100)
    {
        printf("\nFeedback records are full!\n");
        return;
    }

    char teacherID[30];

    printf("\nEnter Student ID: ");
    scanf("%29s", feedbackStudentIDs[feedbackCount]);

    printf("Enter Teacher ID: ");
    scanf("%29s", teacherID);

    int found = 0;

    for (int i = 0; i < teacherCount; i++)
    {
        if (strcmp(teacherIDs[i], teacherID) == 0)
        {
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nTeacher ID does not exist!\n");
        return;
    }

    strcpy(feedbackTeacherIDs[feedbackCount], teacherID);

    printf("Enter Feedback: ");
    scanf(" %199[^\n]", feedbackMessages[feedbackCount]);

    feedbackCount++;

    printf("\nFeedback submitted successfully!\n");
}

void viewFeedback()
{
    if (feedbackCount == 0)
    {
        printf("\nNo feedback records found!\n");
        return;
    }

    printf("\n===== STUDENT FEEDBACK =====\n");

    for (int i = 0; i < feedbackCount; i++)
    {
        printf("\nStudent ID: %s", feedbackStudentIDs[i]);
        printf("\nTeacher ID: %s", feedbackTeacherIDs[i]);
        printf("\nFeedback: %s\n", feedbackMessages[i]);
    }
}

void teacherMenu()
{
    int choice;

    do
    {
        printf("\n===== TEACHER MANAGEMENT =====\n");
        printf("1. Add Teacher\n");
        printf("2. View Teachers\n");
        printf("3. Search Teacher\n");
        printf("4. Submit Student Feedback\n");
        printf("5. View Feedback\n");
        printf("6. Return to Main Menu\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addTeacher();
                break;

            case 2:
                viewTeachers();
                break;

            case 3:
                searchTeacher();
                break;

            case 4:
                addFeedback();
                break;

            case 5:
                viewFeedback();
                break;

            case 6:
                printf("\nReturning to Main Menu...\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while (choice != 6);
}
