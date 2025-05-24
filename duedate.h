// task_due_date.h
#ifndef TASKDUEDATE_H
#define TASKDUEDATE_H

#include <iostream>
#include <unordered_map>
#include <string>
#include "TaskObject.h"  // Ensure this includes the TaskObject struct/class definition

void setDueDate(std::unordered_map<std::string, TaskObject>& tasks);

#endif // TASK_DUE_DATE_H


