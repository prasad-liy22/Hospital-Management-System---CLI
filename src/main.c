#include <stdio.h>
#include <stdlib.h>

#include "../include/emergency_stack.h"
#include "../include/opd_queue.h"
#include "../include/ward_dll.h"
#include "../include/icu_array.h"
#include "../include/roster_csll.h"
#include "../include/pharmacy_array.h"
#include "../include/treatment_sll.h"
#include "../include/vitals_cdll.h"


int main()
{
    int choice;

    while (1)
    {
        printf("\n=========================================\n");
        printf("       HOSPITAL MANAGEMENT SYSTEM        \n");
        printf("=========================================\n");
        printf("1. Emergency Case Handling\n");
        printf("2. OPD Waiting System\n");
        printf("3. Ward Navigation & Management\n");
        printf("4. ICU Bed Management\n");
        printf("5. Patient Treatment Sequence\n");
        printf("6. Round-Robin Duty Rosters\n");
        printf("7. Endless Vitals Monitor\n");
        printf("8. Pharmacy Inventory\n");
        printf("0. Exit\n");
        printf("-----------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Clear buffer from the main menu input
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        switch (choice)
        {
        case 1:
            runEmergencySystem();
            break;
        case 2:
            handleOPD();
            break;
        case 3:
            runWardSystem();
            break;
         case 4:
            runICUArray();
            break;    
        case 5:
            runTreatment();
            break;
        case 6:
            runRosterSystem();
            break;
        case 7:
            runEndlessVitalsMonitor();
            break;
        case 8:
            runPharmacySystem();
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
