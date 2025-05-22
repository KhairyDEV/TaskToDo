// taskobject.h
#ifndef TASKOBJECT_H
#define TASKOBJECT_H

#include <string>

using namespace std; // since you're using this across all files

struct TaskObject
{
    string title;
    string due;
    string prio;
};

#endif // TASKOBJECT_H
