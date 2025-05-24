#include <algorithm>  // for transform
#include <cctype>     // for tolower
#include "duedate.h"

void setDueDate(unordered_map<string, TaskObject>& tasks) {
    string name;
    cout << "Enter task name: ";
    getline(cin >> ws, name);

    // Convert input to lowercase
    string lowerName = name;
    transform(lowerName.begin(), lowerName.end(), lowerName.begin(),
        [](unsigned char c) { return tolower(c); });

    // Find matching task (assumes tasks keys are also lowercase)
    if (tasks.find(lowerName) == tasks.end()) {
        cout << "Task not found.\n";
        return;
    }

    int d, m, y, h, min;

    cout << "Enter day (1-31): ";
    cin >> d;
    if (d < 1 || d > 31) {
        cout << "Error: Invalid day. Must be between 1 and 31.\n";
        return;
    }

    cout << "Enter month (1-12): ";
    cin >> m;
    if (m < 1 || m > 12) {
        cout << "Error: Invalid month. Must be between 1 and 12.\n";
        return;
    }

    cout << "Enter year (e.g. 2024-2100): ";
    cin >> y;
    if (y < 2024 || y > 2100) {
        cout << "Error: Invalid year. Must be between 2024 and 2100.\n";
        return;
    }

    cout << "Enter hour (0-23): ";
    cin >> h;
    if (h < 0 || h > 23) {
        cout << "Error: Invalid hour. Must be between 0 and 23.\n";
        return;
    }

    cout << "Enter minute (0-59): ";
    cin >> min;
    if (min < 0 || min > 59) {
        cout << "Error: Invalid minute. Must be between 0 and 59.\n";
        return;
    }

    tasks[lowerName].due = { d, m, y, h, min };
    cout << "Due date set.\n";
}