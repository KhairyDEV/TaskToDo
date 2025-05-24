#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "taskobject.h"

using namespace std;

unordered_map<string, TaskObject> activeTasksList;

void searchAndFilter(const unordered_map<string, TaskObject>& tasksList) {
    while (true) {
        cout << "\n--- Search & Filter ---\n";
        cout << "1. Search by keyword in title" << endl;
        cout << "2. Filter by priority" << endl;
        cout << "3. Filter overdue by due date" << endl;
        cout << "0. Back to main menu" << endl;
        cout << "Choose: ";
        int choice;
        cin >> choice;
        cin.ignore();
        if (choice == 0) break;

        if (choice == 1) {
            cout << "Enter keyword: ";
            string key;
            getline(cin, key);
            int found = 0;
            for (const auto& p : tasksList) {
                if (p.second.title.find(key) != string::npos) {
                    cout << p.second.title
                         << " | Priority: " << p.second.prio
                         << " | Due: " << p.second.due << endl;
                    found++;
                }
            }
            if (!found) cout << "No tasks found." << endl;
        }
        else if (choice == 2) {
            cout << "Enter priority (High/Medium/Low): ";
            string prio;
            getline(cin, prio);
            int found = 0;
            for (const auto& p : tasksList) {
                if (p.second.prio == prio) {
                    cout << p.second.title
                         << " | Priority: " << p.second.prio
                         << " | Due: " << p.second.due << endl;
                    found++;
                }
            }
            if (!found) cout << "No tasks found with this priority.\n";
        }
        else if (choice == 3) {
            cout << "Enter today's date (YYYY-MM-DD): ";
            string today;
            getline(cin, today);
            int found = 0;
            for (const auto& p : tasksList) {
                if (p.second.due < today) { // simple string comparison
                    cout << p.second.title
                         << " | Priority: " << p.second.prio
                         << " | Due: " << p.second.due << endl;
                    found++;
                }
            }
            if (!found) cout << "No overdue tasks.\n";
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }
}
    string priority; // High,Medium,Low
    string due_date; //  YYYY-MM-DD
};

// 1-search by name 
vector<Task> searchTasks(const vector<Task> &tasks, const string &keyword) {
    vector<Task> results;
    for (const auto &task : tasks) {
        if (task.name.find(keyword) != string::npos) { // 3ashan lw el asm orayb mn haga 
            results.push_back(task);
        }
    }
    return results;
}

// 2- F by status
vector<Task> filterByStatus(const vector<Task> &tasks, bool completed) {
    vector<Task> results;
    for (const auto &task : tasks) {
        if (task.completed == completed) {
            results.push_back(task);
        }
    }
    return results;
}

// 3- F by priority 
vector<Task> filterByPriority(const vector<Task> &tasks, const string &priority) {
    vector<Task> results;
    for (const auto &task : tasks) {
        if (task.priority == priority) {
            results.push_back(task);
        }
    }
    return results;
}

// dy 3shan el at2ked mn el overdue dates 
bool isOverdue(const string &due_date) {
    if (due_date.empty()) return false;

    // tare5 enhrda kam -_-
    time_t t = time(0);
    tm *now = localtime(&t);

    int year_now = now->tm_year + 1900;
    int month_now = now->tm_mon + 1;
    int day_now = now->tm_mday;

    int year, month, day;
    if (sscanf(due_date.c_str(), "%d-%d-%d", &year, &month, &day) != 3) {
        return false; // 8alat yasta 
    }

    if (year < year_now) return true;
    if (year == year_now && month < month_now) return true;
    if (year == year_now && month == month_now && day < day_now) return true;

    return false;
}

// makmeltsh leh yasta 
vector<Task> filterOverdue(const vector<Task> &tasks) {
    vector<Task> results;
    for (const auto &task : tasks) {
        if (!task.completed && isOverdue(task.due_date)) {
            results.push_back(task);
        }
    }
    return results;
}

// matba3et el taskat 
void printTasks(const vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks found.\n";
        return;
    }
    int i = 1;
    for (const auto &task : tasks) {
        cout << i++ << ". " << task.name
             << " | Completed: " << (task.completed ? "Yes" : "No")
             << " | Priority: " << task.priority
             << " | Due: " << task.due_date << endl;
    }
}

int main() {
    // menu el S&F
    vector<Task> tasks = {
        {"Buy groceries", false, "High", "2024-06-15"},
        {"Finish project", true, "Medium", "2024-06-10"},
        {"Read book", false, "Low", "2024-06-14"}
    };

    int choice;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Search by name\n";
        cout << "2. Filter by status\n";
        cout << "3. Filter by priority\n";
        cout << "4. Filter overdue\n";
        cout << "5. Show all tasks\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 0) break;
        if (choice == 1) {
            cout << "Enter keyword: ";
            string keyword;
            getline(cin, keyword);
            printTasks(searchTasks(tasks, keyword));
        } else if (choice == 2) {
            cout << "Enter status (0: Not Completed, 1: Completed): ";
            int status;
            cin >> status;
            cin.ignore();
            printTasks(filterByStatus(tasks, status));
        } else if (choice == 3) {
            cout << "Enter priority (High/Medium/Low): ";
            string prio;
            getline(cin, prio);
            printTasks(filterByPriority(tasks, prio));
        } else if (choice == 4) {
            printTasks(filterOverdue(tasks));
        } else if (choice == 5) {
            printTasks(tasks);
        } else {
            cout << "Invalid choice!\n";
        }
    }
    cout << "Goodbye!" << endl;
    return 0;
}
// W BAS WALLAH 
