void setDueDate(unordered_map<string, TaskObject>& tasks) {
    string inputName;
    cout << "Enter task name: ";
    getline(cin >> ws, inputName);

    string foundKey;
    for (const auto& [key, _] : tasks) {
        if (toLower(key) == toLower(inputName)) {
            foundKey = key;
            break;
        }
    }

    if (foundKey.empty()) {
        cout << "Task not found.\n";
        return;
    }

    int d, m, y, h, min;

    cout << "Enter year (1900-2100): ";
    while (!(cin >> y) || y < 1900 || y > 2100) {
        cout << "Invalid. Try again: ";
        cin.clear(); cin.ignore(1000, '\n');
    }

    cout << "Enter month (1-12): ";
    while (!(cin >> m) || m < 1 || m > 12) {
        cout << "Invalid. Try again: ";
        cin.clear(); cin.ignore(1000, '\n');
    }

    cout << "Enter day (1-31): ";
    while (!(cin >> d) || d < 1 || d > 31) {
        cout << "Invalid. Try again: ";
        cin.clear(); cin.ignore(1000, '\n');
    }

    cout << "Enter hour (0-23): ";
    while (!(cin >> h) || h < 0 || h > 23) {
        cout << "Invalid. Try again: ";
        cin.clear(); cin.ignore(1000, '\n');
    }

    cout << "Enter minute (0-59): ";
    while (!(cin >> min) || min < 0 || min > 59) {
        cout << "Invalid. Try again: ";
        cin.clear(); cin.ignore(1000, '\n');
    }

    tasks[foundKey].due = {d, m, y, h, min};
    cout << "Due date set.\n";
}
