#ifndef ENDLESS_VITALS_H
#define ENDLESS_VITALS_H

// Patient Vitals Structure
typedef struct {
    int patientId;
    char name[50];
    int heartRate;          // bpm
    char bloodPressure[15]; // e.g., 120/80
    int oxygenLevel;        // SpO2 percentage
    float temperature;      // Celsius
} PatientVitals;

// Node structure for the Circular Doubly Linked List (CDLL)
typedef struct Node {
    PatientVitals data;
    struct Node* next; // Swipe Right
    struct Node* prev; // Swipe Left
} Node;

// Main entry function
void runEndlessVitalsMonitor();

#endif