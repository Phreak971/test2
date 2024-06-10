#include "Task.hpp"
#include "TaskManager.hpp"
#include <iostream>
#include <chrono>
#include <limits>

// Function to clear the input buffer
void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
int main() 
{
    auto& manager = TaskManager::GetInstance();
    int choice;
    do 
    {
        std::cout << "\nTask Manager Menu:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Remove Task\n";
        std::cout << "3. Update Task\n";
        std::cout << "4. View All Tasks\n";
        std::cout << "5. Filter Tasks\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";

        while (!(std::cin >> choice)) 
        {
            std::cout << "Invalid input. Please enter a number: ";
            clearInputBuffer();
        }

        switch (choice) 
        {
            case 1: 
            {
                std::string description;
                int dueDays;
                int priority;

                clearInputBuffer(); // Clear the input buffer before getting line input

                std::cout << "Enter task description: ";
                std::getline(std::cin, description);
                
                std::cout << "Enter due days from now: ";
                while (!(std::cin >> dueDays)) 
                {
                    std::cout << "Invalid input. Please enter a number: ";
                    clearInputBuffer();
                }
                
                std::cout << "Enter priority (0-Low, 1-Medium, 2-High): ";
                while (!(std::cin >> priority) || priority < 0 || priority > 2) 
                {
                    std::cout << "Invalid input. Please enter 0, 1, or 2: ";
                    clearInputBuffer();
                }
                
                auto dueDate = std::chrono::system_clock::now() + std::chrono::hours(24 * dueDays);
                manager->AddTask(Task(description, dueDate, static_cast<TaskPriority>(priority)));

                std::cout << "Task added successfully!\n";
                break;
            }
            case 2: 
            {
                unsigned int taskId;
                std::cout << "Enter task ID to remove: ";
                while (!(std::cin >> taskId)) 
                {
                    std::cout << "Invalid input. Please enter a valid task ID: ";
                    clearInputBuffer();
                }

                try 
                {
                    manager->RemoveTask(taskId);
                    std::cout << "Task removed successfully!\n";
                } 
                catch (const std::runtime_error& e) 
                {
                    std::cerr << "Error: " << e.what() << std::endl;
                }

                break;
            }
            // Add similar cases for 3 (Update Task), 4 (View All Tasks), and 5 (Filter Tasks)
            // ... (refer to the provided TaskManager methods for implementation)
            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
    return 0;
}
