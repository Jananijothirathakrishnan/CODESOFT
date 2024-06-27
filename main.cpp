#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.emplace_back(description);
        cout << "Task added: " << description << "\n";
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks available.\n";
            return;
        }

        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].description
                      << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
        }
    }

    void markTaskCompleted(size_t index) {
        if (index > 0 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            cout << "Task " << index << " marked as completed.\n";
        } else {
            cout << "Invalid task number.\n";
        }
    }

    void removeTask(size_t index) {
        if (index > 0 && index <= tasks.size()) {
            cout << "Task removed: " << tasks[index - 1].description << "\n";
            tasks.erase(tasks.begin() + index - 1);
        } else {
            cout << "Invalid task number.\n";
        }
    }
};

void displayMenu() {
    cout<<"-------------------------------------"<<endl;
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
    cout<<"--------------------------------------"<<endl;
}

int main() {
    ToDoList todoList;
    int choice;
    string description;
    size_t index;

    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                cin.ignore();
                getline(std::cin, description);
                todoList.addTask(description);
                break;
            case 2:
                todoList.viewTasks();
                break;
            case 3:
                std::cout << "Enter task number to mark as completed: ";
                cin >> index;
                todoList.markTaskCompleted(index);
                break;
            case 4:
                std::cout << "Enter task number to remove: ";
                cin >> index;
                todoList.removeTask(index);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
