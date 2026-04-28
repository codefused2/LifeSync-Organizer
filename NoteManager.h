#ifndef NOTEMANAGER_H
#define NOTEMANAGER_H

#include <iostream>
#include "HashMap.h"
#include "Note.h"
using namespace std;

class NoteManager {
private:
    HashMap notes;

public:
    void addNote(string title, string content);
    void updateNote(string title, string newContent);
    void undoNote(string title);
    void displayNotes();
    void removeNoteFromFile();
};

#endif
