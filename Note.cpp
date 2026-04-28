#include "Note.h"

Note::Note(string t, string c) : title(t), content(c) {}

void Note::update_content(string new_content) {
    history.push(content);
    content = new_content;
}

void Note::undo() {
    if (!history.empty()) {
        content = history.top();
        history.pop();
    } else {
        cout << "There is no history for: " << title << endl;
    }
}

string Note::getTitle() {
    return title;
}

string Note::getContent() {
    return content;
}

bool Note::has_history() {
    return !history.empty();
}
