#ifndef TASKLINKEDLIST_H
#define TASKLINKEDLIST_H

#include "TaskNode.h"
#include <string>
using namespace std;

class TaskLinkedList{
private:
    TaskNode* head;
public:
    TaskLinkedList();
    ~TaskLinkedList();
    void addTask(string title, string category, int priority);
    void removeTask(string taskTitle);
    void searchTaskByTitle(string taskTitle);
    void searchTaskByCategory(string category);
    void displayTasks();
    void removeTasksfromFile();
};

#endif