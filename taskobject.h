#ifndef TASKOBJECT_H
#define TASKOBJECT_H

#include <string>

using namespace std;
//For Mariam's code
struct DueDate
{
    int year=2025;
    int month;
    int day;
    int hour;
    int minute;
};

struct TaskObject
{
    string title;
    string prio;
    DueDate due;
    bool completed;
    //For Anas's
    string getDueString() const {
        return "(" + to_string(due.year) + "-" +
            (due.month < 10 ? "0" : "") + to_string(due.month) + "-" +
            (due.day < 10 ? "0" : "") + to_string(due.day) + ")";
    }
};

#endif