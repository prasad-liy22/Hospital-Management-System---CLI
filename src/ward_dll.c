#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient {
    int bedNo;
    char name[50];
    char diagnosis[100];
    struct Patient* prev;
    struct Patient* next;
};

struct Patient* head = NULL;

void admitPatient(int bedNo, char name[], char diagnosis[]) {
    struct Patient* newNode = (struct Patient*)malloc(sizeof(struct Patient));

    newNode->bedNo = bedNo;
    strcpy(newNode->name, name);
    strcpy(newNode->diagnosis, diagnosis);
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Patient* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void displayForward() {
    struct Patient* temp = head;
    printf("\nForward Traversal:\n");

    while (temp != NULL) {
        printf("Bed %d - %s (%s)\n", temp->bedNo, temp->name, temp->diagnosis);
        temp = temp->next;
    }
}

void displayBackward() {
    struct Patient* temp = head;

    if (temp == NULL) return;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("\nBackward Traversal:\n");

    while (temp != NULL) {
        printf("Bed %d - %s (%s)\n", temp->bedNo, temp->name, temp->diagnosis);
        temp = temp->prev;
    }
}

void dischargePatient(int bedNo) {
    struct Patient* temp = head;

    while (temp != NULL) {
        if (temp->bedNo == bedNo) {

            if (temp->prev == NULL) {
                head = temp->next;
                if (head != NULL)
                    head->prev = NULL;
            } else {
                temp->prev->next = temp->next;
                if (temp->next != NULL)
                    temp->next->prev = temp->prev;
            }

            free(temp);
            printf("Patient in Bed %d discharged.\n", bedNo);
            return;
        }
        temp = temp->next;
    }

    printf("Patient not found.\n");
}

int main() {
    admitPatient(1, "Kamal", "Fever");
    admitPatient(2, "Nimal", "High BP");
    admitPatient(3, "Sunil", "Skin Rash");

    displayForward();
    displayBackward();

    dischargePatient(2);

    displayForward();

    return 0;
}
