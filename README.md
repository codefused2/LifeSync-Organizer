# LifeSync-Organizer

LifeSync Organizer is a C++ project that simulates a personal productivity system. It combines multiple data structures to manage tasks, events, and notes efficiently.

Features:
Task Management (Linked List)
- Add tasks with title, category, and priority
- Automatically sorts tasks based on priority
- Remove tasks by title
- Search tasks by title or category
- Display all tasks

Event Scheduling (Min-Heap)
- Add events with title, time, and description
- Always keeps the nearest event at the top
- Remove the next upcoming event
- View the next event without deleting it
- Display all events in chronological order
  
Note-Taking System (Hash Map + Stack)
- Store notes using a hash map
- Update notes with version control
- Undo the last update using a stack
- Display all notes
  
Bonus
Load tasks, events, and notes from files at program startup

Data Structures Used
Linked List → Task management
Min-Heap → Event scheduling
Hash Map → Note storage
Stack → Note version history

How to Run

Compile the program:

g++ main.cpp -o LifeSync

Run the executable:

./LifeSync
Project Structure

My Role:
Min-heap implementation + The event scheduling part
TaskLinkedList → Handles all task operations
MinHeap → Manages events
HashMap + Stack → Handles notes and version control
