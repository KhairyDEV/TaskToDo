#include <algorithm>  
#include <cctype>     
#include <limits>     
#include "duedate.h"

void setDueDate(unordered_map<string, TaskObject>& tasks) {
    string name;
    cout << "Enter task name: ";
    getline(cin >> ws, name);

    string lowerName = name;
    transform(lowerName.begin(), lowerName.end(), lowerName.begin(),
        [](unsigned char c) { return tolower(c); });

    if (tasks.find(lowerName) == tasks.end()) {
        cout << "Task not found.\n";
        return;
    }

    int d, m, y, h, min;

    while (true) {
        cout << "Enter day (1-31): ";
        cin >> d;
        if (!cin.fail() && d >= 1 && d <= 31)
            break;
        cout << "Error: Invalid day. Must be between 1 and 31.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    while (true) {
        cout << "Enter month (1-12): ";
        cin >> m;
        if (!cin.fail() && m >= 1 && m <= 12)
            break;
        cout << "Error: Invalid month. Must be between 1 and 12.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (true) {
        cout << "Enter year (2024-2100): ";
        cin >> y;
        if (!cin.fail() && y >= 2024 && y <= 2100)
            break;
        cout << "Error: Invalid year. Must be between 2024 and 2100.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (true) {
        cout << "Enter hour (0-23): ";
        cin >> h;
        if (!cin.fail() && h >= 0 && h <= 23)
            break;
        cout << "Error: Invalid hour. Must be between 0 and 23.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (true) {
        cout << "Enter minute (0-59): ";
        cin >> min;
        if (!cin.fail() && min >= 0 && min <= 59)
            break;
        cout << "Error: Invalid minute. Must be between 0 and 59.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    tasks[lowerName].due = { d, m, y, h, min };
    cout << "Due date set.\n";
}