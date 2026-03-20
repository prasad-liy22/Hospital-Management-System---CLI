#include <stdio.h>
#include <stdlib.h>

#include "emergency_stack.h"
#include "opd_queue.h"
#include "roster_csll.h"
#include "pharmacy_array.h"

int main()
{
    int choice;

    while (1)
    {
        printf("\n=========================================\n");
        printf("       HOSPITAL MANAGEMENT SYSTEM        \n");
        printf("=========================================\n");
        printf("1. Emergency Case Handling (Stack)\n");
        printf("2. OPD Waiting System (Queue)\n");
        printf("6. Round Robin Duty Roster System (Circular Singly Linked List)");
        printf("8. Pharmacy Inventory (Array)\n");
        printf("0. Exit\n");
        printf("-----------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // handleEmergency();
            break;
        case 2:
            // handleOPD();
            break;
        case 6:
            runRosterSystem();
            break;
        case 8:
            // displayInventory();
            break;
        case 0:
            printf("Exiting system...\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
