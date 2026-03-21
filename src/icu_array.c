#include <stdio.h> 
#define TOTAL_BEDS 10 
#include "../include/icu_array.h"

void runICUArray() { 
// Initialize all 10 beds to 0 (Vacant) 
int icu_beds[TOTAL_BEDS] = {0}; 
int choice, bedNum; 
 
    printf("--- ICU Bed Management System ---\n"); 
 
    while(1) { 
        printf("\n1. View All Beds\n2. Admit Patient\n3. Discharge Patient\n4. Exit\n"); 
        printf("Enter choice: "); 
        scanf("%d", &choice); 
 
        switch(choice) { 
            case 1: 
                displayBeds(icu_beds); 
                break; 
            case 2: 
                printf("Enter Bed Number (0-9) to occupy: "); 
                scanf("%d", &bedNum); 
                admitPatientICU(icu_beds, bedNum); 
                break; 
            case 3: 
                printf("Enter Bed Number (0-9) to vacate: "); 
                scanf("%d", &bedNum); 
                dischargePatientICU(icu_beds, bedNum); 
                break; 
            case 4: 
                return; 
            default: 
                printf("Invalid choice!\n"); 
        } 
    } 
} 
 
void displayBeds(int beds[]) { 
    printf("\nICU Status:\n"); 
    for(int i = 0; i < TOTAL_BEDS; i++) { 
        printf("Bed [%d]: %s\n", i, (beds[i] == 0) ? "Vacant" : "OCCUPIED"); 
    } 
} 
 
void admitPatientICU(int beds[], int bedNumber) { 
    if(bedNumber >= 0 && bedNumber < TOTAL_BEDS) { 
        if(beds[bedNumber] == 0) { 
            beds[bedNumber] = 1; 
            printf("Patient admitted to Bed %d.\n", bedNumber); 
        } else { 
            printf("Error: Bed %d is already occupied!\n", bedNumber); 
        } 
    } else { 
        printf("Invalid Bed Number!\n"); 
    } 
} 
 
void dischargePatientICU(int beds[], int bedNumber) { 
    if(bedNumber >= 0 && bedNumber < TOTAL_BEDS) { 
        beds[bedNumber] = 0; 
        printf("Bed %d is now vacant.\n", bedNumber); 
    } else { 
        printf("Invalid Bed Number!\n"); 
    } 
}