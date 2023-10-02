// C++ program TO-DO LIST
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Task
{
    string description;
    bool completed;
};
void displayTasks(const vector<Task> &tasks)
{
    cout << "To-Do List: \n";
    for (size_t i = 0; i < tasks.size(); i++)
    {
        cout << i + 1 << ". [" << (tasks[i].completed ? "X" : " ") << "]" << tasks[i].description << endl;
    }
}
int main()
{
    vector<Task> tasks;
    int choice;
    cout << "Simple To-Do List Manager\n";
    while (1)
    {
        cout << "\n Options: \n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        //code for doing operation
        cin >> choice;
        if (choice == 1)
        {
            Task newTask;
            cout << "Enter task description: ";
            cin.ignore();
            getline(cin, newTask.description);
            newTask.completed = false;
            tasks.push_back(newTask);
            cout << "Task added!\n";
        }
        else if (choice == 2)
        {
            if (tasks.empty())
            {
                cout << "No tasks to display.\n";
            }
            else
            {
                displayTasks(tasks);
            }
        }
        else if (choice == 3)
        {
            int taskIndex;
            cout << "Enter the index of the task to mark as completed: \n";
            cin >> taskIndex;
            if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size()))
            {
                tasks[taskIndex - 1].completed = true;
                cout << "Task marked as completed!\n";
            }
            else
            {
                cout << "Invalid task index.\n";
            }
        }
        else if (choice == 4)
        {
            int taskIndex;
            cout << "Enter te index of the task to remove: \n";
            cin >> taskIndex;

            if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size()))
            {
                tasks.erase(tasks.begin() + taskIndex - 1);
                cout << "Task removed!\n";
            }
            else
            {
                cout << "Invalid task index.\n";
            }
        }
        else if (choice == 5)
        {
            cout << "Exiting the program.\n";
            break;
        }
        else
        {
            cout << "Invalid choice. Please choose a valid option.\n";
        }
    } // end of while loop
    return 0;
} // end of main