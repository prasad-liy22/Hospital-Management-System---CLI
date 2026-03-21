#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/pharmacy_array.h"

// Global inventory array and count
static Medicine inventory[MAX_MEDICINES];
static int medicineCount = 0;

void loadFromFile() {
    FILE *file = fopen("../pharmacy_data.txt", "r");
    if (file == NULL) {
        printf("No existing pharmacy data file found. Starting fresh.\n");
        return;
    }
    medicineCount = 0;
    while (fscanf(file, "%d %49s %d %f %49s %d %99s %d", 
           &inventory[medicineCount].id, inventory[medicineCount].name, 
           &inventory[medicineCount].quantity, &inventory[medicineCount].price, 
           inventory[medicineCount].supplier, &inventory[medicineCount].arrivalDate, 
           inventory[medicineCount].description, &inventory[medicineCount].expiryDate) == 8) {
        medicineCount++;
    }
    fclose(file);
    printf("Pharmacy data loaded successfully! (%d items)\n", medicineCount);
}

// this function saves the current inventory to a file for persistence
void saveToFile() {
    FILE *file = fopen("pharmacy_data.txt", "w");
    if (file == NULL) {
        printf("Error saving pharmacy data!\n");
        return;
    }
    for (int i = 0; i < medicineCount; i++) {
        fprintf(file, "%d %s %d %.2f %s %d %s %d\n", 
                inventory[i].id, inventory[i].name, inventory[i].quantity, 
                inventory[i].price, inventory[i].supplier, inventory[i].arrivalDate, 
                inventory[i].description, inventory[i].expiryDate);
    }
    fclose(file);
    printf("Pharmacy data saved successfully!\n");
}

void addMedicine() {
    if (medicineCount >= MAX_MEDICINES) {
        printf("Inventory is full! Cannot add more medicines.\n");
        return;
    }
    Medicine m;
    printf("\n--- Add New Medicine ---\n");
    printf("Enter ID: "); scanf("%d", &m.id);
    printf("Enter Name (No spaces): "); scanf("%s", m.name);
    printf("Enter Quantity: "); scanf("%d", &m.quantity);
    printf("Enter Price: "); scanf("%f", &m.price);
    printf("Enter Supplier (No spaces): "); scanf("%s", m.supplier);
    printf("Enter Arrival Date (YYYYMMDD): "); scanf("%d", &m.arrivalDate);
    printf("Enter Description (No spaces): "); scanf("%s", m.description);
    printf("Enter Expiry Date (YYYYMMDD): "); scanf("%d", &m.expiryDate);
    
    inventory[medicineCount] = m;
    medicineCount++;
    saveToFile();
    printf("Medicine added successfully!\n");
}

// This function allows the user to dispense a medicine by ID and quantity, updating the inventory accordingly
void dispenseMedicine() {
    int searchId, qtyToDispense, found = 0;
    printf("\n--- Dispense Medicine ---\n");
    printf("Enter Medicine ID: ");
    scanf("%d", &searchId);
    
    for (int i = 0; i < medicineCount; i++) {
        if (inventory[i].id == searchId) {
            found = 1;
            printf("Medicine Found: %s | Available Quantity: %d\n", inventory[i].name, inventory[i].quantity);
            printf("Enter quantity to dispense: ");
            scanf("%d", &qtyToDispense);
            
            if (qtyToDispense <= inventory[i].quantity) {
                inventory[i].quantity -= qtyToDispense;
                printf("Dispensed successfully! Remaining quantity: %d\n", inventory[i].quantity);
                saveToFile();
            } else {
                printf("Error: Not enough quantity in stock!\n");
            }
            break;
        }
    }
    if (!found) printf("Error: Medicine ID not found.\n");
}

// This function sorts the inventory by expiry date using the bubble sort algorithm, allowing the user to easily identify medicines that are expiring soon
void bubbleSortByExpiry() {
    for (int i = 0; i < medicineCount - 1; i++) {
        for (int j = 0; j < medicineCount - i - 1; j++) {
            if (inventory[j].expiryDate > inventory[j + 1].expiryDate) {
                Medicine temp = inventory[j];
                inventory[j] = inventory[j + 1];
                inventory[j + 1] = temp;
            }
        }
    }
    printf("Inventory sorted by Expiry Date (Bubble Sort).\n");
    saveToFile();
}

// this function sorts the inventory by quantity using the insertion sort algorithm, helping the user to quickly identify medicines that are low in stock
void insertionSortByQuantity() {
    for (int i = 1; i < medicineCount; i++) {
        Medicine key = inventory[i];
        int j = i - 1;
        while (j >= 0 && inventory[j].quantity > key.quantity) {
            inventory[j + 1] = inventory[j];
            j = j - 1;
        }
        inventory[j + 1] = key;
    }
    printf("Inventory sorted by Quantity (Insertion Sort).\n");
    saveToFile();
}

// This function checks for medicines that are low in stock (quantity < 100) or expiring soon (expiry date within 7 days) and displays alerts to the user, helping them to take timely action to restock or remove expired medicines
void checkAlerts(int currentDate) {
    printf("\n=== SYSTEM ALERTS ===\n");
    int alertCount = 0;
    for (int i = 0; i < medicineCount; i++) {
        if (inventory[i].quantity < 100) {
            printf("[LOW STOCK] %s (ID: %d) - Only %d left!\n", inventory[i].name, inventory[i].id, inventory[i].quantity);
            alertCount++;
        }
        if (inventory[i].expiryDate - currentDate <= 7 && inventory[i].expiryDate >= currentDate) {
            printf("[EXPIRING SOON] %s (ID: %d) expires on %d!\n", inventory[i].name, inventory[i].id, inventory[i].expiryDate);
            alertCount++;
        } else if (inventory[i].expiryDate < currentDate) {
            printf("[EXPIRED] %s (ID: %d) already expired on %d!\n", inventory[i].name, inventory[i].id, inventory[i].expiryDate);
            alertCount++;
        }
    }
    if (alertCount == 0) printf("All good! No alerts right now.\n");
    printf("=====================\n");
}


void viewInventory() {
    printf("\n----------------------------------------------------------------------------------------------------------\n");
    printf("%-5s | %-15s | %-5s | %-7s | %-12s | %-10s | %-15s | %-10s\n", 
           "ID", "Name", "Qty", "Price", "Supplier", "Arrival", "Description", "Expiry");
    printf("----------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < medicineCount; i++) {
        printf("%-5d | %-15s | %-5d | %-7.2f | %-12s | %-10d | %-15s | %-10d\n", 
               inventory[i].id, inventory[i].name, inventory[i].quantity, 
               inventory[i].price, inventory[i].supplier, inventory[i].arrivalDate, 
               inventory[i].description, inventory[i].expiryDate);
    }
    printf("----------------------------------------------------------------------------------------------------------\n");
}

// submenu function to run the pharmacy system
void runPharmacySystem() {
    loadFromFile();
    int choice;
    int currentDate;
    
    do
    {
        printf("\nEnter today's date (YYYYMMDD) for Pharmacy alerts: ");
        scanf("%d", &currentDate);
    } while (currentDate < 20240000 || currentDate > 20280000); // simple validation for current year
    

    do {
        printf("\n=== PHARMACY SUB-MENU ===\n");
        printf("1. Add New Medicine\n");
        printf("2. Dispense Medicine\n");
        printf("3. Sort by Expiry Date (Bubble Sort)\n");
        printf("4. Sort by Quantity (Insertion Sort)\n");
        printf("5. View Inventory\n");
        printf("6. Check Alerts\n");
        printf("0. Back to Main Hospital Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addMedicine(); break;
            case 2: dispenseMedicine(); break;
            case 3: bubbleSortByExpiry(); break;
            case 4: insertionSortByQuantity(); break;
            case 5: viewInventory(); break;
            case 6: checkAlerts(currentDate); break;
            case 0: printf("Returning to Main Menu...\n"); saveToFile(); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 0);
}