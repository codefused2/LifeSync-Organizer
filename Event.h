#ifndef EVENT_H
#define EVENT_H

#include <string>
using namespace std;

struct Event {
    string time;
    string title;
    string eventDescription;

    Event(string t, string titl, string desc);
    Event();
};

#endif