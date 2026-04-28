#include "NoteManager.h"
#include <fstream>

void NoteManager::addNote(string title, string content) {
    if (notes.find(title) == nullptr) {
        Note* newNote = new Note(title, content);
        notes.insert(title, newNote);
        removeNoteFromFile();

    } else {
        cout << "Note with this title already exists." << endl;
    }
}

void NoteManager::updateNote(string title, string newContent) {
    Note* note = notes.find(title);
    if (note != nullptr) {
        note->update_content(newContent);
        removeNoteFromFile();
        cout << "Note updated." << endl;
    } else {
        cout << "Note not found." << endl;
    }
}

void NoteManager::undoNote(string title) {
    Note* note = notes.find(title);
    if (note != nullptr) {
        note->undo();
        removeNoteFromFile();
        cout << "Undo successful, current content: " << note->getContent() << endl;
    } else {
        cout << "Note not found." << endl;
    }
}

void NoteManager::displayNotes() {
    if (notes.isEmpty()) {
        cout << "No notes available." << endl;
        return;
    }
    cout << endl << "---- All Notes ----" << endl;
    notes.displayAll();
}
void NoteManager::removeNoteFromFile()
{
    ofstream file("notes.txt");

    if (!file.is_open())
    {
        cout << "Error: Failed to open 'notes.txt' for saving.\n";
        return;
    }

    HashNode** table = notes.getTable();
    int tableSize = notes.getTableSize();

    for (int i = 0; i < tableSize; i++)
    {
        HashNode* current = table[i];
        while (current != nullptr)
        {
            file << current->value->getTitle() << ":" << current->value->getContent() << endl;
            current = current->next;
        }
    }

    file.close();
}