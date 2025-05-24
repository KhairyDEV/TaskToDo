#ifndef SEARCHFILTER_H
#define SEARCHFILTER_H

#include <unordered_map>
#include <string>
#include "taskobject.h"
#include <algorithm>

void searchAndFilter(const std::unordered_map<std::string, TaskObject>& tasksList);

#endif
