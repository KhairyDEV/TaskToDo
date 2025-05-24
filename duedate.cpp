#include <algorithm>
#include <cctype>
#include <limits>
#include "duedate.h"

void setDueDate(unordered_map<string, TaskObject>& tasks) {
    string name;
    cout << "Enter task name: ";
    getline(cin >> ws, name);

    // Convert to lowercase
    transform(name.begin(), name.end(), name.begin(),
        [](unsigned char c) { return tolower(c); });

    if (tasks.find(name) == tasks.end()) {
        cout << "Task not found.\n";
        return;
    }

    int d, m, y, h, min;

    // Simple validation loop helper
    auto getInput = [](const string& prompt, int minVal, int maxVal) {
        int value;
        while (true) {
            cout << prompt;
            cin >> value;
            if (!cin.fail() && value >= minVal && value <= maxVal) break;
            cout << "Invalid input. Try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        return value;
        };

    d = getInput("Enter day (1-31): ", 1, 31);
    m = getInput("Enter month (1-12): ", 1, 12);
    y = getInput("Enter year (2024-2100): ", 2024, 2100);
    h = getInput("Enter hour (0-23): ", 0, 23);
    min = getInput("Enter minute (0-59): ", 0, 59);

    tasks[name].due = { d, m, y, h, min };
    cout << "Due date set.\n";
}