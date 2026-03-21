#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient {
    int id;
    char name[50];
    struct Patient* next;
};

struct Patient* top = NULL;

//Add Emergency Patient (Push) 
void add_emergency_patient() {
    struct Patient* newNode = (struct Patient*)malloc(sizeof(struct Patient));

    printf("Enter Patient ID: ");
    scanf("%d", &newNode->id);
    printf("Enter Patient Name: ");
    scanf("%s", newNode->name);

    newNode->next = top;
    top = newNode;

    printf("Emergency patient added!\n");
}

//Treat Patient (Pop) 
void treat_patient() { 
    if (top == NULL) {
        printf("No emergency patients!\n");
    } else {
        struct Patient* temp = top;
        printf("Treating Patient: %d - %s\n", temp->id, temp->name);

        top = top->next;
        free(temp);
    }
}

//Display  
void display() {
    struct Patient* temp = top;

    if (temp == NULL) {
        printf("No emergency patients\n");
    } else {
        while (temp != NULL) {
            printf("%d - %s\n", temp->id, temp->name);
            temp = temp->next;
        }
    }
}

//Main Function  
int main() {
    int choice;

    do {
        printf("\n--- Emergency Stack Menu ---\n");
        printf("1. Add Emergency Patient (Push)\n");
        printf("2. Treat Patient (Pop)\n");
        printf("3. Display Emergency Patients\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_emergency_patient();
                break;

            case 2:
                treat_patient();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 4);

    return 0;
}
