#ifndef PHARMACY_H
#define PHARMACY_H  

#define MAX_MEDICINES 500

// Medicine Structure
typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
    char supplier[50];
    int arrivalDate;   // Format: YYYYMMDD
    char description[100];
    int expiryDate;    // Format: YYYYMMDD
} Medicine;

// Global Variables
Medicine inventory[MAX_MEDICINES];
extern int medicineCount;

// Function Prototypes
void loadFromFile();
void saveToFile();
void addMedicine();
void dispenseMedicine();
void bubbleSortByExpiry();
void insertionSortByQuantity();
void checkAlerts(int currentDate);
void viewInventory();
void runPharmacySystem();

#endif