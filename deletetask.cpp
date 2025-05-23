#include "deletetask.h"
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

//shash, the comments are my own to remember the functionality of each section.

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

    // to correct case sensitivites, convert all letters to lower
    string titlecorrected = titlefordeleting;
    transform(titlecorrected.begin(), titlecorrected.end(), titlecorrected.begin(), ::tolower);

    //look through the stored tasks to find a match
    for (auto it = tasksList.begin(); it != tasksList.end(); ++it) {
        string currentcorrectedtask = it->first;
        transform(currentcorrectedtask.begin(), currentcorrectedtask.end(), currentcorrectedtask.begin(), ::tolower);

        if (currentcorrectedtask == titlecorrected) {
            string deletedTitle = it->first;  // Save originaltitle
            tasksList.erase(it);              // delete it
            cout << "Task \"" << deletedTitle << "\" deleted successfully.\n";
            return;
        }
    }

    // if no title match is found
    cout << "Task \"" << titlefordeleting << "\" not found.\n";
}

//end of shash's part.
