#ifndef EMERGENCY_STACK_H
#define EMERGENCY_STACK_H

// Emergency Patient Structure
typedef struct Patient {
    int id;
    char full_name[100];
    int age;
    char gender;
    char contact_number[15];
    char emergency_type[50];
    int severity_level;
    struct Patient* next;
} Patient;

// Stack Operations (Core)
void add_emergency_patient();        // Push
void treat_patient();                // Pop
void display_emergency_patients();   // Display all

// Additional Operations
void peek_emergency_patient();       // View top patient
int isEmpty();                       // Check if stack is empty
int count_emergency_patients();      // Count total patients
void search_emergency_patient();     // Search by ID
void clear_emergency_stack();        // Clear all patients

// System Controller
void runEmergencySystem();         // Menu system

#endif
