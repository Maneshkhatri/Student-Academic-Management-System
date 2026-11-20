
#include <stdio.h>
#include "course.h"

int courseCodes[100];
int creditHours[100];
int courseCount = 0;

void registerCourse()
{
    int code, credits, i, found = 0;

    if (courseCount >= 100)
    {
        printf("Course limit reached.\n");
        return;
    }

    printf("Enter course code (number): ");

    if (scanf("%d", &code) != 1)
    {
        printf("Invalid course code.\n");
        return;
    }

    for (i = 0; i < courseCount; i++)
    {
        if (courseCodes[i] == code)
        {
            found = 1;
            break;
        }
    }

    if (found == 1)
    {
        printf("Course code already exists.\n");
        return;
    }

    printf("Enter credit hours: ");

    if (scanf("%d", &credits) != 1)
    {
        printf("Invalid credit hours.\n");
        return;
    }

    if (credits <= 0)
    {
        printf("Credit hours must be positive.\n");
        return;
    }

    courseCodes[courseCount] = code;
    creditHours[courseCount] = credits;
    courseCount++;

    printf("Course registered successfully.\n");
}

void viewCourses()
{
    int i;

    if (courseCount == 0)
    {
        printf("No courses registered.\n");
        return;
    }

    for (i = 0; i < courseCount; i++)
    {
        printf("\nCourse Code: %d\n", courseCodes[i]);
        printf("Credit Hours: %d\n", creditHours[i]);
    }
}

void searchCourse()
{
    int code, i, found = 0;

    printf("Enter course code to search: ");

    if (scanf("%d", &code) != 1)
    {
        printf("Invalid course code.\n");
        return;
    }

    for (i = 0; i < courseCount; i++)
    {
        if (courseCodes[i] == code)
        {
            printf("Course found!\n");
            printf("Course Code: %d\n", courseCodes[i]);
            printf("Credit Hours: %d\n", creditHours[i]);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Course not found.\n");
    }
}

void courseMenu()
{
    int choice;

    do
    {
        printf("\n===== COURSE MANAGEMENT =====\n");
        printf("1. Register Course\n");
        printf("2. View Courses\n");
        printf("3. Search Course\n");
        printf("4. Back to Main Menu\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Enter a number.\n");
            return;
        }

        switch (choice)
        {
            case 1:
                registerCourse();
                break;

            case 2:
                viewCourses();
                break;

            case 3:
                searchCourse();
                break;

            case 4:
                printf("Returning to Main Menu.\n");
                break;

            default:
                printf("Invalid choice! Enter 1 to 4.\n");
        }

    } while (choice != 4);
}
