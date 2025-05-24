// addtask Salah's Part
#include "addtask.h"
#include <iostream>
#include <algorithm>

using namespace std;

string trimInput(const string& str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return (first == string::npos) ? "" : str.substr(first, (last - first + 1));
}

void addtask(unordered_map<string, TaskObject>& tasksList)
{
    string title, prio;

    cout << "\n--- Add New Task ---\n";
    cout << "Title: ";
    getline(cin >> ws, title);
    title = trimInput(title); 

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

    cout << "Priority (High/Medium/Low): ";
    getline(cin, prio);

    string prioLcase = prio;
    transform(prioLcase.begin(), prioLcase.end(), prioLcase.begin(), ::tolower);
    if (prioLcase != "high" && prioLcase != "medium" && prioLcase != "low")
    {
        cout << "Invalid priority. Defaulting to 'Medium'.\n";
        prio = "Medium";
    }

    tasksList[title] = TaskObject{ title, prio };
}
