#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/vitals_cdll.h"

// Global pointer to the head of the Circular Doubly Linked List
static Node* head = NULL;

// Create a new node and allocate memory
Node* createNode(int id, char* name, int hr, char* bp, int spo2, float temp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data.patientId = id;
    strcpy(newNode->data.name, name);
    newNode->data.heartRate = hr;
    strcpy(newNode->data.bloodPressure, bp);
    newNode->data.oxygenLevel = spo2;
    newNode->data.temperature = temp;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Add a patient to the end of the CDLL (No null ends)
void addPatient(int id, char* name, int hr, char* bp, int spo2, float temp) {
    Node* newNode = createNode(id, name, hr, bp, spo2, temp);

    if (head == NULL) {
        head = newNode;
        head->next = head; // Points to itself to avoid NULL
        head->prev = head; // Points to itself to avoid NULL
        return;
    }

    Node* tail = head->prev;

    // Connect the new node in the circular loop
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
}

// Dummy data to test the Swiping feature
void loadVitalsData() {
    if (head != NULL) return; 

    addPatient(101, "Kamal_Perera", 85, "120/80", 98, 36.5);
    addPatient(102, "Nimal_Silva", 110, "140/90", 92, 38.2); 
    addPatient(103, "Sunil_Santhush", 72, "118/75", 99, 36.8);
    addPatient(104, "Ruwan_Kumara", 60, "110/70", 95, 36.4);
    addPatient(105, "Kasun_Kalhara", 125, "150/95", 88, 39.1); 
    printf("Tablet data synced successfully.\n");
}

// The Endless Swipe Interface
void startTabletMonitor() {
    if (head == NULL) {
        printf("No patient data available on the monitor.\n");
        return;
    }

    Node* current = head;
    char command;

    do {
        // Clear screen simulation (optional, works on some consoles)
        printf("\n\n\n\n"); 
        
        printf("=========================================\n");
        printf("       ENDLESS VITALS MONITOR (TAB)      \n");
        printf("=========================================\n");
        printf("  Patient ID     : %d\n", current->data.patientId);
        printf("  Patient Name   : %s\n", current->data.name);
        printf("-----------------------------------------\n");
        
        if (current->data.heartRate > 100 || current->data.heartRate < 60)
            printf("  Heart Rate     : %d bpm [WARNING!]\n", current->data.heartRate);
        else
            printf("  Heart Rate     : %d bpm\n", current->data.heartRate);

        printf("  Blood Pressure : %s\n", current->data.bloodPressure);

        if (current->data.oxygenLevel < 90)
            printf("  Oxygen (SpO2)  : %d%% [CRITICAL!]\n", current->data.oxygenLevel);
        else
            printf("  Oxygen (SpO2)  : %d%%\n", current->data.oxygenLevel);

        printf("  Temperature    : %.1f C\n", current->data.temperature);
        printf("=========================================\n");
        
        // Tablet Swipe Controls
        printf("[R] Swipe Right (Next) | [L] Swipe Left (Prev) | [E] Close App\n");
        printf("Action: ");
        scanf(" %c", &command); 

        if (command == 'R' || command == 'r') {
            current = current->next; 
        } else if (command == 'L' || command == 'l') {
            current = current->prev; 
        } else if (command != 'E' && command != 'e') {
            printf("Invalid action. Use R, L, or E.\n");
        }

    } while (command != 'E' && command != 'e');

    printf("Closing Tablet Monitor...\n");
}

// Entry point function
void runEndlessVitalsMonitor() {
    int choice;
    loadVitalsData();

    do {
        printf("\n=== ENDLESS VITALS MONITOR SYSTEM ===\n");
        printf("1. Open Tablet Swipe Interface\n");
        printf("0. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: startTabletMonitor(); break;
            case 0: printf("Returning...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 0);
}