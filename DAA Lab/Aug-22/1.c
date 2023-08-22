/*Write a program to implement Binary Search to give the position of
leftmost appearance of the element in the array being searched. Display the number of
comparisons made while searching.*/
#include <stdio.h>

int main(){
    int lower, upper, mid, num, key, arr[20], flag=0;
    printf("Enter size of array: ");
    scanf("%d",&num);
    
    printf("Enter elements of the array: ");
    for(int i = 0; i < num; i++)
        scanf("%d", &arr[i]);
    
    printf("Enter the key to be searched: ");
    scanf("%d", &key);
    
    lower = 0;
    upper = num - 1;
    mid = (lower+upper)/2;
    
    while (lower <= upper) {
        flag++;
        if(arr[mid] < key)
            lower = mid + 1;
        else if (arr[mid] == key) {
            printf("\n%d found at index position: %d \n", key, mid);
            printf("Number of comparisions: %d\n", flag);
            break;
        }
        else
            upper = mid - 1;
        mid = (lower + upper)/2;
    }
    
    if(lower > upper)
    printf("Not found! %d isn't present in the list\n", key);

    return 0;
}
