// DueDateSetter.h
#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

struct DueDate {
    int day;
    int month;
    int hour;
    int minute;
};

struct TaskObject {
    std::string title;
    DueDate due;
};

// Function declaration
void setDueDate(std::unordered_map<std::string, TaskObject>& tasks);
