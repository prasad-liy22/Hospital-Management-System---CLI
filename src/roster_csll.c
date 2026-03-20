#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "roster_csll.h"

void intializeRoster(struct Roster *roster)
{
  roster->head = NULL;
  roster->tail = NULL;
}

int isRosterEmpty(struct Roster *roster)
{
  if (roster->head == NULL)
    return 1;
  else
    return 0;
}

void addStaff(struct Roster *roster, char *name, int id)
{
  struct StaffNode *newNode = (struct StaffNode *)malloc(sizeof(struct StaffNode));
  strcpy(newNode->name, name);
  newNode->staffID = id;

  if (isRosterEmpty(roster))
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

void displayRoster(struct Roster *roster)
{
  if (isRosterEmpty(roster))
  {
    printf("\nThe roster is currently empty.\n");
    return;
  }

  struct StaffNode *current = roster->head;
  int count = 1;

  printf("\n=== Current Staff Roster ===\n");
  do
  {
    printf("%d. %s (ID: %d)\n", count, current->name, current->staffID);
    current = current->next;
    count++;
  } while (current != roster->head);

  printf("\n");
}

void removeStaff(struct Roster *roster, int id)
{
  if (isRosterEmpty(roster))
  {
    printf("\nThe roster is currently empty. Nothing to remove.\n");
    return;
  }

  struct StaffNode *current = roster->head;
  struct StaffNode *previous = roster->tail;

  do
  {
    if (current->staffID == id)
    {
      if (current == roster->head && current == roster->tail)
      {
        roster->head = NULL;
        roster->tail = NULL;
      }
      else if (current == roster->head)
      {
        roster->head = roster->head->next;
        roster->tail->next = roster->head;
      }
      else if (current == roster->tail)
      {
        previous->next = roster->head;
        roster->tail = previous;
      }
      else
      {
        previous->next = current->next;
      }

      printf(" -> Removed %s (ID: %d) from the roster.\n", current->name, current->staffID);
      free(current);
      return;
    }

    previous = current;
    current = current->next;
  } while (current != roster->head);

  printf("Staff with ID %d not found.\n", id);
}

int countStaff(struct Roster *roster)
{
  if (isRosterEmpty(roster))
  {
    return 0;
  }

  int count = 0;
  struct StaffNode *current = roster->head;

  do
  {
    count++;
    current = current->next;
  } while (current != roster->head);

  return count;
}

void generateShiftSchedule(struct Roster *roster, int noOfShifts)
{
  if (isRosterEmpty(roster))
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

void clearRoster(struct Roster *roster)
{
  if (isRosterEmpty(roster))
  {
    return;
  }

  struct StaffNode *current = roster->head->next;
  while (current != roster->head)
  {
    struct StaffNode *temp = current;
    current = current->next;
    free(temp);
  }

  free(roster->head);
  roster->head = NULL;
  roster->tail = NULL;
}

void runRosterSystem()
{
  struct Roster nightShiftRoster;
  intializeRoster(&nightShiftRoster);

  int choice;
  int id;
  int noOfShifts;
  int validInput;
  char name[50];

  while (1)
  {
    printf("\n=========================================\n");
    printf("         DUTY ROSTER MANAGEMENT          \n");
    printf("=========================================\n");
    printf("1. Add Staff\n");
    printf("2. Display Roster\n");
    printf("3. Remove Staff\n");
    printf("4. Count Staff\n");
    printf("5. Generate Shift Schedule\n");
    printf("0. Back to Main Menu\n");
    printf("-----------------------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      getchar();
      printf("\nEnter staff name: ");
      gets(name);

      printf("Enter staff ID: ");
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
      break;

    case 2:
      displayRoster(&nightShiftRoster);
      break;

    case 3:
      printf("Enter staff ID to remove: ");
      scanf("%d", &id);
      removeStaff(&nightShiftRoster, id);
      break;

    case 4:
      printf("\nTotal staff in roster: %d\n", countStaff(&nightShiftRoster));
      break;

    case 5:
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

      generateShiftSchedule(&nightShiftRoster, noOfShifts);
      break;

    case 0:
      clearRoster(&nightShiftRoster);
      printf("Returning to main menu...\n");
      return;

    default:
      printf("Invalid choice! Please try again.\n");
    }
  }
}
