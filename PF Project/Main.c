#include <stdio.h>

#include "student.h"
#include "Course.h"
#include "attendance.h"
#include "fees.h"
#include "gpa.h"
#include "teacher.h"
#include "report.h"
#include "Marks.h"

int main()
{
    int choice;

    do
    {
        printf("\n====================================\n");
        printf(" STUDENT ACADEMIC MANAGEMENT SYSTEM\n");
        printf("====================================\n");

        printf("1. Student Management\n");
        printf("2. Course Management\n");
        printf("3. Attendance Management\n");
        printf("4. Marks Management\n");
        printf("5. Fees Management\n");
        printf("6. GPA Management\n");
        printf("7. Teacher Management\n");
        printf("8. Academic Report\n");
        printf("0. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                studentMenu();
                break;

            case 2:
                courseMenu();
                break;

            case 3:
                attendanceMenu();
                break;

            case 4:
                marksMenu();
                break;

            case 5:
                feesMenu();
                break;

            case 6:
                gpaMenu();
                break;

            case 7:
                teacherMenu();
                break;

            case 8:
                reportMenu();
                break;

            case 0:
                printf("\nThank you for using Student Academic Management System!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}
