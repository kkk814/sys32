#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int at[], int wt[]) {
    wt[0] = 0; 

    
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1] + at[i - 1] - at[i];
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void findAverageTime(int processes[], int n, int bt[], int at[]) {
    int wt[n], tat[n];
    
    findWaitingTime(processes, n, bt, at, wt);
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
    int n;

    
    printf("Enter the number of processes: ");
    scanf("%d", &n);

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

    
    findAverageTime(processes, n, burst_time, arrival_time);

    return 0;
}
