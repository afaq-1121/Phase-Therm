#ifndef Functioning_h
#define Functioning_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Selection.h"
#include "FileManagment.h"
struct Phases;

void display(struct Phases** phase);
void deleteAllRecords(void);
void displayAndDelete(void);
void displayAllRecord(void);
void searchAndDisplay(void);
int searchRecord(void);
void addRecordtoFile(struct Phases** phase);
void Austenite(void);
void Bainite(void);
void Martensite(void);

#endif /* Functioning_h */
