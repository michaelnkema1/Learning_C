#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASK_LENGTH 100
#define FILENAME "tasks.txt"

void Addtask();
void Viewtasks();
void Deletetask();
void SavetaskstoFile();
void LoadtasksfromFile();

struct Task {
    char description[MAX_TASK_LENGTH];
    int completed;
};

struct Task tasks[100];
int taskCount = 0;

int main() {
    int choice;
    
    LoadtasksfromFile();
    
    while(1) {
        printf("\n=== To-Do List Manager ===\n");
        printf("1. Add New Task\n");
        printf("2. View Saved Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        
        switch(choice) {
            case 1:
                Addtask();
                break;
            case 2:
                Viewtasks();
                break;
            case 3:
                Deletetask();
                break;
            case 4:
                SavetaskstoFile();
                printf("See you later!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

void Addtask() 
{
    printf("Enter task: ");
    fgets(tasks[taskCount].description, MAX_TASK_LENGTH, stdin);
    tasks[taskCount].description[strcspn(tasks[taskCount].description, "\n")] = 0;
    tasks[taskCount].completed = 0;
    taskCount++;
    
    SavetaskstoFile();
    printf("Task added!\n");
}

void Viewtasks() 
{
    printf("\nSaved Tasks:\n");
    for(int i = 0; i < taskCount; i++) 
    {
        printf("%d. [%c] %s\n", i + 1, 
               tasks[i].completed ? 'X' : ' ',
               tasks[i].description);
    }
}

void Deletetask() 
{
    int taskNum;
    
    Viewtasks();
    if(taskCount == 0) return;
    
    printf("Enter task number to delete (1-%d): ", taskCount);
    scanf("%d", &taskNum);
    getchar();
    
    if(taskNum < 1 || taskNum > taskCount) {
        printf("Invalid task number!\n");
        return;
    }
    
    for(int i = taskNum - 1; i < taskCount - 1; i++) {
        strcpy(tasks[i].description, tasks[i + 1].description);
        tasks[i].completed = tasks[i + 1].completed;
    }
    taskCount--;
    
    SavetaskstoFile();
    printf("Task deleted!\n");
}

void SavetaskstoFile() 
{
    FILE *file = fopen(FILENAME, "w");

    for(int i = 0; i < taskCount; i++) {
        fprintf(file, "%d|%s\n", tasks[i].completed, tasks[i].description);
    }
    
    fclose(file);
}

void LoadtasksfromFile() 
{
    FILE *file = fopen(FILENAME, "r");
    if(file == NULL) {
        return;
    }
    
    char line[MAX_TASK_LENGTH + 3];
    taskCount = 0;
    
    while(fgets(line, sizeof(line), file) && taskCount < 100) {
        tasks[taskCount].completed = line[0] - '0';
        strcpy(tasks[taskCount].description, line + 2);
        tasks[taskCount].description[strcspn(tasks[taskCount].description, "\n")] = 0;
        taskCount++;
    }
    
    fclose(file);
}
