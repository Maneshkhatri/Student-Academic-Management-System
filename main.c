#include <stdio.h>
int main()
{
    int choice;

    do
    {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Student Management\n");
        printf("2. Course Management\n");
        printf("3. Marks Management\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Please enter a number.\n");
            return 0;
        }

        switch (choice)
        {
            case 1:
                printf("Student Management selected.\n");
                break;

            case 2:
                printf("Course Management selected.\n");
                break;

            case 3:
                printf("Marks Management selected.\n");
                break;

            case 4:
                printf("Program closed.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 4);

    return 0;
}
