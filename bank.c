#include <stdio.h>
#include <stdbool.h>

void findSafeSequence(int processes[], int avail[], int max[][10], int allot[][10], int need[][10], int numProcesses, int numResources) {
    bool finish[numProcesses];
    int safeSeq[numProcesses];
    int work[numResources];

    
    for (int i = 0; i < numProcesses; i++) {
        finish[i] = false;
    }
    for (int i = 0; i < numResources; i++) {
        work[i] = avail[i];
    }

    int count = 0;
    while (count < numProcesses) {
        bool found = false;
        for (int p = 0; p < numProcesses; p++) {
            
            if (!finish[p]) {
                bool canAllocate = true;
                for (int r = 0; r < numResources; r++) {
                    if (need[p][r] > work[r]) {
                        canAllocate = false;
                        break;
                    }
                }

                
                if (canAllocate) {
                    
                    for (int r = 0; r < numResources; r++) {
                        work[r] += allot[p][r];
                    }
                    safeSeq[count++] = p;  
                    finish[p] = true;      
                    found = true;
                    break;
                }
            }
        }

        
        if (!found) {
            printf("The system is not in a safe state.\n");
            return;
        }
    }

    
    printf("Safe sequence: ");
    for (int i = 0; i < numProcesses; i++) {
        printf("%d ", safeSeq[i]);
    }
    printf("\n");
}

int main() {
    int numProcesses, numResources;

    
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);
    printf("Enter the number of resources: ");
    scanf("%d", &numResources);

    int avail[numResources];
    int max[numProcesses][numResources];
    int allot[numProcesses][numResources];
    int need[numProcesses][numResources];

    
    printf("Enter the available resources:\n");
    for (int i = 0; i < numResources; i++) {
        printf("Resource %d: ", i);
        scanf("%d", &avail[i]);
    }

    
    printf("Enter the maximum resource matrix:\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("Process %d:\n", i);
        for (int j = 0; j < numResources; j++) {
            printf("Resource %d max: ", j);
            scanf("%d", &max[i][j]);
        }
    }

    
    printf("Enter the allocated resource matrix:\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("Process %d:\n", i);
        for (int j = 0; j < numResources; j++) {
            printf("Resource %d allocated: ", j);
            scanf("%d", &allot[i][j]);
        }
    }

    
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            need[i][j] = max[i][j] - allot[i][j];
        }
    }

    
    findSafeSequence(NULL, avail, max, allot, need, numProcesses, numResources);

    return 0;
}
