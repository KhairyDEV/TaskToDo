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

    string titlecorrected = titlefordeleting;
    transform(titlecorrected.begin(), titlecorrected.end(), titlecorrected.begin(), ::tolower);
    
    for (auto it = tasksList.begin(); it != tasksList.end(); ++it) {
        string currentcorrectedtask = it->first;
        transform(currentcorrectedtask.begin(), currentcorrectedtask.end(), currentcorrectedtask.begin(), ::tolower);

        if (currentcorrectedtask == titlecorrected) {
            string deletedTitle = it->first;  
            tasksList.erase(it);              
            cout << "Task \"" << deletedTitle << "\" deleted successfully.\n";
            return;
        }
    }

    cout << "Task \"" << titlefordeleting << "\" not found.\n";
}

