#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int YES = 1;
const int NO = 0;

int if_simple(int n){
    int i;
    int result = YES;

    if (n <= 1) return NO;
    if (n == 2) return YES;
    for (i=2; i <= floor(sqrt(n)); i++){
        if (n%i == 0) result = NO;
    }

    return result;
}

int simple_number_N(int N){
    int i = 0;        // i just goes up until (counter = N)
    int counter = 0;  // counting umber of simple number

    while (counter < N){
            i++;
            if (if_simple(i))
                counter++;
    }

    return i;
}

int main(){
    int N;

    scanf("%d",&N);
    printf("\n\t%d",simple_number_N(N));

    return 0;
}
