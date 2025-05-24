// struct header

#ifndef TASKOBJECT_H
#define TASKOBJECT_H

#include <string>

using namespace std;

struct TaskObject
{
    string title;
    string prio;
    string due;
    bool completed;
};

#endif
