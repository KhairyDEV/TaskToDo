#include "deletetask.h"
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;


void DeleteTask(unordered_map<string, TaskObject>& tasksList)
{
    cout << "\n--- Delete Task ---\n";

    if (tasksList.empty()) {
        cout << "No tasks to delete.\n";
        return;
    }

    cout << "Current Tasks:\n";
    for (const auto& pair : tasksList) {
        cout << "- " << pair.first << endl;
    }

    cout << "Enter the title of the task to delete: ";
    string titlefordeleting;
    getline(cin >> ws, titlefordeleting);
    
    titlefordeleting = trim(titlefordeleting); 
    transform(titlefordeleting.begin(), titlefordeleting.end(), titlefordeleting.begin(), ::tolower);

    auto it = tasksList.find(titlefordeleting);
    if (it != tasksList.end()) {
        string deletedTitle = it->first;
        tasksList.erase(it);
        cout << "Task \"" << deletedTitle << "\" deleted successfully.\n";
    } else {
        cout << "Task \"" << titlefordeleting << "\" not found.\n";
    }
}

