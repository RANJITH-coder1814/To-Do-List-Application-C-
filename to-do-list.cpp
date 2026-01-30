#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Todo {
    vector<string> tasks;

public:
    void addTask() {
        string task;
        cin.ignore();
        cout << "Enter new task: ";
        getline(cin, task);
        tasks.push_back(task);
        cout << " Task added successfully!\n";
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "⚠ No tasks available!\n";
            return;
        }

        cout << "\n Your Tasks:\n";
        for (size_t i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
    }

    void deleteTask() {
        if (tasks.empty()) {
            cout << "⚠ No tasks to delete!\n";
            return;
        }

        int index;
        cout << "Enter task number to delete: ";
        cin >> index;

        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number!\n";
        } else {
            tasks.erase(tasks.begin() + index - 1);
            cout << "🗑 Task deleted successfully!\n";
        }
    }
};

int main() {
    Todo todo;
    int choice;

    while (true) {
        cout << "\n===== To-Do List App =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Delete Task\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: todo.addTask(); break;
            case 2: todo.viewTasks(); break;
            case 3: todo.deleteTask(); break;
            case 4: cout << " Exiting... Goodbye!\n"; return 0;
            default: cout << "⚠ Invalid choice! Try again.\n";
        }
    }
}
