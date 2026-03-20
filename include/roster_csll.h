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
void addStaff(struct Roster *roster, char *name, int id);
void generateShiftSchedule(struct Roster *roster, int noOfShifts);
void runRosterSystem();

#endif
