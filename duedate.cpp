// DueDateSetter.cpp
#include "DueDateSetter.h"

void setDueDate(std::unordered_map<std::string, TaskObject>& tasks) {
    std::string name;
    std::cout << "Enter task name: ";
    std::getline(std::cin >> std::ws, name); // case-sensitive match

    if (tasks.find(name) == tasks.end()) {
        std::cout << "Task not found.\n";
        return;
    }

    int d, m, h, min;
    std::cout << "Enter day (1-31): ";
    std::cin >> d;
    std::cout << "Enter month (1-12): ";
    std::cin >> m;
    std::cout << "Enter hour (0-23): ";
    std::cin >> h;
    std::cout << "Enter minute (0-59): ";
    std::cin >> min;

    tasks[name].due = {d, m, h, min};
    std::cout << "Due date set.\n";
}
