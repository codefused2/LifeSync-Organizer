#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "TaskLinkedList.h"
#include "NoteManager.h"
#include "EventScheduling.h"
using namespace std;

void loadTasksFromFile( TaskLinkedList& list)
{
    ifstream file("task.txt");
    string line, title, category;
    int priority;

    if (!file.is_open()) return;
    cout << "\n--- Loaded Taskes ---\n";

    while (getline(file, line))
    {
        stringstream ss(line);
        getline(ss, title, ',');
        getline(ss, category, ',');
        ss >> priority;

        list.addTask(title, category, priority);
    }
    file.close();
}


void loadNotesFromFile( NoteManager& manager)
{
    ifstream file("notes.txt");
    string line, title, content;

    if (!file.is_open()) return;
    cout << "\n--- Loaded Notes ---\n";

    while (getline(file, line))
    {
        stringstream ss(line);
        if (getline(ss, title, ':'))
        {
            getline(ss, content);
            manager.addNote(title, content);
        }
    }
    file.close();
}



void loadEventsFromFile(EventScheduling& scheduler)
{
    ifstream file("events.txt");
    string line, time, title, description;

    if (!file.is_open()) return;
    cout << "\n--- Loaded Events ---\n";

    while (getline(file, line))
    {
        stringstream ss(line);

        getline(ss, time, ',');
        getline(ss, title, ',');
        getline(ss, description);

       scheduler.loadEventToHeap(time, title, description);
    }
    file.close();
}


void taskmenu(TaskLinkedList& list)
{
    int choice;
    string title, category, filename;
    int priority;

    while (true)
    {
        cout << "\n=== TASK MENU ===\n";
        cout << "1. Add a task\n2. Remove a task\n3. Search by title\n4. Search by category\n5. Display all tasks\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            cout << "Enter task title: ";
            getline(cin, title);
            cout << "Enter category: ";
            getline(cin, category);
            cout << "Enter priority (numeric): ";
            cin >> priority;
            cin.ignore();

            list.addTask(title, category, priority);
            list.removeTasksfromFile();
            cout << "Task added successfully!\n";
        }
        else if (choice == 2)
        {
            cout << "Enter task title to remove: ";
            getline(cin, title);
            list.removeTask(title);
            // list.removeTasksfromFile() this function is added in the removetask
        }
        else if (choice == 3)
        {
            cout << "Enter task title to search: ";
            getline(cin, title);
            list.searchTaskByTitle(title);
        }
        else if (choice == 4)
        {
            cout << "Enter category to search: ";
            getline(cin, category);
            list.searchTaskByCategory(category);
        }
        else if (choice == 5)
        {
            list.displayTasks();
        }
        else if (choice == 6)
        {
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }
    }
}
// I did it passing by reference to load the events from the file to heap in a prober way
void eventscheduling(EventScheduling& scheduler)
{
    scheduler.menu();
}


void notemenu(NoteManager& manager)
{
    int choice;
    string title, content;

    while (true)
    {
        cout << "\n=== NOTE MENU ===\n";
        cout << "1. Add Note\n2. Update Note\n3. Undo Update\n4. Display All Notes\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            cout << "Enter Title: ";
            getline(cin, title);
            cout << "Enter Content: ";
            getline(cin, content);
            manager.addNote(title, content);
            cout << "Note added successfully." << endl;
        }
        else if (choice == 2)
        {
            cout << "Enter Title: ";
            getline(cin, title);
            cout << "Enter New Content: ";
            getline(cin, content);

            manager.updateNote(title, content);
        }
        else if (choice == 3)
        {
            cout << "Enter Title: ";
            getline(cin, title);
            manager.undoNote(title);
        }
        else if (choice == 4)
        {
            manager.displayNotes();
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }
    }
}


void displayMainMenu()
{
    cout << "\n========== LifeSync Organizer ==========\n";
    cout << "1. Task Management\n";
    cout << "2. Event Scheduling\n";
    cout << "3. Note-Taking System\n";
    cout << "4. Exit\n";
    cout << "========================================\n";
    cout << "Choose an option: ";
}


int main()
{
    cout << "Welcome to LifeSync Organizer!\n";
    cout << "================================\n\n";

    TaskLinkedList taskList;
    EventScheduling scheduler;
    NoteManager noteManager;

    loadTasksFromFile( taskList);
    loadNotesFromFile( noteManager);
    loadEventsFromFile(scheduler);

    int mainChoice;
    while (mainChoice != 4)
    {
        displayMainMenu();
        cin >> mainChoice;

        cin.ignore();

        switch (mainChoice)
        {
        case 1:
            taskmenu(taskList);
            break;
        case 2:
            eventscheduling(scheduler);
            break;
        case 3:
            notemenu(noteManager);
            break;
        case 4:
            cout << "\nThank you for using LifeSync Organizer!\nGoodbye!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
