#include <iostream>
#include <vector>

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
    vector<Task> getTasks() const
    {
        return tasks;
    }
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
    }
};
int main()
{
    TodoList todoList;
    todoList.addTask("Do the laundry");
    todoList.addTask("Go to the gym");
    todoList.addTask("Buy groceries");

    todoList.displayTasks();

    todoList.completeTask(0);
    todoList.displayTasks();

    todoList.removeTask(1);
    todoList.displayTasks();

    return 0;
}
