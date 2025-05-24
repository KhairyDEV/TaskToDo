#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include "taskobject.h" // Ensure this matches your project's structure

// Function to set the due date for an existing task
void setDueDate(std::unordered_map<std::string, TaskObject>& tasks) {
    std::string name;
    std::cout << "Enter task name: ";
    std::getline(std::cin >> std::ws, name); // Reads the task name (case-sensitive)

    auto it = tasks.find(name);
    if (it == tasks.end()) {
        std::cout << "Task not found.\n";
        return;
    }

    int day, month, hour, minute;
    std::cout << "Enter day (1-31): ";
    std::cin >> day;
    std::cout << "Enter month (1-12): ";
    std::cin >> month;
    std::cout << "Enter hour (0-23): ";
    std::cin >> hour;
    std::cout << "Enter minute (0-59): ";
    std::cin >> minute;

    it->second.due = {day, month, hour, minute};
    std::cout << "Due date set.\n";
}

