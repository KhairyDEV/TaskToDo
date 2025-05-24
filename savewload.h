#ifndef TASKFILEIO_H
#define TASKFILEIO_H

#include "TaskObject.h"
#include <unordered_map>
#include <string>

using namespace std;

void saveTasksToFile(const string& filename, const unordered_map<string, TaskObject>& tasks);
void loadTasksFromFile(const string& filename, unordered_map<string, TaskObject>& tasks);

#endif // TASKFILEIO_H
