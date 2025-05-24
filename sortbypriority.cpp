#include "sortbypriority.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

// Convert priority to numeric value
int getPriorityValue(const string& prio) {
    if (prio == "high") return 1;
    if (prio == "medium") return 2;
    if (prio == "low") return 3;
    return 4; // Unknown priorities go last
}

// Main function to sort and display tasks
void sortbypriority(unordered_map<string, TaskObject>& tasksList) {
    vector<TaskObject> taskVector;
    for (const auto& pair : tasksList) {
        taskVector.push_back(pair.second);
    }

    // Show numeric options
    cout << "Choose sort mode:\n"
        << "1 - Priority: High to Low\n"
        << "2 - Priority: Low to High\n"
        << "3 - Alphabetical: A to Z\n"
        << "4 - Alphabetical: Z to A\n"
        << "Enter your choice (1-4): ";

    int choice;
    cin >> choice;

    switch (choice) {
    case 1: // High to Low
        sort(taskVector.begin(), taskVector.end(),
            [](const TaskObject& a, const TaskObject& b) {
                return getPriorityValue(a.prio) < getPriorityValue(b.prio);
            });
        cout << "Tasks sorted by priority (high to low):\n";
        break;

    case 2: // Low to High
        sort(taskVector.begin(), taskVector.end(),
            [](const TaskObject& a, const TaskObject& b) {
                return getPriorityValue(a.prio) > getPriorityValue(b.prio);
            });
        cout << "Tasks sorted by priority (low to high):\n";
        break;

    case 3: // A to Z
        sort(taskVector.begin(), taskVector.end(),
            [](const TaskObject& a, const TaskObject& b) {
                return a.title < b.title;
            });
        cout << "Tasks sorted alphabetically (A to Z):\n";
        break;

    case 4: // Z to A
        sort(taskVector.begin(), taskVector.end(),
            [](const TaskObject& a, const TaskObject& b) {
                return a.title > b.title;
            });
        cout << "Tasks sorted alphabetically (Z to A):\n";
        break;

    default:
        cout << "Invalid choice.\n";
        return;
    }

    // Display sorted tasks
    for (const auto& task : taskVector) {
        cout << "Title: " << task.title
            << ", Priority: " << task.prio << '\n';
    }
}
