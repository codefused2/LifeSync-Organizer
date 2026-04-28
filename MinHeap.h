#ifndef MINHEAP_H
#define MINHEAP_H

#include "Event.h"
#include <iostream>
using namespace std;

class MinHeap {
private:
    Event* arr;
    int size;
    int capacity;

    int parent(int i);
    int left(int i);
    int right(int i);
    void swap(Event &a, Event &b);
    void heapifyUp(int i);
    void heapifyDown(int i);



public:
    MinHeap();
    ~MinHeap();

    void addEvent(Event e);
    Event removeEvent();
    Event getNextEvent() const;
    void displayAllEvents();
    int getSize();
    Event* getArray();
};

#endif