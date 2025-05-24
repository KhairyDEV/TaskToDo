#include "savewload.h"
#include <fstream>
#include <iostream>

void saveTasksToFile(const string& filename, const unordered_map<string, TaskObject>& tasks) {
    ofstream file(filename);
    if (!file) {
        cerr << "Error opening file for writing.\n";
        return;
    }

    for (const auto& pair : tasks) {
        const string& key = pair.first;
        const TaskObject& task = pair.second;

        file << key << "\n";
        file << task.title << "\n";
        file << task.prio << "\n";
        file << task.due.day << " " << task.due.month << " " << task.due.year << " "
            << task.due.hour << " " << task.due.minute << "\n";
        file << task.completed << "\n";
    }

    file.close();
    cout << "Tasks saved.\n";
}

void loadTasksFromFile(const string& filename, unordered_map<string, TaskObject>& tasks) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file for reading.\n";
        return;
    }

    string key;
    TaskObject task;

    while (getline(file, key)) {
        if (!getline(file, task.title)) break;
        if (!getline(file, task.prio)) break;
        if (!(file >> task.due.day >> task.due.month >> task.due.year
            >> task.due.hour >> task.due.minute)) break;
        if (!(file >> task.completed)) break;
        file.ignore();  // Ignore the newline after completed

        tasks[key] = task;
    }

    file.close();
    cout << "Tasks loaded.\n";
}
