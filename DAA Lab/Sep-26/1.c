#include <stdio.h>
#include <stdlib.h>

struct item{
    int item_id;
    double item_profit;
    double item_weight;
    double profit_weight_ratio;
};

void heapify(struct item items[], int n, int i){
    int largest=i;
    int left = 2*i+1;
    int right = 2*i+2;
    
    if(left < n && items[left].profit_weight_ratio > items[largest].profit_weight_ratio)
        largest=left;
        
    if(right < n && items[right].profit_weight_ratio > items[largest].profit_weight_ratio)
        largest=right;
        
    if (largest != i){
        struct item temp = items[i];
        items[i] = items[largest];
        items[largest] = temp;
        
        heapify(items, n , largest);
    }
}

void heapSort(struct item items[], int n){
    for(int i=n/2-1; i>=0; i--)
        heapify(items, n, i);
    
    
    for(int i=n-1; i>=0; i--){
        struct item temp = items[0];
        items[0] = items[i];
        items[i] = temp;
        
        heapify(items, i, 0);
    }
}

int main(){
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    struct item items[n];
    for(int i=0; i<n; i++){
        items[i].item_id = i+1;
        printf("Enter the profit and weight of item no %d: ", i+1);
        scanf("%lf %lf", &items[i].item_profit, &items[i].item_weight);
        items[i].profit_weight_ratio = items[i].item_profit / items[i].item_weight;
    }
    
    double capacity;
    printf("Enter the capacity of knapsack: ");
    scanf("%lf", &capacity);
    
    heapSort(items, n);
    
    double maxProfit = 0;
    printf("Item No Profit Weight Amount to be taken\n");
    for(int i=0; i<n; i++){
        if(capacity >= items[i].item_weight){
        printf("%d %.6lf %.6lf 1.000000\n", items[i].item_id, items[i].item_profit, items[i].item_weight);
        maxProfit += items[i].item_profit;
        capacity -= items[i].item_weight;
        }
        else{
            double fraction = capacity / items[i].item_weight;
            printf("%d %.6lf %.6lf %.6lf\n", items[i].item_id, items[i].item_profit, items[i].item_weight, fraction);
            maxProfit += (fraction * items[i].item_profit);
            break;
        }
    }
    
    printf("Maximum profit: %.6lf\n", maxProfit);
    
    return 0;
}
