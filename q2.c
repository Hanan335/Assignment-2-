#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>

struct process{

pid_t pid;
char name[50];
struct process* nextprocess;
struct process* previousprocess;
int state;
};

struct process*control = NULL;
struct process*readyqueue;
struct process*waitqueue;




void add_process_to_ready_queue(struct process*new) {

new->state = 1;
if(readyqueue == NULL ){
readyqueue = new;
}
else{
  struct process*temp = readyqueue;

 while(temp->nextprocess != NULL){
    temp = temp->nextprocess;
 }

temp->nextprocess = new;
new->previousprocess = temp;

}

new->nextprocess = NULL;
}



void add_process_to_wait_queue(struct process*new){

new->state = 0;
if(waitqueue == NULL ){
    readyqueue = new;
}
else{
  struct process*temp = waitqueue;

 while(temp->nextprocess != NULL){
    temp = temp->nextprocess;
 }

temp->nextprocess = new;
new->previousprocess = temp;

}

new->nextprocess = NULL;
}



void return_to_ready_queue(){

if(waitqueue == NULL){
return 0;
}

else{

struct process*temp = waitqueue;

 waitqueue = waitqueue->nextprocess; 
        if (waitqueue != NULL) {
            waitqueue->previousprocess = NULL;

}
temp->state = 0  ;     /// ready
add_process_to_ready_queue(temp);

}

}



void simulateprocess(){
if(readyqueue == 0){
   return 0;
}
control =  readyqueue;
readyqueue = readyqueue->nextprocess;
    if (readyqueue != NULL) {
        readyqueue->previousprocess = NULL;
    }
   control->state =  1;  // Running state
};




void interruptprocess(){
if(readyqueue == 0){
   return 0;
}
control =  readyqueue;
readyqueue = readyqueue->nextprocess;
    if (readyqueue != NULL) {
        readyqueue->previousprocess = NULL;
    }
   control->state =  1;  // Running state
};




void terminateprocess(){

 if (control == NULL) {
        return 0;
    }
    control = NULL;

}



// Process flow simulation
void process_flow_simulation() {
    struct process* simulation = (struct process*)malloc(sizeof(struct process));
    
    add_process_to_ready_queue(simulation);

    simulateprocess();

    add_process_to_wait_queue(control);

    control = NULL;

    return_to_ready_queue();

    simulateprocess();

 
    interruptprocess();

    simulateprocess();   /// execution for next 

    terminate_process();
}










































