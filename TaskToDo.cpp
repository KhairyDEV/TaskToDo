#include "TaskToDo.h"


unordered_map<string, TaskObject> activeTasksList;
map<int, Command> commands =
{
    //Adding goes like this {(function's number), (define a new Command)}
    {1, Command{"Add Task", []() { addtask(activeTasksList); }}},
    {2, Command{"Delete Task", []() { deletetask(activeTasksList); }}},

};

int main()

{
    while (true)
    {
        string choiceString;
        int choice = 0;
        bool correctUserInput = true;
        cout << "\n*****\n\n" << "Below are the possible choices, input the NUMBER of the task you want (Max of 9-numbers long input allowed).\n";
        for (auto command : commands)
        {
            cout << command.first << "." << command.second.name << endl;
        }
        cout << endl;
        cin >> choiceString;
        if (choiceString.length() > 9)
        {
            cout << "\nPlease enter a number less than 999999999 (With 9 nines).\nYou inputted " << choiceString.length() << " characters.\n";
            continue;
        }
        for (char i : choiceString)
        {
            if (!isdigit(i))
            {
                correctUserInput = false;
            }
        }
        cout << endl;

        if (correctUserInput)
        {
            choice = stoi(choiceString);
        }
        else
        {
            cout << "Please enter a number, such as specified above.\n";
            continue;
        }
        if (commands.count(choice))
        {
            commands[choice].function();
        }
        else
        {
            cout << "Invalid operation.\n";
        }
    }

    return 0;
}
