#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Task class to represent individual tasks
class Task
{
public:
    string description; // Description of the task
    bool isComplete;    // Status of the task (complete or not)

    Task(const string &desc) : description(desc), isComplete(false) {}
};

// TodoList class to manage the list of tasks
class TodoList
{
private:
    vector<Task> tasks; // Vector to hold all tasks

public:
    // Adds a new task to the todo list
    void addTask(const string &description)
    {
        tasks.emplace_back(description); // Create a new task and add it to the list
        cout << "Task added: " << description << endl;
    }

    // Marks a task as complete
    void completeTask(int index)
    {
        if (index >= 0 && index < tasks.size())
        {
            tasks[index].isComplete = true; // Mark the specified task as complete
            cout << "Task completed: " << tasks[index].description << endl;
        }
        else
        {
            cout << "Invalid task index!" << endl;
        }
    }

    // Removes a task from the todo list
    void removeTask(int index)
    {
        if (index >= 0 && index < tasks.size())
        {
            cout << "Removing task: " << tasks[index].description << endl;
            tasks.erase(tasks.begin() + index); // Remove the task from the list
        }
        else
        {
            cout << "Invalid task index!" << endl;
        }
    }

    // Displays all tasks in the todo list
    void displayTasks()
    {
        cout << "\nTodo List:\n";
        for (size_t i = 0; i < tasks.size(); ++i)
        {
            cout << i + 1 << ". " << tasks[i].description; // Print task description
            if (tasks[i].isComplete)
            {
                cout << " [Completed]"; // Mark completed tasks
            }
            cout << endl;
        }
        cout << endl;
    }
};

// Main function to run the Todo List application
int main()
{
    TodoList todoList; // Create a TodoList instance
    int choice;
    string taskDescription;

    while (true)
    {
        // Display menu options
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
        case 1: // Add Task
            cout << "Enter task description: ";
            cin.ignore();                  // Clear the input buffer
            getline(cin, taskDescription); // Get the full line as task description
            todoList.addTask(taskDescription);
            break;
        case 2: // Complete Task
            cout << "Enter task number to complete: ";
            int completeIndex;
            cin >> completeIndex;
            todoList.completeTask(completeIndex - 1); // Convert to zero-based index
            break;
        case 3: // Remove Task
            cout << "Enter task number to remove: ";
            int removeIndex;
            cin >> removeIndex;
            todoList.removeTask(removeIndex - 1); // Convert to zero-based index
            break;
        case 4: // View Tasks
            todoList.displayTasks();
            break;
        case 5: // Exit
            cout << "Exiting the Todo List application.\n";
            return 0; // Exit the application
        default:
            cout << "Invalid choice! Please try again.\n"; // Handle invalid choices
        }
    }

    return 0; // End of the program
}
