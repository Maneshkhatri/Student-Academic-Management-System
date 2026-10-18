
#include <stdio.h>

int main()
{
    int ids[100];
    int quiz[100];
    int assignment[100];
    int midterm[100];
    int finalExam[100];
    int total[100];

    int count = 0;
    int choice, id, i, found;
    float percentage;

    do
    {
        printf("\n===== MARKS MANAGEMENT =====\n");
        printf("1. Enter Marks\n");
        printf("2. View All Results\n");
        printf("3. Search Result\n");
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
                    printf("Marks record limit reached.\n");
                    break;
                }

                printf("Enter student ID: ");
                if (scanf("%d", &id) != 1)
                {
                    printf("Invalid student ID.\n");
                    return 0;
                }

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (ids[i] == id)
                    {
                        found = 1;
                        break;
                    }
                }

                if (found == 1)
                {
                    printf("Marks already entered for this ID.\n");
                    break;
                }

                printf("Enter quiz marks (0-100): ");
                if (scanf("%d", &quiz[count]) != 1)
                {
                    printf("Invalid marks input.\n");
                    return 0;
                }

                printf("Enter assignment marks (0-100): ");
                if (scanf("%d", &assignment[count]) != 1)
                {
                    printf("Invalid marks input.\n");
                    return 0;
                }

                printf("Enter midterm marks (0-100): ");
                if (scanf("%d", &midterm[count]) != 1)
                {
                    printf("Invalid marks input.\n");
                    return 0;
                }

                printf("Enter final exam marks (0-100): ");
                if (scanf("%d", &finalExam[count]) != 1)
                {
                    printf("Invalid marks input.\n");
                    return 0;
                }

                if (quiz[count] < 0 || quiz[count] > 100 ||
                    assignment[count] < 0 || assignment[count] > 100 ||
                    midterm[count] < 0 || midterm[count] > 100 ||
                    finalExam[count] < 0 || finalExam[count] > 100)
                {
                    printf("Marks must be between 0 and 100.\n");
                    break;
                }

                ids[count] = id;

                total[count] = quiz[count] +
                               assignment[count] +
                               midterm[count] +
                               finalExam[count];

                count++;

                printf("Marks entered successfully.\n");
                break;

            case 2:
                if (count == 0)
                {
                    printf("No results available.\n");
                }
                else
                {
                    for (i = 0; i < count; i++)
                    {
                        percentage = total[i] / 4.0f;

                        printf("\nStudent ID: %d\n", ids[i]);
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
                }
                break;

            case 3:
                printf("Enter student ID to search: ");
                if (scanf("%d", &id) != 1)
                {
                    printf("Invalid student ID.\n");
                    return 0;
                }

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (ids[i] == id)
                    {
                        percentage = total[i] / 4.0f;

                        printf("Student ID: %d\n", ids[i]);
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

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                    printf("Result not found.\n");

                break;

            case 4:
                printf("Marks menu closed.\n");
                break;

            default:
                printf("Invalid choice! Enter 1 to 4.\n");
        }

    } while (choice != 4);

    return 0;
}
