#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n) {
    int i, key, j, comparisons = 0;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            comparisons++;
        }
        arr[j + 1] = key;
    }
    printf("Number of comparisons: %d\n", comparisons);
}

int main() {
    int i, choice;
    FILE *inputFile, *outputFile;
    printf("Enter your choice:\n1. Ascending order\n2. Descending order\n3. Random data\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            inputFile = fopen("inAsce.csv", "r");
            outputFile = fopen("outInsAsce.csv", "w");
            break;
        case 2:
            inputFile = fopen("inDesc.csv", "r");
            outputFile = fopen("outInsDesc.csv", "w");
            break;
        case 3:
            inputFile = fopen("inRand.dat", "r");
            outputFile = fopen("outInsRand.dat", "w");
            break;
        default:
            printf("Invalid choice\n");
            return 0;
    }
    int n = 0, num;
    while (fscanf(inputFile, "%d", &num) == 1) {
        n++;
    }
    rewind(inputFile);
    int arr[n];
    for (i = 0; i < n; i++) {
        fscanf(inputFile, "%d", &arr[i]);
    }
    insertionSort(arr, n);
    for (i = 0; i < n; i++) {
        fprintf(outputFile, "%d ", arr[i]);
    }
    fclose(inputFile);
    fclose(outputFile);
    outputFile = fopen("outInsAsce.dat", "r");
    printf("Sorted elements:\n");
    for (i = 0; i < n; i++) {
        fscanf(outputFile, "%d", &arr[i]);
        printf("%d ", arr[i]);
    }
    fclose(outputFile);
    return 0;
}

