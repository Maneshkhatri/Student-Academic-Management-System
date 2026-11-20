
#include <stdio.h>
#include <string.h>
#include "fees.h"

char feeStudentIDs[100][30];
float totalFees[100];
float paidFees[100];

int feeCount = 0;

void addFeeRecord()
{
    if (feeCount >= 100)
    {
        printf("\nFee records are full!\n");
        return;
    }

    printf("\nEnter Student ID: ");
    scanf("%29s", feeStudentIDs[feeCount]);

    printf("Enter Total Fee: ");
    scanf("%f", &totalFees[feeCount]);

    printf("Enter Paid Fee: ");
    scanf("%f", &paidFees[feeCount]);

    if (totalFees[feeCount] <= 0 ||
        paidFees[feeCount] < 0 ||
        paidFees[feeCount] > totalFees[feeCount])
    {
        printf("\nInvalid fee information!\n");
        return;
    }

    feeCount++;

    printf("\nFee record added successfully!\n");
}

void viewFeeRecords()
{
    if (feeCount == 0)
    {
        printf("\nNo fee records found!\n");
        return;
    }

    printf("\n===== ALL FEE RECORDS =====\n");

    for (int i = 0; i < feeCount; i++)
    {
        float remaining = totalFees[i] - paidFees[i];

        printf("\nStudent ID: %s", feeStudentIDs[i]);
        printf("\nTotal Fee: %.2f", totalFees[i]);
        printf("\nPaid Fee: %.2f", paidFees[i]);
        printf("\nRemaining Fee: %.2f", remaining);

        if (remaining == 0)
            printf("\nStatus: PAID\n");
        else
            printf("\nStatus: PENDING\n");
    }
}

void searchFeeRecord()
{
    char searchID[30];
    int found = 0;

    printf("\nEnter Student ID: ");
    scanf("%29s", searchID);

    for (int i = 0; i < feeCount; i++)
    {
        if (strcmp(feeStudentIDs[i], searchID) == 0)
        {
            float remaining = totalFees[i] - paidFees[i];

            printf("\n===== FEE DETAILS =====\n");
            printf("Student ID: %s\n", feeStudentIDs[i]);
            printf("Total Fee: %.2f\n", totalFees[i]);
            printf("Paid Fee: %.2f\n", paidFees[i]);
            printf("Remaining Fee: %.2f\n", remaining);

            if (remaining == 0)
                printf("Status: PAID\n");
            else
                printf("Status: PENDING\n");

            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nFee record not found!\n");
}

void updatePaidFee()
{
    char searchID[30];
    int found = 0;

    printf("\nEnter Student ID: ");
    scanf("%29s", searchID);

    for (int i = 0; i < feeCount; i++)
    {
        if (strcmp(feeStudentIDs[i], searchID) == 0)
        {
            float newPayment;

            printf("Enter additional payment: ");
            scanf("%f", &newPayment);

            if (newPayment <= 0 ||
                paidFees[i] + newPayment > totalFees[i])
            {
                printf("\nInvalid payment amount!\n");
                return;
            }

            paidFees[i] += newPayment;

            printf("\nPayment updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nFee record not found!\n");
}

void feesMenu()
{
    int choice;

    do
    {
        printf("\n===== FEES MANAGEMENT =====\n");
        printf("1. Add Fee Record\n");
        printf("2. View All Fee Records\n");
        printf("3. Search Fee Record\n");
        printf("4. Update Paid Fee\n");
        printf("5. Return to Main Menu\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addFeeRecord();
                break;

            case 2:
                viewFeeRecords();
                break;

            case 3:
                searchFeeRecord();
                break;

            case 4:
                updatePaidFee();
                break;

            case 5:
                printf("\nReturning to Main Menu...\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while (choice != 5);
}
