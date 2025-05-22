#include <iostream>
#include <map>
#include <unordered_map>
#include <functional>
#include <string>
#include "taskobject.h"
#include "addtask.h"
using namespace std;

/*For all team-members*/


//this is where all active tasks are stored, added, deleted, sorted, and all other operations that run on the taskobject are run on this list
unordered_map<string, TaskObject> activeTasksList;


/*End for all team-members*/

// Salah's Part add tasks
//Kashta's (make sure code is compatible with menu (easy arguments))
struct Command
{
    string name;
    function<void()> function;
};
/*
(for future k, noone implement any of this.):
-make a vraiable that holds current tasklist in order to pass as argument (done)
-make delegates for each of team's function's (if they require arguments, if not, then just put the name)
-delete quirks like placeholder functions and comments such as this one
-add a tad bit of cool shi cuz why tf not (not sure wut constitutes as cool just yet) (task roullete XD)
*/

void Meow()
{
    cout << "Meow\n";
}



map<int, Command> commands =
{
    //Adding goes like this {(function's number), (define a new Command)}
    {1, Command{"Meow", Meow}},
    {2, Command{"Add Task", []() { addtask(activeTasksList); }}},
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
//End Kashta's

