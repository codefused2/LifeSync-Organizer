#include "EventScheduling.h"
#include <cctype>
#include <fstream>
#include <iostream>
using namespace std;

bool EventScheduling::isValidTime(string t) {
    if (t.length() != 5 || t[2] != ':') return false;
    if (!isdigit(t[0]) || !isdigit(t[1]) || !isdigit(t[3]) || !isdigit(t[4]))
        return false;

    int hours = stoi(t.substr(0, 2));
    int minutes = stoi(t.substr(3, 2));

    return (hours >= 0 && hours <= 23 && minutes >= 0 && minutes <= 59);
}

void EventScheduling::addEvent() {
    string time, title, description;
    cout << "== Event Adding ==\n";
    cout << "Enter time (HH:MM): ";
    cin >> time;
    while (!isValidTime(time)) {
        cout << "Wrong time format! please use (HH:MM): ";
        cin >> time;
    }
    cin.ignore();

    cout << "Enter event title: ";
    getline(cin, title);

    cout << "Enter event description: ";
    getline(cin, description);

    Event e(time, title, description);
    eventHeap.addEvent(e);
    removeEventFromFile();
}
// note:- don't panic ya molto this is my part also added it in the .h
//file part----------------------------
void EventScheduling::loadEventToHeap(string t, string titl, string desc) {
    Event e(t, titl, desc);
    eventHeap.addEvent(e);
    // add data to heap to let the user see his data when display
}
void EventScheduling::removeEventFromFile()
{
    ofstream file("events.txt"); // Overwrite mode

    if (!file.is_open())
    {
        cout << "Error: Failed to open 'events.txt' for saving.\n";
        return;
    }

    Event* arr = eventHeap.getArray();
    int size = eventHeap.getSize();

    for (int i = 0; i < size; i++)
    {
        file << arr[i].time << "," << arr[i].title << "," << arr[i].eventDescription << endl;
    }

    file.close();
}
Event* MinHeap::getArray()
{
    return arr;
}

//-------------------------------------

void EventScheduling::removeNextEvent() {
    cout << "== Removing Event ==\n";
    if (eventHeap.getSize() == 0) {
        cout << "No events to remove!\n";
        return;
    }

    Event removed = eventHeap.removeEvent();
    removeEventFromFile();
    cout << "Event removed: " << removed.time << " - " << removed.title
         << " - " << removed.eventDescription << endl;
}

void EventScheduling::viewNextEvent() {
    cout << "== Your next event ==\n";
    if (eventHeap.getSize() == 0) {
        cout << "No events available!\n";
        return;
    }

    Event next = eventHeap.getNextEvent();
    cout << next.time << " - " << next.title << " - "
         << next.eventDescription << endl;
}

void EventScheduling::showAllEvents() {
    eventHeap.displayAllEvents();
}

void EventScheduling::menu() {
    int choice = 0;
    while (choice != 5) {
        cout << "\n=== Event Scheduling ===\n";
        cout << "1) Add event\n2) Remove next event\n3) View next event\n";
        cout << "4) Show all events\n5) Return to main menu\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addEvent(); break;
            case 2: removeNextEvent(); break;
            case 3: viewNextEvent(); break;
            case 4: showAllEvents(); break;
            case 5: break;
            default: cout << "Invalid Choice!\n";
        }
    }
}