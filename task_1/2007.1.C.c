#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// DOES NOT WORK at N > 2

const int  NO = 0;
const int  YES = 1;

int if_measures_with_4(int n){
    if (n==1) return YES;
    if (((n%4)==1)||((n%4)==0)) return if_measures_with_4(n%4);
    if ((n%4)==3) return if_measures_with_4((n%4)+1);
    return NO;
}

int main(){
    int k; //int i;

    scanf("%d",&k);
    printf("\t%d",if_measures_with_4(k));

    return 0;
}
