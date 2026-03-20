#ifndef ROSTER_CSLL_H
#define ROSTER_CSLL_H

struct StaffNode
{
  char name[50];
  int staffID;
  struct StaffNode *next;
};

struct Roster
{
  struct StaffNode *head;
  struct StaffNode *tail;
};

void intializeRoster(struct Roster *roster);
int isRosterEmpty(struct Roster *Roster);
void addStaff(struct Roster *roster, char *name, int id);
void displayRoster(struct Roster *roster);
void removeStaff(struct Roster *roster, int id);
int countStaff(struct Roster *roster);
void generateShiftSchedule(struct Roster *roster, int noOfShifts);
void clearRoster(struct Roster *roster);
void runRosterSystem();

#endif
