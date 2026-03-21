#ifndef EMERGENCY_STACK_H
#define EMERGENCY_STACK_H

// Patient structure for Emergency Stack
struct EmergencyPatient {
    int id;
    char name[50];
    struct EmergencyPatient* next;
};

// Function prototypes for Emergency Stack module

// Add emergency patient (Push)
void add_emergency_patient();

// Treat emergency patient (Pop)
void treat_patient();

// Display all emergency patients
void display_emergency_patients();

// Run Emergency System (Menu)
void run_emergency_system();

#endif
