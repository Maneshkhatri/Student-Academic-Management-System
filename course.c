#include <stdio.h>

int main()
{
    int courseCodes[100];
    int creditHours[100];
    int count = 0;
    int choice, code, credits, i, found;

    do
    {
        printf("\n===== COURSE MANAGEMENT =====\n");
        printf("1. Register Course\n");
        printf("2. View Courses\n");
        printf("3. Search Course\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        fflush(stdout);

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Enter a number.\n");
            return 0;
        }

        switch (choice)
        {
            case 1:
                if (count >= 100)
                {
                    printf("Course limit reached.\n");
                    break;
                }

                printf("Enter course code (number): ");
                if (scanf("%d", &code) != 1)
                {
                    printf("Invalid course code.\n");
                    return 0;
                }

                found = 0;

                for (i = 0; i < count; i++)
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
                    break;
                }

                printf("Enter credit hours: ");
                if (scanf("%d", &credits) != 1)
                {
                    printf("Invalid credit hours.\n");
                    return 0;
                }

                if (credits <= 0)
                {
                    printf("Credit hours must be positive.\n");
                    break;
                }

                courseCodes[count] = code;
                creditHours[count] = credits;
                count++;

                printf("Course registered successfully.\n");
                break;

            case 2:
                if (count == 0)
                {
                    printf("No courses registered.\n");
                }
                else
                {
                    for (i = 0; i < count; i++)
                    {
                        printf("\nCourse Code: %d\n", courseCodes[i]);
                        printf("Credit Hours: %d\n", creditHours[i]);
                    }
                }
                break;

            case 3:
                printf("Enter course code to search: ");
                if (scanf("%d", &code) != 1)
                {
                    printf("Invalid course code.\n");
                    return 0;
                }

                found = 0;

                for (i = 0; i < count; i++)
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
                    printf("Course not found.\n");

                break;

            case 4:
                printf("Course menu closed.\n");
                break;

            default:
                printf("Invalid choice! Enter 1 to 4.\n");
        }

    } while (choice != 4);

    return 0;
}
