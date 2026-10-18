
#include <stdio.h>
#include <string.h>

int main()
{
    char ids[100][30];
    int ages[100];

    int count = 0;
    int choice, age, i, j, found;
    char id[30];

    do
    {
        printf("\n===== STUDENT MANAGEMENT =====\n");
        printf("1. Register Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student Age\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid choice!\n");
            return 0;
        }

        switch (choice)
        {
            case 1:
                if (count >= 100)
                {
                    printf("Student limit reached.\n");
                    break;
                }

                printf("Enter student ID: ");
                scanf("%29s", id);

                found = 0;

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
                    break;
                }

                printf("Enter student age: ");

                if (scanf("%d", &age) != 1)
                {
                    printf("Invalid age input.\n");
                    return 0;
                }

                if (age <= 0)
                {
                    printf("Age must be positive.\n");
                    break;
                }

                strcpy(ids[count], id);
                ages[count] = age;
                count++;

                printf("Student registered successfully!\n");
                break;

            case 2:
                if (count == 0)
                {
                    printf("No student records found.\n");
                }
                else
                {
                    for (i = 0; i < count; i++)
                    {
                        printf("\nStudent ID: %s\n", ids[i]);
                        printf("Student Age: %d\n", ages[i]);
                    }
                }
                break;

            case 3:
                printf("Enter ID to search: ");
                scanf("%29s", id);

                found = 0;

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

                break;

            case 4:
                printf("Enter ID to update: ");
                scanf("%29s", id);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (strcmp(ids[i], id) == 0)
                    {
                        printf("Enter new age: ");

                        if (scanf("%d", &age) != 1)
                        {
                            printf("Invalid age input.\n");
                            return 0;
                        }

                        if (age <= 0)
                        {
                            printf("Age must be positive.\n");
                            break;
                        }

                        ages[i] = age;
                        printf("Student updated successfully!\n");
                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                    printf("Student not found or age invalid.\n");

                break;

            case 5:
                printf("Enter ID to delete: ");
                scanf("%29s", id);

                found = 0;

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

                break;

            case 6:
                printf("Student menu closed.\n");
                break;

            default:
                printf("Invalid choice! Enter 1 to 6.\n");
        }

    } while (choice != 6);

    return 0;
}
