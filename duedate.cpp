#include <algorithm>  // for transform
#include <cctype>     // for tolower
#include "duedate.h"
void setDueDate(unordered_map<string, TaskObject>& tasksList) {
    string name;
    cout << "Enter task name: ";
    getline(cin >> ws, name);

    // Convert input to lowercase
    string lowerName = name;
    transform(lowerName.begin(), lowerName.end(), lowerName.begin(),
        [](unsigned char c) { return tolower(c); });

    // Find matching task (assumes tasks keys are also lowercase)
    if (tasksList.find(lowerName) == tasksList.end()) {
        cout << "Task not found.\n";
        return;
    }

    int d, m, h, min;
    cout << "Enter day (1-31): ";
    cin >> d;
    cout << "Enter month (1-12): ";
    cin >> m;
    cout << "Enter hour (0-23): ";
    cin >> h;
    cout << "Enter minute (0-59): ";
    cin >> min;

    tasksList[lowerName].due = { d, m, h, min };
    cout << "Due date set.\n";
}
