#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define SQR(x) ((x)*(x))

// I REALLY have no idea, why it works like a program WITHOUT code!

int main(){
    int i, j, N;
    long long Sum;

    scanf("%n", &N);
    int** matrix = (int**) calloc (SQR(N), sizeof(int));

    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
            scanf("%d", &matrix[i][j]);

    for (i = N-1; i>=0; i--){
        Sum = 0;
        for (j = (N-1)-i; j>=(N-1); j++)
            Sum =+ matrix[j][N-j];
        printf("%I64d ",Sum);
    }

    for (i = 1; i < N; i++){
        Sum = 0;
        for (j = (N-1)-i; j>0; j--)
            Sum =+ matrix[j+1][i+j-1];
        printf("%I64d ", Sum);
    }

    free(matrix);

    return 0;
}
