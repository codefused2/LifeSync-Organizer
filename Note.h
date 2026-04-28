#ifndef NOTE_H
#define NOTE_H

#include <iostream>
#include <stack>
using namespace std;

class Note {
private:
    string title;
    string content;
    stack<string> history;

public:
    Note(string t = "", string c = "");
    void update_content(string new_c);
    void undo();
    string getTitle();
    string getContent();
    bool has_history();
};

#endif
