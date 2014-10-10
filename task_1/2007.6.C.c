#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define SQR(x) ((x)*(x))

/*
int main(){
    printf("%d\n", sizeof(int));
    printf("%d\n", sizeof(long));
    printf("%d\n", sizeof(long int));
    printf("%d\n", sizeof(long long));
    printf("%d\n", sizeof(long long int));
//    printf("%d\n", sizeof(long long long));
    printf("%d\n", sizeof(unsigned int));
    printf("%d\n", sizeof(unsigned long));
    printf("%d\n", sizeof(unsigned long int));
    printf("%d\n", sizeof(unsigned long long));
    printf("%d\n", sizeof(unsigned long long int));
//    printf("%d\n", sizeof(unsigned long long long));
return 0;
}
*/

////// DOES NOT WORK PROPERLY

int contains_squares(int num);

int main(){
    int N, temp, i, shelf_counter;

    scanf("%d", &N);
    int* shelf = (int*) calloc (N, sizeof(int));

    shelf_counter = 0;
    for (i=0; i<N; i++){
        scanf("%d", &temp);

        if (!contains_squares(temp)) {
                shelf[shelf_counter] = temp;
                shelf_counter++;
        }
    }

    for (i=0; i <= (shelf_counter - 1); i++)
        printf ("%d ", shelf[i]);

    free(shelf);

    return 0;
}

int contains_squares(int num){
    int i;

    for (i=2; i <= ceil(sqrt(num)); i++)
        if ( (num % SQR(i)) == 0 ) return i;
    return 0;
}
