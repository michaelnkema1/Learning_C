#include<stdio.h>


#define MAX_TASKS 100
#define MAX_LENGTH 50

struct Task {
    char description[MAX_LENGTH];
    int completed;
};

struct Task todoList[MAX_TASKS];
int taskCount = 0;

void addTask(const char* description) {
    if (taskCount < MAX_TASKS) {
        strncpy(todoList[taskCount].description, description, MAX_LENGTH - 1);
        todoList[taskCount].description[MAX_LENGTH - 1] = '\0';
        todoList[taskCount].completed = 0;
        taskCount++;
        printf("Task added successfully!\n");
    } else {
        printf("Todo list is full!\n");
    }
}

void markAsComplete(int index) {
    if (index >= 0 && index < taskCount) {
        todoList[index].completed = 1;
        printf("Task marked as complete!\n");
    } else {
        printf("Invalid task index!\n");
    }
}

void displayTasks() {
    if (taskCount == 0) {
        printf("No tasks in the list!\n");
        return;
    }
    
    printf("\n=== TODO LIST ===\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. [%c] %s\n", 
            i + 1, 
            todoList[i].completed ? 'X' : ' ',
            todoList[i].description);
    }
    printf("================\n");
}

int main() {
    int choice;
    char taskDescription[MAX_LENGTH];
    int taskIndex;

    while (1) {
        printf("\n1. Add Task\n");
        printf("2. Mark Task as Complete\n");
        printf("3. Display Tasks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character

        switch (choice) {
            case 1:
                printf("Enter task description: ");
                fgets(taskDescription, MAX_LENGTH, stdin);
                taskDescription[strcspn(taskDescription, "\n")] = 0; // Remove newline
                addTask(taskDescription);
                break;
            case 2:
                printf("Enter task number to mark as complete: ");
                scanf("%d", &taskIndex);
                markAsComplete(taskIndex - 1);
                break;
            case 3:
                displayTasks();
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
