#pragma once
#include <iostream>
#include <map>
#include <unordered_map>
#include <functional>
#include <string>
#include "taskobject.h"
#include "addtask.h"
#include "deletetask.h"
#include "sortbypriority.h"
#include "searchfilter.h"
#include "duedate.h"
#include "savewload.h"
struct Command
{
    string name;
    function<void()> function;
};
