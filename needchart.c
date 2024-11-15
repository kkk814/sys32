#include <stdio.h>


void calculateNeedMatrix(int m, int n, int allocation[m][n], int maximum[m][n], int need[m][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
}


void displayMatrix(int m, int n, int matrix[m][n], const char *name) {
    printf("\n%s Matrix:\n", name);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}


void displayAvailable(int n, int available[n]) {
    printf("\nAvailable Resources:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", available[i]);
    }
    printf("\n");
}

int main() {
    int m, n;

    
    printf("Enter the number of processes: ");
    scanf("%d", &m);
    printf("Enter the number of resource types: ");
    scanf("%d", &n);

    int allocation[m][n], maximum[m][n], need[m][n], available[n];

    
    printf("\nEnter the Allocation matrix (Process x Resource):\n");
    for (int i = 0; i < m; i++) {
        printf("For Process P%d:\n", i + 1);
        for (int j = 0; j < n; j++) {
            printf("Resource R%d: ", j + 1);
            scanf("%d", &allocation[i][j]);
        }
    }

    
    printf("\nEnter the Maximum matrix (Process x Resource):\n");
    for (int i = 0; i < m; i++) {
        printf("For Process P%d:\n", i + 1);
        for (int j = 0; j < n; j++) {
            printf("Resource R%d: ", j + 1);
            scanf("%d", &maximum[i][j]);
        }
    }

    
    printf("\nEnter the Available resources (Resource types):\n");
    for (int i = 0; i < n; i++) {
        printf("Resource R%d: ", i + 1);
        scanf("%d", &available[i]);
    }

    
    calculateNeedMatrix(m, n, allocation, maximum, need);

    
    displayMatrix(m, n, allocation, "Allocation");
    displayMatrix(m, n, maximum, "Maximum");
    displayMatrix(m, n, need, "Need");
    displayAvailable(n, available);

    return 0;
}
