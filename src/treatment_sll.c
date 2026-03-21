#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/treatment_sll.h"

void initializeTreatment(struct TreatmentPlan *plan) {
    plan->head = NULL;
    plan->tail = NULL;
}

void addTreatmentStep(struct TreatmentPlan *plan, char *stepName) {
    struct TreatmentStep *newStep = (struct TreatmentStep *)malloc(sizeof(struct TreatmentStep));
    strcpy(newStep->stepName, stepName);
    newStep->next = NULL;

    if (plan->head == NULL) {
        plan->head = newStep;
        plan->tail = newStep;
    } else {
        plan->tail->next = newStep;
        plan->tail = newStep;
    }

    printf(" -> Added treatment step: %s\n", stepName);
}

void displayTreatmentSequence(struct TreatmentPlan *plan) {
    if (plan->head == NULL) {
        printf("Treatment plan is empty.\n");
        return;
    }

    printf("\n=== Patient Treatment Sequence ===\n");

    struct TreatmentStep *current = plan->head;
    int stepNumber = 1;

    while (current != NULL) {
        printf("Step %d: %s\n", stepNumber, current->stepName);
        current = current->next;
        stepNumber++;
    }

    printf("\n");
}

int countSteps(struct TreatmentPlan *plan) {
    int count = 0;
    struct TreatmentStep *current = plan->head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

void runTreatment() {
    struct TreatmentPlan patientPlan;
    initializeTreatment(&patientPlan);

    int choice;
    char step[50];

    do {
        printf("\n===== Patient Treatment System =====\n");
        printf("1. Add Treatment Step\n");
        printf("2. Display Treatment Sequence\n");
        printf("3. Count Total Steps\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {

            case 1:
                printf("Enter treatment step: ");
                fgets(step, sizeof(step), stdin);
                step[strcspn(step, "\n")] = 0;
                addTreatmentStep(&patientPlan, step);
                break;

            case 2:
                displayTreatmentSequence(&patientPlan);
                break;

            case 3:
                printf("Total steps: %d\n", countSteps(&patientPlan));
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);

}