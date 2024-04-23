#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Todo {
    char *buffer;
    int count;
    char *date;
    int completed;
    struct Todo *next;
} Todo;

Todo *start = NULL;
const char *FILENAME = "todo_data.txt";

void loadTasksFromFile() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) return;

    char line[512];
    while (fgets(line, sizeof(line), file)) {
        Todo *add = malloc(sizeof(Todo));
        sscanf(line, "%d %d %s %[^\n]", &add->count, &add->completed, add->date, add->buffer);
        add->buffer = strdup(add->buffer);
        add->date = strdup(add->date);

        if (!start) {
            start = add;
            add->next = NULL;
        } else {
            Todo *temp = start;
            while (temp->next) temp = temp->next;
            temp->next = add;
            add->next = NULL;
        }
    }
    fclose(file);
}

void saveTasksToFile() {
    FILE *file = fopen(FILENAME, "w");
    Todo *temp = start;
    while (temp) {
        fprintf(file, "%d %d %s %s\n", temp->count, temp->completed, temp->date, temp->buffer);
        temp = temp->next;
    }
    fclose(file);
}

void cleanupMemory() {
    Todo *temp = start;
    while (temp) {
        Todo *next = temp->next;
        free(temp->buffer);
        free(temp->date);
        free(temp);
        temp = next;
    }
}

void interface() {
    system("color 4F");
    printf("\n\n\n\n");
    printf("\t~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~\n");
    // ...
}

int main() {
    loadTasksFromFile();

    int choice;
    while (1) {
        system("cls");
        printf("1. Login\n");
        printf("2. Register\n");
        printf("3. Exit\n");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // login logic
                break;
            case 2:
                // register logic
                break;
            case 3:
                saveTasksToFile();
                cleanupMemory();
                exit(0);
                break;
        }

        while (1) {
            system("cls");
            printf("1. See ToDo list\n");
            printf("2. Create new ToDo\n");
            printf("3. Update ToDo\n");
            printf("4. Delete ToDo\n");
            printf("5. Exit\n");
            printf("6. Mark as completed\n");
            printf("7. See upcoming tasks\n");
            printf("8. See completed tasks\n");
            printf("9. See tasks for date\n");

            printf("\n\nEnter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    seeToDo();
                    break;
                case 2:
                    createToDo();
                    break;
                case 3:
                    updateToDo();
                    break;
                case 4:
                    deleteToDo();
                    break;
                case 5:
                    saveTasksToFile();
                    cleanupMemory();
                    exit(0);
                    break;
                case 6:
                    markCompleted();
                    break;
                case 7:
                    checkUpcomingTasks();
                    break;
                case 8:
                    checkCompletedTasks();
                    break;
                case 9:
                    checkTasksForDate();
                    break;
            }
        }
    }

    return 0;
}

void seeToDo() {
    system("cls");
    Todo *temp = start;
    printf("ToDo list...\n\n");
    while (temp) {
        printf("%d. %s (Date: %s)\n", temp->count, temp->buffer, temp->date);
        temp = temp->next;
    }
    printf("\n\n\n");
    system("pause");
}

void createToDo() {
    char c;
    Todo *add;
    system("cls");

    while (1) {
        printf("Want to add a new ToDo? Press 'y' for Yes and 'n' for No: ");
        fflush(stdin);
        scanf(" %c", &c);

        if (c == 'n')
            break;

        add = malloc(sizeof(Todo));
        add->completed = 0;

        printf("Enter the task content: ");
        add->buffer = malloc(201);
        fflush(stdin);
        scanf(" %200[^\n]", add->buffer);

        printf("Enter the task date (YYYY-MM-DD): ");
        add->date = malloc(11);
        fflush(stdin);
        scanf(" %10s", add->date);

        if (!start) {
            start = add;
            add->count = 1;
            start->next = NULL;
        } else {
            Todo *temp = start;
            while (temp->next) temp = temp->next;
            temp->next = add;
            add->count = temp->count + 1;
            add->next = NULL;
        }
    }
    adjustcount();
}

void updateToDo() {
    int taskNumber;
    Todo *temp = start;

    system("cls");
    if (!start)
        printf("List is empty.....\n\n\n");

    else {
        seeToDo();

        printf("Enter the ToDo number you want to update: ");
        scanf("%d", &taskNumber);
        while (temp) {
            if (temp->count == taskNumber) {
                printf("Enter the updated task: ");
                temp->buffer = malloc(201);
                fflush(stdin);
                scanf(" %200[^\n]", temp->buffer);

                printf("Enter the updated date (YYYY-MM-DD): ");
                temp->date = malloc(11);
                fflush(stdin);
                scanf(" %10s", temp->date);
                break;
            }
            temp = temp->next;
        }
    }

    system("pause");
}

void deleteToDo() {
    system("cls");
    int x;
    Todo *del, *temp;

    if (!start)
        printf("No tasks in your ToDo list.\n\n\n");

    else {
        seeToDo();

        printf("Enter the ToDo's number that you want to remove: ");
        scanf("%d", &x);
        del = start;
        temp = start->next;

        while (1) {
            if (del->count == x) {
                start = start->next;
                free(del->buffer);
                free(del->date);
                free(del);
                adjustcount();
                break;
            }
            if (temp->count == x) {
                del->next = temp->next;
                free(temp->buffer);
                free(temp->date);
                free(temp);
                adjustcount();
                break;
            }
            else {
                del = temp;
                temp = temp->next;
            }
        }
    }
    system("pause");
}

void adjustcount() {
    Todo *temp = start;
    int i = 1;
    while (temp) {
        temp->count = i;
        i++;
        temp = temp->next;
    }
}

void markCompleted() {
    int taskNumber;
    Todo *temp = start;

    system("cls");
    if (!start)
        printf("List is empty.....\n\n\n");

    else {
        seeToDo();

        printf("Enter the ToDo number you want to mark as completed: ");
        scanf("%d", &taskNumber);
        while (temp) {
            if (temp->count == taskNumber)
                temp->completed = 1;
            temp = temp->next;
        }
    }

    system("pause");
}

void checkUpcomingTasks() {
    system("cls");
    Todo *temp = start;
    printf("Upcoming tasks...\n\n");

    if (!start)
        printf("No tasks in your ToDo list.\n\n");

    else {
        while (temp) {
            if (!temp->completed) {
                printf("%d. %s (Date: %s)\n", temp->count, temp->buffer, temp->date);
            }
            temp = temp->next;
        }
    }

    printf("\n\n\n");
    system("pause");
}

void checkCompletedTasks() {
    system("cls");
    Todo *temp = start;
    printf("Completed tasks...\n\n");

    if (!start)
        printf("No tasks in your ToDo list.\n\n");

    else {
        while (temp) {
            if (temp->completed) {
                printf("%d. %s (Date: %s)\n", temp->count, temp->buffer, temp->date);
            }
            temp = temp->next;
        }
    }

    printf("\n\n\n");
    system("pause");
}

void checkTasksForDate() {
    char targetDate[11];
    system("cls");
    Todo *temp = start;
    printf("Enter the date (YYYY-MM-DD): ");
    scanf(" %10s", targetDate);
    printf("Tasks for %s...\n\n", targetDate);

    if (!start)
        printf("No tasks in your ToDo list.\n\n");

    else {
        while (temp) {
            if (!strcmp(temp->date, targetDate)) {
                printf("%d. %s (Date: %s)\n", temp->count, temp->buffer, temp->date);
            }
            temp = temp->next;
        }
    }

    printf("\n\n\n");
    system("pause");
}
