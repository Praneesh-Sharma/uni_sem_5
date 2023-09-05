#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* ARR[]){
    int i=1;
    
    for(int j=0; j<argc; j++){
        printf("%s\n", ARR[j]);
    } 
    
    while(atoi(ARR[i])<atoi(ARR[i+1])){
        i++;
    }
    
    printf("%d\n", i);

    return 0;
}
