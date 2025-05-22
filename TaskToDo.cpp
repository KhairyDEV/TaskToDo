#include "TaskToDo.h"


unordered_map<string, TaskObject> activeTasksList;
map<int, Command> commands =
{
    //Adding goes like this {(function's number), (define a new Command)}
    {1, Command{"Add Task", []() { addtask(activeTasksList); }}},
};

int main()

{
    while (true)
    {
        string choiceString;
        int choice = 0;
        bool correctUserInput = true;
        cout << "\n*****\n\n" << "Below are the possible choices, input the NUMBER of the task you want\n";
        for (auto command : commands)
        {
            cout << command.first << "." << command.second.name << endl;
        }
        cout << endl;
        cin >> choiceString;
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