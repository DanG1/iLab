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
    drivel_stk_double *stk = drivel_stk_double_ctor(k);

    drivel_stk_double_dump(stk);

    for (stk_counter = 0; stk_counter < k; stk_counter++)
    {
        printf("%d\n",drivel_stk_double_push(stk, stk_counter)); //Пушаю, дампаю и печатаю код (0 - нормально)
      //  drivel_stk_double_dump(stk);
    }

    drivel_stk_double_swap(stk);

   // drivel_stk_double_dump(stk);
//    if (drivel_stk_double_empty(stk)) drivel_stk_double_delete(stk);

    drivel_stk_double_dump(stk);


    printf("\n\nIs stack empty?: %d\n\n",drivel_stk_double_empty(stk));

while (!drivel_stk_double_empty(stk)) {
        drivel_stk_double_pop(stk);
        printf("\n\nIs stack empty?: %d\n\n", drivel_stk_double_empty(stk));
        }

    return 0;
}
