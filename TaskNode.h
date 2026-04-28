#ifndef TASKNODE_H
#define TASKNODE_H

#include <string>
using namespace std;

class TaskNode{
public:
    string taskTitle, category;
    int priority;
    TaskNode* next;
    TaskNode(string title, string cat, int prio);
};

#endif