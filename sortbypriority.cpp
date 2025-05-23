#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <sortbypriority.h>

using namespace std;

struct TaskObject {
    string title;
    string due;
    int prio;
};

void sortbypriority(unordered_map<string, TaskObject>& tasksList) {
    // Copy map entries into a vector
    vector<pair<string, TaskObject>> taskVec(tasksList.begin(), tasksList.end());

    // Sort by prio (ascending)
    sort(taskVec.begin(), taskVec.end(), [](const auto& a, const auto& b) {
        return a.second.prio < b.second.prio;
    });

    // Display sorted tasks
    for (const auto& [key, task] : taskVec) {
        cout << "Title: " << task.title
             << ", Due: " << task.due
             << ", Priority: " << task.prio << endl;
    }
}
