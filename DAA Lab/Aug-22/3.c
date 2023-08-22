/*Write a menu driven program to sort a list of elements in ascending
order using Quick Sort technique. Each choice for the input data has its own disc file. A separate
output file can be used for sorted elements. After sorting display the content of the output file
along with number of comparisons. Based on the partitioning position for each recursive call,
conclude the input scenario is either best-case partitioning or worst-case partitioning.*/
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high, int* comparisons) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        (*comparisons)++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int* comparisons) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons);
        quickSort(arr, low, pi - 1, comparisons);
        quickSort(arr, pi + 1, high, comparisons);
    }
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    FILE *inputFile, *outputFile;
    int arr[500];  // Maximum array size
    int comparisons = 0;

    printf("Menu:\n");
    printf("1. Ascending Order\n");
    printf("2. Descending Order\n");
    printf("3. Random Data\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            inputFile = fopen("inAsce.dat", "r");
            outputFile = fopen("outQuickAsce.dat", "w");
            break;
        case 2:
            inputFile = fopen("inDesc.dat", "r");
            outputFile = fopen("outQuickDesc.dat", "w");
            break;
        case 3:
            inputFile = fopen("inRand.dat", "r");
            outputFile = fopen("outQuickRand.dat", "w");
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    int n;
    fscanf(inputFile, "%d", &n);
    for (int i = 0; i < n; i++) {
        fscanf(inputFile, "%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1, &comparisons);

    printf("Sorted array: ");
    displayArray(arr, n);
    printf("Number of comparisons: %d\n", comparisons);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
