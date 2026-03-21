#ifndef OPD_QUEUE_H
#define OPD_QUEUE_H

// Expanded Patient structure
struct OPDPatient {
    int id;
    char full_name[100];
    int age;
    char gender;
    char contact_number[15];
    char symptoms[200];
    struct OPDPatient* next;
};

// Function prototypes for the OPD module
void clearBuffer();
void enqueue();
void dequeue();
void peek();
void display();
void searchPatientByID();
void handleOPD();

#endif
