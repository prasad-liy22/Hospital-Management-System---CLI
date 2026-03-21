#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/opd_queue.h" 

struct OPDPatient* front = NULL;
struct OPDPatient* rear = NULL;

// Global variable to track the next available ID
int next_patient_id = 1;

// Helper function to clear the input buffer to prevent skipping inputs
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// 1. Enqueue with Input Validation
void enqueue() {
    struct OPDPatient* newNode = (struct OPDPatient*)malloc(sizeof(struct OPDPatient));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("\n--- Entering Patient Details ---\n");

    // Auto-assign the ID and increment the counter
    newNode->id = next_patient_id++;
    printf("Assigned Patient ID: %d\n", newNode->id);

    // Get Full Name
    printf("Enter Full Name: ");
    fgets(newNode->full_name, sizeof(newNode->full_name), stdin);
    newNode->full_name[strcspn(newNode->full_name, "\n")] = 0;

    // Validate Age (Must be a number between 0 and 120)
    while (1) {
        printf("Enter Age: ");
        if (scanf("%d", &newNode->age) == 1 && newNode->age >= 0 && newNode->age <= 120) {
            clearBuffer();
            break;
        }
        printf("  -> Invalid age! Please enter a realistic number between 0 and 120.\n\n");
        clearBuffer();
    }

    // Validate Gender (Must be M, F, or O)
    while (1) {
        printf("Enter Gender (M/F/O): ");
        scanf("%c", &newNode->gender);
        clearBuffer();
        newNode->gender = toupper(newNode->gender); 
        if (newNode->gender == 'M' || newNode->gender == 'F' || newNode->gender == 'O') {
            break;
        }
        printf("  -> Invalid gender! Please enter M for Male, F for Female, or O for Other.\n\n");
    }

    // Validate Contact Number
    while (1) {
        printf("Enter Contact Number (e.g., 0712345678): ");
        fgets(newNode->contact_number, sizeof(newNode->contact_number), stdin);
        newNode->contact_number[strcspn(newNode->contact_number, "\n")] = 0;

        if (strlen(newNode->contact_number) == 10) {
            break;
        }
        printf("  -> Invalid number! Please enter a valid contact number.\n\n");
    }

    // Get Symptoms
    printf("Enter Symptoms: ");
    fgets(newNode->symptoms, sizeof(newNode->symptoms), stdin);
    newNode->symptoms[strcspn(newNode->symptoms, "\n")] = 0;

    newNode->next = NULL;

    // Queue linking logic
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("\n>>> Patient '%s' added to OPD queue successfully. <<<\n", newNode->full_name);
}

// 2. Dequeue
void dequeue() {
    if (front == NULL) {
        printf("\nNo patients currently in the queue.\n");
        return;
    }

    struct OPDPatient* temp = front;
    printf("\n[TREATMENT ROOM] Calling Patient ID %d: %s\n", temp->id, temp->full_name);
    printf("  Symptoms reported: %s\n", temp->symptoms);

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

// 3. Peek
void peek() {
    if (front == NULL) {
        printf("\nQueue is empty.\n");
        return;
    }
    printf("\nNext in line: ID %d - %s (Age: %d, Symptoms: %s)\n",
           front->id, front->full_name, front->age, front->symptoms);
}

// 4. Display
void display() {
    if (front == NULL) {
        printf("\nQueue is empty.\n");
        return;
    }

    struct OPDPatient* temp = front;
    printf("\n=== Current OPD Waiting List ===\n");
    int position = 1;
    while (temp != NULL) {
        printf("%d. [ID: %d] %s | Age: %d | Gender: %c | Contact: %s \n   Symptoms: %s\n",
               position, temp->id, temp->full_name, temp->age, temp->gender, temp->contact_number, temp->symptoms);
        temp = temp->next;
        position++;
    }
    printf("\n");
}

// 5. Search for a patient by their ID
void searchPatientByID() {
    if (front == NULL) {
        printf("\nQueue is empty. No patients to search.\n");
        return;
    }

    int searchID;
    printf("\nEnter Patient ID to search: ");
    if (scanf("%d", &searchID) != 1) {
        clearBuffer();
        printf("  -> Invalid input! Please enter a numeric ID.\n");
        return;
    }
    clearBuffer();

    struct OPDPatient* temp = front;
    int position = 1;
    int found = 0;

    // Traverse the linked list
    while (temp != NULL) {
        if (temp->id == searchID) {
            printf("\n--- Patient Found! ---\n");
            printf("Position in Queue: %d\n", position);
            printf("ID: %d | Name: %s | Age: %d | Gender: %c\n",
                   temp->id, temp->full_name, temp->age, temp->gender);
            printf("Contact: %s | Symptoms: %s\n",
                   temp->contact_number, temp->symptoms);
            printf("\n");
            found = 1;
            break;
        }
        temp = temp->next;
        position++;
    }

    if (!found) {
        printf("\nPatient with ID %d is not in the current OPD waiting list.\n", searchID);
    }
}

// 6. OPD Sub-Menu (Called by main.c)
void handleOPD() {
    int choice;
    do {
        printf("\n--- OPD Queue Menu ---\n\n");
        printf("1. Add Patient\n");
        printf("2. Treat Patient\n");
        printf("3. View Next Patient\n");
        printf("4. Display All Patients\n");
        printf("5. Search Patients By ID\n");
        printf("6. Return to Main Hospital Menu\n\n");
        printf("Enter your choice: ");

        // validation for menu choice
        if (scanf("%d", &choice) != 1) {
            choice = 0; // Reset choice to trigger default case
        }
        clearBuffer();

        switch(choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                searchPatientByID();
                break;
            case 6:
                printf("Returning to Main Hospital System...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number from 1 to 6.\n");
        }
    } while(choice != 6);
}
