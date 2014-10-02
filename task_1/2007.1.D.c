#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int lastNonEmptyK(int n){
    int k;

    k = floor(n/2) + n%2;
    if (k < 0) k=0;

    return k;
}


int b(int n, int k){
    int result;

    if (k == 0){
            result = 1;
    } else {
            if(k > lastNonEmptyK(n)){
                    result = 0;
            } else {
                    result = b(n-1,k) + b(n-2,k-1);
            }

    }
    return result;
}

void printTableOfReplaceVariants(int N){
    int n,k; //int i;


    for (n=0; n <= N; n++){
        for (k=0; k <= lastNonEmptyK(n); k++){
            printf("%4d", b(n,k));
        };
        printf("\n");
    }

}

//DO NOT KNOW, WHETHER I NEED THESE DEBUGGING PEACES OF COMMITTED CODE:


int main(){
    int N;

    scanf("%d",&N);
    printTableOfReplaceVariants(N);

    return 0;
}

