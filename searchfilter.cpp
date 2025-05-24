#include "searchfilter.h"
#include <iostream>
using namespace std;

string toLower(const string& s) {
    string res = s;
    transform(res.begin(), res.end(), res.begin(), ::tolower);
    return res;
}

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
                        << " | Due: " << p.second.getDueString() << endl;
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
                if (toLower(p.second.prio) == toLower(prio)) {
                    cout << p.second.title
                        << " | Priority: " << p.second.prio
                        << " | Due: " << p.second.getDueString() << endl;
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
                if (p.second.getDueString() < today) { 
                    cout << p.second.title
                        << " | Priority: " << p.second.prio
                        << " | Due: " << p.second.getDueString() << endl;
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
