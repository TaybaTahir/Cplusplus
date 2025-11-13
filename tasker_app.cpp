#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> tasks;

// Function to display all tasks
void showTasks() {
    if (tasks.empty()) {
        cout << "\nNo tasks available!\n";
        return;
    }
    cout << "\n--- To-Do List ---\n";
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].description
             << " [" << (tasks[i].completed ? "Done" : "Pending") << "]\n";
    }
}

// Function to add a new task
void addTask() {
    Task t;
    cout << "\nEnter new task: ";
    cin.ignore();
    getline(cin, t.description);
    t.completed = false;
    tasks.push_back(t);
    cout << "Task added!\n";
}

// Function to mark task as completed
void markTask() {
    showTasks();
    cout << "\nEnter task number to mark as completed: ";
    int num;
    cin >> num;
    if (num > 0 && num <= tasks.size()) {
        tasks[num - 1].completed = true;
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid number!\n";
    }
}

// Function to delete a task
void deleteTask() {
    showTasks();
    cout << "\nEnter task number to delete: ";
    int num;
    cin >> num;
    if (num > 0 && num <= tasks.size()) {
        tasks.erase(tasks.begin() + num - 1);
        cout << "Task deleted!\n";
    } else {
        cout << "Invalid number!\n";
    }
}

// Save tasks to file
void saveToFile() {
	    ofstream file("tasks.txt");
	   for (int i = 0; i < tasks.size(); i++) {
	    file << tasks[i].description << "|" << tasks[i].completed << "\n";
	}

    file.close();
    cout << "Tasks saved to file!\n";
}

// Load tasks from file
void loadFromFile() {
    ifstream file("tasks.txt");
    if (!file.is_open()) return;
    tasks.clear();
    string line;
    while (getline(file, line)) {
        Task t;
        size_t pos = line.find('|');
        t.description = line.substr(0, pos);
        t.completed = (line.substr(pos + 1) == "1");
        tasks.push_back(t);
    }
    file.close();
    cout << "Tasks loaded from file!\n";
}

int main() {
    loadFromFile();
    int choice;

    while (true) {
        cout << "\n==== TO-DO LIST MENU ====\n";
        cout << "1. Show Tasks\n";
        cout << "2. Add Task\n";
        cout << "3. Mark Task Completed\n";
        cout << "4. Delete Task\n";
        cout << "5. Save & Exit\n";
        cout << "Enter choice: ";
        
        cin >> choice;

        switch (choice) {
            case 1: showTasks(); break;
            case 2: addTask(); break;
            case 3: markTask(); break;
            case 4: deleteTask(); break;
            case 5: saveToFile(); 
                    cout << "Goodbye!\n";
                    return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}

