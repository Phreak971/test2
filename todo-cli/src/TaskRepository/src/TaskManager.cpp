#include "TaskManager.hpp"
#include <algorithm> //for std::sort 
#include <iostream>

std::unique_ptr<TaskManager> TaskManager::instance = nullptr;

TaskManager::~TaskManager() {
    std::cout << "TaskManager destroyed!\n";
}
// Get instance
std::unique_ptr<TaskManager>& TaskManager::GetInstance() 
{
    if (!instance) 
    {
        instance = std::unique_ptr<TaskManager>(new TaskManager());
    }
    return instance;
}
//add task
void TaskManager::AddTask(const Task& task) 
{
    _vecTasks.push_back(task);
}

//Remove Task
void TaskManager::RemoveTask(unsigned int TaskId) 
{
    // Find the task with the given ID and remove it
    _vecTasks.erase(std::remove_if(_vecTasks.begin(), _vecTasks.end(),
        [TaskId](const Task& task) { return task.getId() == TaskId; }), 
        _vecTasks.end());
}

//Remove Tasks
void TaskManager::RemoveTask(std::vector<Task> tasks)
{
    for(Task task : tasks)
    {
        RemoveTask(task.getId());
    }
}

//Get Task
Task TaskManager::GetTask(unsigned int taskid) const 
{
    auto it = std::find_if(_vecTasks.begin(), _vecTasks.end(),
                           [taskid](const Task& task) { return task.getId() == taskid; });

    if (it != _vecTasks.end()) 
    {
        return *it;
    } 
    else 
    {
        throw std::runtime_error("Task not found");
    }
}

//Get Tasks
std::vector<Task> TaskManager::GetTasks()
{
    return _vecTasks;
}

//Update Task
void TaskManager::UpdateTask(const Task& task) 
{
    // Find the task with the matching ID and update it
    for (Task& existingTask : _vecTasks) 
    {
        if (existingTask.getId() == task.getId()) 
        {
            existingTask = task;
            return;
        }
    }
    throw std::runtime_error("Task not found for update");
}

//Get Filtered Task
std::vector<Task> TaskManager::GetFilteredTasks(TaskFilter taskFilter) const 
{
    std::vector<Task> filteredTasks = _vecTasks; // Copy the tasks

    switch (taskFilter) 
    {
        case TaskFilter::DueDate:
            std::sort(filteredTasks.begin(), filteredTasks.end(),
                      [](const Task& a, const Task& b) 
                      { return a.getDueDate() < b.getDueDate(); });
            break;
        case TaskFilter::Priority:
            std::sort(filteredTasks.begin(), filteredTasks.end(),
                      [](const Task& a, const Task& b) 
                      { return a.getPriority() > b.getPriority(); }); // High to Low
            break;
        case TaskFilter::Status:
            // You might want to define a specific order for statuses
            std::sort(filteredTasks.begin(), filteredTasks.end(), 
                      [](const Task& a, const Task& b) 
                      { return a.getStatus() < b.getStatus(); }); 
            break;
    }
    return filteredTasks;
}
