/*Write a menu driven program to sort list of array elements using Merge
Sort technique and calculate the execution time only to sort the elements. Count the number of comparisons.*/
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int lower, int middle, int upper) {
    int i, j, k;
    int n1 = middle - lower + 1;
    int n2 = upper - middle;
    int L[n1], R[n2];
    
    for (i = 0; i < n1; i++)
        L[i] = arr[lower + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];
    
    i = 0;
    j = 0;
    k = lower;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int lower, int upper) {
    if (lower < upper) {
        // comp++;
        int middle = lower + (upper - lower) / 2;
        mergeSort(arr, lower, middle);
        mergeSort(arr, middle + 1, upper);
        merge(arr, lower, middle, upper);
    }
}

void calculateExecutionTime(int arr[], int n) {
    clock_t start, end;
    double cpu_time_used;
    
    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("Execution time: %f seconds\n", cpu_time_used);
}

int readInputFile(int arr[], int n, char *filename) {
    FILE *fp = fopen(filename, "r");
    
    if (fp == NULL) {
        printf("Error opening file\n");
    }
    
    int num;
    n=0;
    printf("Before sorting: ");
    while (fscanf(fp, "%d", &num) == 1) {
        printf("%d ", num);
        arr[n++] = num;
    }
    printf("\n");
    
    fclose(fp);
    
    return n;
}

void writeOutputFile(int arr[], int n, char *filename) {
    FILE *ptr = fopen(filename, "w");
    
    if (ptr == NULL) {
        printf("Error opening file\n");
    }
    
    printf("After sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        fprintf(ptr, "%d ", arr[i]);
    }
    printf("\n");
    fclose(ptr);
}

int main() {
    int arr[1000];
    int n;
    int choice;
    
    while (1) {
        printf("1. Ascending data\n");
        printf("2. Descending data\n");
        printf("3. Random data\n");
        printf("4. Error(Exit)\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        
        switch (choice) {
            case 1:
                n = readInputFile(arr, n, "inAsce.csv");
                calculateExecutionTime(arr, n);
                writeOutputFile(arr, n, "outMergeAsc.dat");
                break;
            case 2:
                readInputFile(arr, n, "inDesc.csv");
                calculateExecutionTime(arr, n);
                writeOutputFile(arr, n, "outMergeDesc.dat");
                break;
            case 3:
                readInputFile(arr, n, "inRand.dat");
                calculateExecutionTime(arr, n);
                writeOutputFile(arr, n, "outMergeRand.dat");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
        
        printf("\n");
    }
    
    return 0;
}

