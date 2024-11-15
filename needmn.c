#include <stdio.h>

void calculateNeedMatrix(int m, int n, int allocation[m][n], int maximum[m][n], int need[m][n]) {
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
}

void displayMatrix(int m, int n, int matrix[m][n]) {
    printf("\nNeed Matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m, n;

    
    printf("Enter the number of processes: ");
    scanf("%d", &m);
    printf("Enter the number of resource types: ");
    scanf("%d", &n);

    int allocation[m][n], maximum[m][n], need[m][n];

    
    printf("\nEnter the Allocation matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Allocation[%d][%d]: ", i, j);
            scanf("%d", &allocation[i][j]);
        }
    }

    
    printf("\nEnter the Maximum matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Maximum[%d][%d]: ", i, j);
            scanf("%d", &maximum[i][j]);
        }
    }

    
    calculateNeedMatrix(m, n, allocation, maximum, need);

    
    displayMatrix(m, n, need);

    return 0;
}
