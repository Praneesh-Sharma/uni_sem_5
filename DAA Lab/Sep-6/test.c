#include <stdio.h>

int main(){
    int N, flag=10000000, index=0;
    printf("Enter N: ");
    scanf("%d", &N);
    int ARR[N];
    
    for(int i=0; i<N; i++){
        printf("Enter element %d : ", i+1);
        scanf("%d", &ARR[i]);
        
        if(ARR[i]<flag){
            index = i;
            flag = ARR[i];
        }
    }
    
    printf("Number of right rotations: %d\n", index);

    return 0;
}
