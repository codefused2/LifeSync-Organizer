#include "TaskLinkedList.h"
#include<fstream>
#include <iostream>
using namespace std;

TaskLinkedList::TaskLinkedList() : head(nullptr) {}

TaskLinkedList::~TaskLinkedList()
{
    while(head != nullptr)
    {
        TaskNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void TaskLinkedList::addTask(string title, string category, int priority)
{
    // taha don't panic
    // what did i add:-
    //  Checker for prevent infinite spam and check if a task is already made
    // i did this because when i selected the display it spams
    TaskNode* checker = head;
    while (checker != nullptr)
    {
        if (checker->taskTitle == title)
        {
            return;
        }
        checker = checker->next;
    }

    // taha's Original function
    TaskNode* newNode = new TaskNode(title, category, priority);
    if(head == nullptr || newNode->priority < head->priority)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        TaskNode* temp = head;
        while(temp->next != nullptr && temp->next->priority <= newNode->priority)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void TaskLinkedList::removeTask(string taskTitle)
{
    if(head == nullptr)
    {
        cout << "Empty list!\n";
        return;
    }
    if(head->taskTitle == taskTitle)
    {
        TaskNode* del = head;
        head = head->next;
        delete del;
        cout << "Task removed successfully!\n";
        removeTasksfromFile();
        return;
    }
    TaskNode* temp = head;
    while(temp->next != nullptr && temp->next->taskTitle != taskTitle)
    {
        temp = temp->next;
    }
    if(temp->next == nullptr)
    {
        cout << "Task not found!\n";
        return;
    }
    TaskNode* del = temp->next;
    temp->next = del->next;
    delete del;
    removeTasksfromFile();
    cout << "Task removed successfully!\n";
}
//file part:---------------------------------
void TaskLinkedList::removeTasksfromFile()
{
    ofstream file("task.txt");

    if (!file.is_open())
    {
        cout << "Error: Failed to open 'task.txt' for saving.\n";
        return;
    }

    TaskNode* current = head;
    while (current != nullptr)
    {
        file << current->taskTitle << "," << current->category << "," << current->priority << endl;
        current = current->next;
    }

    file.close();

}
//--------------------------------------------------

void TaskLinkedList::searchTaskByTitle(string taskTitle)
{
    TaskNode* temp = head;
    while(temp != nullptr)
    {
        if(temp->taskTitle == taskTitle)
        {
            cout << "Task found!\n";
            cout << "Title: " << temp->taskTitle << ", Category: " << temp->category << ", Priority: " << temp->priority << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Task not found!\n";
}

void TaskLinkedList::searchTaskByCategory(string category)
{
    TaskNode* temp = head;
    bool found = false;
    while(temp != nullptr)
    {
        if(temp->category == category)
        {
            cout << "Title: " << temp->taskTitle << ", Category: " << temp->category << ", Priority: " << temp->priority << "\n";
            found = true;
        }
        temp = temp->next;
    }
    if(!found)
    {
        cout << "No tasks found in this category!\n";
    }
}

void TaskLinkedList::displayTasks()
{
    if(head == nullptr)
    {
        cout << "No tasks to display!\n";
        return;
    }
    TaskNode* temp = head;
    while(temp != nullptr) {
        cout << "Title: " << temp->taskTitle << ", Category: " << temp->category << ", Priority: " << temp->priority << "\n";

        temp = temp->next;
    }
}