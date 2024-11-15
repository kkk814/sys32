#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int at[], int wt[], int tq) {
    int remaining_bt[n];
    int remaining_time = 0;

    
    for (int i = 0; i < n; i++) {
        remaining_bt[i] = bt[i];
    }

    int time = 0;  
    int done = 0;  
    int last_completed_time = 0;  

    while (done < n) {
        int progress = 0;

        for (int i = 0; i < n; i++) {
            
            if (remaining_bt[i] > 0 && at[i] <= time) {
                progress = 1;
                
                if (remaining_bt[i] > tq) {
                    remaining_bt[i] -= tq;
                    time += tq;
                } else {
                    time += remaining_bt[i];
                    wt[i] = time - bt[i] - at[i];  
                    remaining_bt[i] = 0;  
                    done++;  
                }
            }
        }

        
        if (!progress) {
            time++;
        }
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void findAverageTime(int processes[], int n, int bt[], int at[], int tq) {
    int wt[n], tat[n];

    
    findWaitingTime(processes, n, bt, at, wt, tq);
    findTurnAroundTime(processes, n, bt, wt, tat);

    int total_wt = 0, total_tat = 0;

    
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], at[i], bt[i], wt[i], tat[i]);
    }

    
    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time: %.2f", (float)total_tat / n);
}

int main() {
    int n, tq;

    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time quantum: ");
    scanf("%d", &tq);

    int processes[n], burst_time[n], arrival_time[n];

    
    printf("Enter the arrival times and burst times for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i] = i;  
        printf("Process %d\n", i);
        printf("Arrival Time: ");
        scanf("%d", &arrival_time[i]);
        printf("Burst Time: ");
        scanf("%d", &burst_time[i]);
    }

    
    findAverageTime(processes, n, burst_time, arrival_time, tq);

    return 0;
}
