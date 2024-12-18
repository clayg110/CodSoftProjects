#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Task
{
public:
    string description;
    bool isComplete;

    Task(const string &desc) : description(desc), isComplete(false) {}
};
class TodoList
{
private:
    vector<Task> tasks;

public:
    void addTask(const string &description)
    {
        tasks.emplace_back(description);
        cout << "Task added: " << description << endl;
    }
    void completeTask(int index)
    {
        if (index >= 0 && index < tasks.size())
        {
            tasks[index].isComplete = true;
            cout << "Task completed: " << tasks[index].description << endl;
        }
        else
        {
            cout << "Invalid task index!" << endl;
        }
    }
    void removeTask(int index)
    {
        if (index >= 0 && index < tasks.size())
        {
            cout << "Removing task: " << tasks[index].description << endl;
            tasks.erase(tasks.begin() + index);
        }
        else
        {
            cout << "Invalid task index!" << endl;
        }
    }
    void displayTasks()
    {
        cout << "\nTodo List:\n";
        for (size_t i = 0; i < tasks.size(); ++i)
        {
            cout << i + 1 << ". " << tasks[i].description;
            if (tasks[i].isComplete)
            {
                cout << " [Completed]";
            }
            cout << endl;
        }
        cout << endl;
    }
};
int main()
{
    TodoList todoList;
    int choice;
    string taskDescription;

    while (true)
    {
        cout << "Todo List Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. Complete Task\n";
        cout << "3. Remove Task\n";
        cout << "4. View Tasks\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter task description: ";
            cin.ignore();
            getline(cin, taskDescription);
            todoList.addTask(taskDescription);
            break;
        case 2:
            cout << "Enter task number to complete: ";
            int completeIndex;
            cin >> completeIndex;
            todoList.completeTask(completeIndex - 1);
            break;
        case 3:
            cout << "Enter task number to remove: ";
            int removeIndex;
            cin >> removeIndex;
            todoList.removeTask(removeIndex - 1);
            break;
        case 4:
            todoList.displayTasks();
            break;
        case 5:
            cout << "Exiting the Todo List application.\n";
            return 0;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
