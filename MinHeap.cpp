#include "MinHeap.h"

int MinHeap::parent(int i) { return (i - 1) / 2; }
int MinHeap::left(int i) { return 2*i + 1; }
int MinHeap::right(int i) { return 2*i + 2; }

void MinHeap::swap(Event &a, Event &b) {
    Event temp = b;
    b = a;
    a = temp;
}

void MinHeap::heapifyUp(int i) {
    while (i > 0 && arr[i].time < arr[parent(i)].time) {
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::heapifyDown(int i) {
    while (true) {
        int smallest = i;

        if (left(i) < size && arr[left(i)].time < arr[smallest].time)
            smallest = left(i);
        if (right(i) < size && arr[right(i)].time < arr[smallest].time)
            smallest = right(i);

        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            i = smallest;
        }
        else break;
    }
}

MinHeap::MinHeap() {
    capacity = 100;
    arr = new Event[capacity];
    size = 0;
}

MinHeap::~MinHeap() {
    delete[] arr;
}

void MinHeap::addEvent(Event e) {
    if (size == capacity) {
        cout << "Sorry, capacity reached!\n";
        return;
    }
    arr[size] = e;
    heapifyUp(size);
    size++;
}

Event MinHeap::removeEvent() {
    if (size == 0) {
        return {"", "", ""};
    }

    Event removedEvent = arr[0];
    arr[0] = arr[size - 1];
    size--;
    heapifyDown(0);

    return removedEvent;
}

Event MinHeap::getNextEvent() const {
    if (size == 0) {
        return {"", "", ""};
    }
    return arr[0];
}

void MinHeap::displayAllEvents() {
    if (size == 0) {
        cout << "No events available!\n";
        return;
    }

    MinHeap tempHeap;
    for (int i = 0; i < size; i++) {
        tempHeap.addEvent(arr[i]);
    }

    cout << "\n=== Scheduled Events (Time based) ===\n";
    cout << "Time  | Title                     | Description\n";
    cout << "----------------------------------------------------------\n";

    while (tempHeap.size > 0) {
        Event e = tempHeap.removeEvent();
        cout << e.time << " | " << e.title;

        for (int i = e.title.length(); i < 25; i++) {
            cout << " ";
        }
        cout << " | " << e.eventDescription << endl;
    }
    cout << "----------------------------------------------------------\n";
}

int MinHeap::getSize() { return size; }