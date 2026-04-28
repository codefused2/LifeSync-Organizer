#ifndef EVENTSCHEDULING_H
#define EVENTSCHEDULING_H

#include "MinHeap.h"
#include <string>
using namespace std;

class EventScheduling {
private:
    MinHeap eventHeap;
    bool isValidTime(string t);

public:
    void addEvent();
    void removeNextEvent();
    void viewNextEvent();
    void showAllEvents();
    void menu();
    void loadEventToHeap(string t, string titl, string desc);
    void removeEventFromFile();


};

#endif