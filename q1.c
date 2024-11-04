#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>

struct process{

pid_t pid;
char name[50];
struct process* nextprocess;
struct process* previousprocess;


};

struct process*head = NULL;

void add_process(pid_t pid, const char* name) {
 struct process* new = (struct process*)malloc(sizeof(struct process));
    new->pid = pid;
    strncpy(new->name, name, sizeof(new->name));
    new->nextprocess = NULL; 
    new->previousprocess = NULL; 
    if (head == NULL) {
        head = new;
    } else {
        struct process* temp = head;
        while (temp->nextprocess != NULL) {
            temp = temp->nextprocess;
        }
        temp->nextprocess = new; 
        new->previousprocess = temp; 
    }
}


void remove_process(pid_t pid)
{
     struct process* temp = head;
     while (temp != NULL && temp->pid != pid) {
        temp = temp->nextprocess;
    }

    if (temp == NULL) {
        return 0;
    }

    if (temp == head) {
        head = temp->nextprocess;
        if (head != NULL) {
            head->previousprocess = NULL;
        }
    }
    else {
        if (temp->previousprocess != NULL) {
            temp->previousprocess->nextprocess = temp->nextprocess;
        }
        if (temp->nextprocess != NULL) {
            temp->nextprocess->previousprocess = temp->previousprocess;
        }
    }
}


void display_processes() {
    struct process* temp = head;
    while (temp != NULL) {
        printf("Pid - %d, Name - %s\n", temp->pid, temp->name);
        temp = temp->nextprocess;
    }
}

void terminateprocess(pid_t pid){

remove_process(pid);


};


void move_to_next(struct process* current) {
    if (current != NULL && current->nextprocess != NULL) {
        printf("Pid - %d, Name- %s\n", current->nextprocess->pid, current->nextprocess->name);
    } else {
        printf("Nothing here");
    }
};

void move_to_previous(struct process* current) {
    if (current != NULL && current->previousprocess != NULL) {
        
        printf("Pid - %d, Name: %s\n", current->previousprocess->pid, current->previousprocess->name);
    } else {
        printf("Nothing here");
}
};
int main(){

// only function calls 



}




 











