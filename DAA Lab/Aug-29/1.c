#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

// Function to create a person
struct person createPerson(int id, char *name, int age, int height, int weight) {
    struct person p;
    p.id = id;
    p.name = name;
    p.age = age;
    p.height = height;
    p.weight = weight;
    return p;
}

// Function to display the weight of the youngest person
void displayWeightOfYoungest(struct person *people, int n) {
    int youngestIndex = 0;
    for (int i = 1; i < n; i++) {
        if (people[i].age < people[youngestIndex].age) {
            youngestIndex = i;
        }
    }
    float weightInKg = people[youngestIndex].weight * 0.453592;
    printf("Weight of the youngest person: %.2f kg\n", weightInKg);
}

// Function to insert a new person into the min-heap
void insertPerson(struct person *people, int *n, struct person newPerson) {
    (*n)++;
    int i = *n - 1;
    while (i > 0 && newPerson.age < people[(i - 1) / 2].age) {
        people[i] = people[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    people[i] = newPerson;
}

// Function to delete the oldest person from the min-heap
void deleteOldestPerson(struct person *people, int *n) {
    if (*n == 0) {
        printf("Heap is empty\n");
        return;
    }
    struct person oldestPerson = people[0];
    people[0] = people[*n - 1];
    (*n)--;
    int i = 0;
    while (1) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        int smallest = i;
        if (leftChild < *n && people[leftChild].age < people[smallest].age) {
            smallest = leftChild;
        }
        if (rightChild < *n && people[rightChild].age < people[smallest].age) {
            smallest = rightChild;
        }
        if (smallest != i) {
            struct person temp = people[i];
            people[i] = people[smallest];
            people[smallest] = temp;
            i = smallest;
        } else {
            break;
        }
    }
    printf("Deleted the oldest person with ID %d\n", oldestPerson.id);
}

int main() {
    int option, n = 0;
    struct person *people = malloc(500 * sizeof(struct person));

    do {
        printf("\nMAIN MENU (HEAP)\n");
        printf("1. Read Data\n");
        printf("2. Create a Min-heap based on the age\n");
        printf("3. Create a Max-heap based on the weight\n");
        printf("4. Display weight of the youngest person\n");
        printf("5. Insert a new person into the Min-heap\n");
        printf("6. Delete the oldest person\n");
        printf("7. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1: {
                // Read data from file and store in the dynamically allocated array
                FILE *file = fopen("data.txt", "r");
                if (file == NULL) {
                    printf("Error opening file\n");
                    break;
                }
                int id, age, height, weight;
                char name[100];
                int i = 0;
                while (fscanf(file, "%d %s %d %d %d", &id, name, &age, &height, &weight) != EOF) {
                    people[i] = createPerson(id, strdup(name), age, height, weight);
                    i++;
                }
                n = i;
                fclose(file);
                printf("Data read successfully\n");
                break;
            }
            case 2: {
                // Create a min-heap based on the age
                for (int i = n / 2 - 1; i >= 0; i--) {
                    int parent = i;
                    while (1) {
                        int leftChild = 2 * parent + 1;
                        int rightChild = 2 * parent + 2;
                        int smallest = parent;
                        if (leftChild < n && people[leftChild].age < people[smallest].age) {
                            smallest = leftChild;
                        }
                        if (rightChild < n && people[rightChild].age < people[smallest].age) {
                            smallest = rightChild;
                        }
                        if (smallest != parent) {
                            struct person temp = people[parent];
                            people[parent] = people[smallest];
                            people[smallest] = temp;
                            parent = smallest;
                        } else {
                            break;
                        }
                    }
                }
                printf("Min-heap based on age created\n");
                break;
            }
            case 3: {
                // Create a max-heap based on the weight
                for (int i = n / 2 - 1; i >= 0; i--) {
                    int parent = i;
                    while (1) {
                        int leftChild = 2 * parent + 1;
                        int rightChild = 2 * parent + 2;
                        int largest = parent;
                        if (leftChild < n && people[leftChild].weight > people[largest].weight) {
                            largest = leftChild;
                        }
                        if (rightChild < n && people[rightChild].weight > people[largest].weight) {
                            largest = rightChild;
                        }
                        if (largest != parent) {
                            struct person temp = people[parent];
                            people[parent] = people[largest];
                            people[largest] = temp;
                            parent = largest;
                        } else {
                            break;
                        }
                    }
                }
                printf("Max-heap based on weight created\n");
                break;
            }
            case 4: {
                // Display weight of the youngest person
                displayWeightOfYoungest(people, n);
                break;
            }
            case 5: {
                // Insert a new person into the min-heap
                int id, age, height, weight;
                char name[100];
                printf("Enter the ID: ");
                scanf("%d", &id);
                printf("Enter the name: ");
                scanf("%s", name);
                printf("Enter the age: ");
                scanf("%d", &age);
                                printf("Enter the height: ");
                scanf("%d", &height);
                printf("Enter the weight: ");
                scanf("%d", &weight);
                struct person newPerson = createPerson(id, strdup(name), age, height, weight);
                insertPerson(people, &n, newPerson);
                printf("Person inserted into the Min-heap\n");
                break;
            }
            case 6: {
                // Delete the oldest person from the min-heap
                deleteOldestPerson(people, &n);
                break;
            }
            case 7: {
                // Exit the program
                printf("Exiting...\n");
                break;
            }
            default:
                printf("Invalid option\n");
                break;
        }
    } while (option != 7);

    // Free the dynamically allocated memory
    for (int i = 0; i < n; i++) {
        free(people[i].name);
    }
    free(people);

    return 0;
}


