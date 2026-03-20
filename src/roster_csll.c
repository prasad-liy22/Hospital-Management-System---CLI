#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "roster_csll.h"

void intializeRoster(struct Roster *roster)
{
  roster->head = NULL;
  roster->tail = NULL;
}

void addStaff(struct Roster *roster, char *name, int id)
{
  struct StaffNode *newNode = (struct StaffNode *)malloc(sizeof(struct StaffNode));
  strcpy(newNode->name, name);
  newNode->staffID = id;

  if (roster->head == NULL)
  {
    roster->head = newNode;
    roster->tail = newNode;
    newNode->next = roster->head;
  }
  else
  {
    roster->tail->next = newNode;
    roster->tail = newNode;
    newNode->next = roster->head;
  }

  printf(" -> Added %s (ID: %d) to the roster.\n", name, id);
}

void generateShiftSchedule(struct Roster *roster, int noOfShifts)
{
  if (roster->head == NULL)
  {
    printf("\nThe roster is currently empty. Cannot assign shifts.\n");
    return;
  }

  printf("\n=== Generating Schedule for %d Shifts ===\n", noOfShifts);

  struct StaffNode *current = roster->head;

  for (int i = 0; i < noOfShifts; i++)
  {
    printf("Shift %d assigned to: %s (ID: %d)\n", i + 1, current->name, current->staffID);
    current = current->next;
  }

  printf("\n\n");
}

void runRosterSystem()
{
  int noOfStaff;
  char name[50];
  int id;
  int noOfShifts;
  int validInput;

  struct Roster nightShiftRoster;
  intializeRoster(&nightShiftRoster);

  printf("--- Hospital Night Shift Roster Setup ---\n\n");

  printf("How many staff members are on call tonight? ");
  do
  {
    validInput = 1;
    scanf("%d", &noOfStaff);
    if (noOfStaff <= 0)
    {
      printf("Invalid input.\n");
      validInput = 0;
    }
  } while (!validInput);

  printf("\n");

  for (int i = 0; i < noOfStaff; i++)
  {
    printf("\nEnter details for staff member %d:\n", i + 1);
    getchar();
    printf("Name: ");
    gets(name);

    printf("ID Number: ");
    do
    {
      validInput = 1;
      scanf("%d", &id);
      if (id <= 0)
      {
        printf("Invalid input.\n");
        validInput = 0;
      }
    } while (!validInput);

    addStaff(&nightShiftRoster, name, id);
  }

  printf("\n");

  printf("How many shifts would you like to schedule? ");
  do
  {
    validInput = 1;
    scanf("%d", &noOfShifts);
    if (noOfShifts <= 0)
    {
      printf("Invalid input.\n");
      validInput = 0;
    }
  } while (!validInput);

  printf("\n");
  generateShiftSchedule(&nightShiftRoster, noOfShifts);
}
