#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int  NO = 0;
const int  YES = 1;

int if_measures_with_4(int n){
    if (n==1) return YES;
    if (((n%4)==1)||((n%4)==0)) return if_measures_with_4(floor(n/4));
    if ((n%4)==3) return if_measures_with_4(floor(n/4)+1);
    return NO;
}

char* logic_to_word(int logic){
    if (logic){
            return "YES";
            } else {
            return "NO";
            }
}

int main(){
    int k; //int i;

    scanf("%d",&k);
    printf("\t%s",logic_to_word(if_measures_with_4(k)));

    return 0;
}
