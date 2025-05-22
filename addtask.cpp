// addtask Salah's Part
#include "addtask.h"
#include <iostream>
#include <algorithm>

using namespace std;

void addtask(unordered_map<string, TaskObject>& tasksList)
{
    string title, due, prio;

    cout << "\n--- Add New Task ---\n";
    cout << "Title: ";
    getline(cin >> ws, title);

    if (tasksList.find(title) != tasksList.end()) {
        string confirm;
        cout << "Task already exists. Overwrite? (y/n): ";
        getline(cin, confirm);
        if (confirm != "y" && confirm != "Y") return;
    }

    if (title.empty())
    {
        cout << "Title cannot be empty. Please fill the title.\n";
        return;
    }

    cout << "Due Date (DD-MM-YYYY): ";
    getline(cin, due);

    if (due.length() != 10){
        cout << "Invalid Date Format, Please fill the date correctly";
        return;
    }

    cout << "Priority (High/Medium/Low): ";
    getline(cin, prio);

    string prioLcase = prio;
    transform(prioLcase.begin(), prioLcase.end(), prioLcase.begin(), ::tolower);
    if (prioLcase != "high" && prioLcase != "medium" && prioLcase != "low")
    {
        cout << "Invalid priority. Defaulting to 'Medium'.\n";
        prio = "Medium";
    }

    tasksList[title] = TaskObject{ title, due, prio };
}
