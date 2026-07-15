#include <stdio.h>
#define MAX_PROCESSES 100
//access struct fields with . operator 
typedef struct{
        int pid;
        int arrivalTime;
        int burstTime;
        int priority;

        int waitingTime; // how long process spends waiting in the ready queue over its entre lifetime
        int turnaroundTime;
        int responseTime; //how long did the process wait before it got the cpu for the very first time
        int completionTime;
    }Process;

int main(){
    printf("Welcome to the CPU scheduler simulator!\n");
    
    //return 0;
    Process processes[MAX_PROCESSES]; //store upto 100 processes 
    int numProcesses = 0;

    FILE *file = fopen("input.txt", "r");
    if(file == NULL){ //if opening file fails print error message and stop the program
        printf("Could not open file\n");
        return 1;
    }
    while(fscanf(file,"%d %d %d %d", 
        &processes[numProcesses].pid, 
        &processes[numProcesses].arrivalTime, 
        &processes[numProcesses].burstTime, 
        &processes[numProcesses].priority) == 4){
     numProcesses++;
    }
    fclose(file);

    


    //printf("Enter the number of processes: ");
    //scanf("%d\n", &numProcesses);


    for(int i = 0; i < numProcesses; i++){
        printf("\nProcess %d\n", i + 1);
        printf("PID: %d\n", processes[i].pid);
        printf("Arrival: %d\n", processes[i].arrivalTime);
        printf("Burst: %d\n", processes[i].burstTime);
        printf("Priority: %d\n", processes[i].priority);
    }

   


    return 0;
}