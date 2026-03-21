#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/emergency_stack.h"

struct Patient* top = NULL;

// Clear input buffer
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Add Emergency Patient (Push)
void add_emergency_patient() {
    struct Patient* newNode = (struct Patient*)malloc(sizeof(struct Patient));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter Patient ID: ");
    scanf("%d", &newNode->id);
    clearBuffer();

    printf("Enter Full Name: ");
    scanf(" %[^\n]", newNode->full_name);

    printf("Enter Age: ");
    scanf("%d", &newNode->age);
    clearBuffer();

    printf("Enter Gender (M/F): ");
    scanf(" %c", &newNode->gender);
    clearBuffer();

    printf("Enter Contact Number: ");
    scanf(" %[^\n]", newNode->contact_number);

    printf("Enter Emergency Type: ");
    scanf(" %[^\n]", newNode->emergency_type);

    printf("Enter Severity Level (1-5): ");
    scanf("%d", &newNode->severity_level);

    newNode->next = top;
    top = newNode;

    printf("Emergency patient added!\n");
}

// Treat Patient (Pop)
void treat_patient() {
    if (top == NULL) {
        printf("No emergency patients!\n");
        return;
    }

    struct Patient* temp = top;

    printf("\n Treating Patient:\n");
    printf("ID: %d | Name: %s\n", temp->id, temp->full_name);
    printf("Emergency: %s | Severity: %d\n",
           temp->emergency_type, temp->severity_level);

    top = top->next;
    free(temp);
}

// Display All Patients
void display_emergency_patients() {
    struct Patient* temp = top;

    if (temp == NULL) {
        printf("No emergency patients\n");
        return;
    }

    printf("\n--- Emergency Patients ---\n");

    while (temp != NULL) {
        printf("ID: %d | Name: %s | Age: %d | Gender: %c\n",
               temp->id, temp->full_name, temp->age, temp->gender);

        printf("Contact: %s | Emergency: %s | Severity: %d\n",
               temp->contact_number, temp->emergency_type, temp->severity_level);

        printf("----------------------------------\n");

        temp = temp->next;
    }
}

// Peek Top Patient
void peek_emergency_patient() {
    if (top == NULL) {
        printf("No emergency patients!\n");
        return;
    }

    printf("Next Patient: %d - %s\n", top->id, top->full_name);
}

// Check Empty
int isEmpty() {
    return (top == NULL);
}

// Count Patients
int count_emergency_patients() {
    int count = 0;
    struct Patient* temp = top;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

// Search Patient
void search_emergency_patient() {
    int id;

    printf("Enter Patient ID to search: ");
    scanf("%d", &id);

    struct Patient* temp = top;

    while (temp != NULL) {
        if (temp->id == id) {
            printf("\n Patient Found:\n");
            printf("ID: %d | Name: %s | Age: %d\n",
                   temp->id, temp->full_name, temp->age);
            printf("Emergency: %s | Severity: %d\n",
                   temp->emergency_type, temp->severity_level);
            return;
        }
        temp = temp->next;
    }

    printf("Patient not found!\n");
}

// Clear Stack
void clear_emergency_stack() {
    struct Patient* temp;

    while (top != NULL) {
        temp = top;
        top = top->next;
        free(temp);
    }

    printf("All emergency patients cleared!\n");
}

// Main Menu 
void runEmergencySystem() {
    int choice;

    do {
        printf("\n=== Emergency System Menu ===\n");
        printf("1. Add Emergency Patient (Push)\n");
        printf("2. Treat Patient (Pop)\n");
        printf("3. Display Patients\n");
        printf("4. Peek Top Patient\n");
        printf("5. Count Patients\n");
        printf("6. Search Patient\n");
        printf("7. Clear All Patients\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_emergency_patient();
                break;

            case 2:
                treat_patient();
                break;

            case 3:
                display_emergency_patients();
                break;

            case 4:
                peek_emergency_patient();
                break;

            case 5:
                printf("Total Patients: %d\n", count_emergency_patients());
                break;

            case 6:
                search_emergency_patient();
                break;

            case 7:
                clear_emergency_stack();
                break;

            case 8:
                printf("Exiting system...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 8);
}
