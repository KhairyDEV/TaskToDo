#pragma once
#include <iostream>
#include <map>
#include <unordered_map>
#include <functional>
#include <string>
#include "taskobject.h"
#include "addtask.h"

struct Command
{
    string name;
    function<void()> function;
};
