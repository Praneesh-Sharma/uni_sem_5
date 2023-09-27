#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the SYMBOL structure
struct SYMBOL {
    char alphabet;
    int frequency;
    struct SYMBOL* left;
    struct SYMBOL* right;
};

// Define a structure for Min-Heap (Priority Queue)
struct MinHeapNode {
    struct SYMBOL* symbol;
};

// Function to create a new MinHeapNode
struct MinHeapNode* createMinHeapNode(struct SYMBOL* symbol) {
    struct MinHeapNode* node = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    node->symbol = symbol;
    return node;
}

// Function to build a Min-Heap
void buildMinHeap(struct MinHeapNode** minHeap, int size) {
    int i = size / 2 - 1;
    for (; i >= 0; i--) {
        int j = i;
        while (1) {
            int smallest = j;
            int left = 2 * j + 1;
            int right = 2 * j + 2;

            if (left < size && minHeap[left]->symbol->frequency < minHeap[smallest]->symbol->frequency)
                smallest = left;

            if (right < size && minHeap[right]->symbol->frequency < minHeap[smallest]->symbol->frequency)
                smallest = right;

            if (smallest != j) {
                struct MinHeapNode* temp = minHeap[j];
                minHeap[j] = minHeap[smallest];
                minHeap[smallest] = temp;
                j = smallest;
            } else {
                break;
            }
        }
    }
}

// Function to extract the minimum node from Min-Heap
struct MinHeapNode* extractMin(struct MinHeapNode** minHeap, int* size) {
    struct MinHeapNode* minNode = minHeap[0];
    minHeap[0] = minHeap[*size - 1];
    (*size)--;
    buildMinHeap(minHeap, *size);
    return minNode;
}

// Function to insert a new node into Min-Heap
void insertMinHeap(struct MinHeapNode** minHeap, int* size, struct MinHeapNode* newNode) {
    (*size)++;
    int i = *size - 1;
    while (i > 0 && newNode->symbol->frequency < minHeap[(i - 1) / 2]->symbol->frequency) {
        minHeap[i] = minHeap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap[i] = newNode;
}

// Function to construct the Huffman tree
struct SYMBOL* buildHuffmanTree(char alphabets[], int frequencies[], int numAlphabets) {
    struct MinHeapNode* minHeap[numAlphabets];
    int heapSize = numAlphabets;

    for (int i = 0; i < numAlphabets; i++) {
        struct SYMBOL* symbol = (struct SYMBOL*)malloc(sizeof(struct SYMBOL));
        symbol->alphabet = alphabets[i];
        symbol->frequency = frequencies[i];
        symbol->left = symbol->right = NULL;
        minHeap[i] = createMinHeapNode(symbol);
    }

    buildMinHeap(minHeap, heapSize);

    while (heapSize > 1) {
        struct MinHeapNode* left = extractMin(minHeap, &heapSize);
        struct MinHeapNode* right = extractMin(minHeap, &heapSize);

        struct SYMBOL* newNode = (struct SYMBOL*)malloc(sizeof(struct SYMBOL));
        newNode->alphabet = '$'; // Internal node symbol
        newNode->frequency = left->symbol->frequency + right->symbol->frequency;
        newNode->left = left->symbol;
        newNode->right = right->symbol;

        insertMinHeap(minHeap, &heapSize, createMinHeapNode(newNode));
    }

    return minHeap[0]->symbol;
}

// Function to perform in-order traversal of Huffman tree
void inorderTraversal(struct SYMBOL* root) {
    if (root) {
        inorderTraversal(root->left);
        if (root->alphabet != '$') // Print only non-internal nodes
            printf("%c ", root->alphabet);
        inorderTraversal(root->right);
    }
}

int main() {
    int numAlphabets;

    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &numAlphabets);

    char alphabets[numAlphabets];
    int frequencies[numAlphabets];

    printf("Enter the alphabets: ");
    for (int i = 0; i < numAlphabets; i++) {
        scanf(" %c", &alphabets[i]); // Note the space before %c to consume newline characters
    }

    printf("Enter its frequencies: ");
    for (int i = 0; i < numAlphabets; i++) {
        scanf("%d", &frequencies[i]);
    }

    struct SYMBOL* root = buildHuffmanTree(alphabets, frequencies, numAlphabets);

    printf("In-order traversal of the tree (Huffman): ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
