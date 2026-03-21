#ifndef TREATMENT_SLL_H
#define TREATMENT_SLL_H

struct TreatmentStep {
    char stepName[50];
    struct TreatmentStep *next;
};

struct TreatmentPlan {
    struct TreatmentStep *head;
    struct TreatmentStep *tail;
};

void initializeTreatment(struct TreatmentPlan *plan);
void addTreatmentStep(struct TreatmentPlan *plan, char *stepName);
void displayTreatmentSequence(struct TreatmentPlan *plan);
int countSteps(struct TreatmentPlan *plan);
void runTreatment();

#endif