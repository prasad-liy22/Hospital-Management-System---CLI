#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ward_dll.h"

static struct Patient* head = NULL;

// Load patients from file
void loadPatients() {
    FILE *file = fopen("../ward_data.txt", "r");
    if (file == NULL) {
        printf("No existing ward data found. Starting fresh.\n");
        return;
    }

    int bedNo;
    char name[50], diagnosis[100];

    while (fscanf(file, "%d %49s %99s", &bedNo, name, diagnosis) == 3) {
        admitPatient(bedNo, name, diagnosis);
    }

    fclose(file);
    printf("Ward data loaded successfully!\n");
}

// Save patients to file
void savePatients() {
    FILE *file = fopen("ward_data.txt", "w");
    if (file == NULL) {
        printf("Error saving ward data!\n");
        return;
    }

    struct Patient* temp = head;
    while (temp != NULL) {
        fprintf(file, "%d %s %s\n", temp->bedNo, temp->name, temp->diagnosis);
        temp = temp->next;
    }

    fclose(file);
    printf("Ward data saved successfully!\n");
}

// Admit patient
void admitPatient(int bedNo, char name[], char diagnosis[]) {
    struct Patient* newNode = (struct Patient*)malloc(sizeof(struct Patient));

    newNode->bedNo = bedNo;
    strcpy(newNode->name, name);
    strcpy(newNode->diagnosis, diagnosis);
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Patient* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Discharge patient
void dischargePatient() {
    int bedNo;
    printf("\nEnter Bed Number to discharge: ");
    scanf("%d", &bedNo);

    struct Patient* temp = head;

    while (temp != NULL) {
        if (temp->bedNo == bedNo) {

            if (temp->prev == NULL) {
                head = temp->next;
                if (head != NULL)
                    head->prev = NULL;
            } else {
                temp->prev->next = temp->next;
                if (temp->next != NULL)
                    temp->next->prev = temp->prev;
            }

            free(temp);
            printf("Patient discharged successfully!\n");
            savePatients();
            return;
        }
        temp = temp->next;
    }

    printf("Patient not found!\n");
}

// View patients
void viewPatients() {
    struct Patient* temp = head;

    printf("\n---------------------------------------------\n");
    printf("%-5s | %-15s | %-15s\n", "Bed", "Name", "Diagnosis");
    printf("---------------------------------------------\n");

    while (temp != NULL) {
        printf("%-5d | %-15s | %-15s\n", temp->bedNo, temp->name, temp->diagnosis);
        temp = temp->next;
    }

    printf("---------------------------------------------\n");
}

// Forward traversal
void forwardTraversal() {
    struct Patient* temp = head;
    printf("\nForward Traversal:\n");

    while (temp != NULL) {
        printf("Bed %d - %s (%s)\n", temp->bedNo, temp->name, temp->diagnosis);
        temp = temp->next;
    }
}

// Backward traversal
void backwardTraversal() {
    struct Patient* temp = head;

    if (temp == NULL) return;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("\nBackward Traversal:\n");

    while (temp != NULL) {
        printf("Bed %d - %s (%s)\n", temp->bedNo, temp->name, temp->diagnosis);
        temp = temp->prev;
    }
}

// Submenu
void runWardSystem() {
    loadPatients();
    int choice;

    do {
        printf("\n=== WARD MANAGEMENT SUB-MENU ===\n");
        printf("1. Admit Patient\n");
        printf("2. Discharge Patient\n");
        printf("3. View Patients\n");
        printf("4. Forward Traversal\n");
        printf("5. Backward Traversal\n");
        printf("0. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int bedNo;
                char name[50], diagnosis[100];

                printf("Enter Bed Number: ");
                scanf("%d", &bedNo);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Diagnosis: ");
                scanf("%s", diagnosis);

                admitPatient(bedNo, name, diagnosis);
                savePatients();
                printf("Patient admitted successfully!\n");
                break;
            }
            case 2: dischargePatient(); break;
            case 3: viewPatients(); break;
            case 4: forwardTraversal(); break;
            case 5: backwardTraversal(); break;
            case 0: printf("Returning to Main Menu...\n"); savePatients(); break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 0);
}
