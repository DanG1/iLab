#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdfix.h>
#include "drivel_stack.h"


int main()
{
    int k=7;
    int stk_counter;
    drivel_stk_double *stk = drivelStkDoubleCtor(k);

    drivelStkDoubleDump(stk);

    for (stk_counter = 0; stk_counter < k; stk_counter++)
    {
        printf("%d\n",drivelStkDoublePush(stk, stk_counter)); //Пушаю, дампаю и печатаю код (0 - нормально)
      //  drivel_stk_double_dump(stk);
    }

    drivelStkDoubleSwap(stk);

   // drivel_stk_double_dump(stk);
//    if (drivel_stk_double_empty(stk)) drivel_stk_double_delete(stk);

    drivelStkDoubleDump(stk);


    printf("\n\nIs stack empty?: %d\n\n",drivelStkDoubleEmpty(stk));

while (!drivelStkDoubleEmpty(stk)) {
        drivelStkDoublePop(stk);
        printf("\n\nIs stack empty?: %d\n\n", drivelStkDoubleEmpty(stk));
        }

drivelStkDoubleDelete(stk);
drivelStkDoubleDump(stk);
    return 0;
}
