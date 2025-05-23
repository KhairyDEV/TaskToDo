#ifndef DELETETASK_H
#define DELETETASK_H

#include <vector>
#include "taskobject.h"
#include <unordered_map>

void DeleteTask(unordered_map<string, TaskObject>& tasksList);

#endif