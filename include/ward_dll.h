#ifndef WARD_DLL_H
#define WARD_DLL_H

// Patient Structure
typedef struct Patient {
    int bedNo;
    char name[50];
    char diagnosis[100];
    struct Patient* prev;
    struct Patient* next;
} Patient;

// Global Variable
extern Patient* head;

// Function Prototypes
void loadPatients();
void savePatients();
void admitPatient(int bedNo, char name[], char diagnosis[]);
void dischargePatient();
void viewPatients();
void forwardTraversal();
void backwardTraversal();
void runWardSystem();

#endif
