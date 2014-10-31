#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdfix.h>
#include "drivel_stack.h"


int main()
{
    int stk_counter;
    drivel_stk_double stk = drivel_stk_double_ctor(8);

    for (stk_counter = 0; stk_counter < 8; stk_counter++)
    {
        drivel_stk_double_push(&stk, stk_counter);
    }

    for (stk_counter = 0; stk_counter < 8; stk_counter++)
    {
        printf("%g\n",drivel_stk_double_top(&stk));
        drivel_stk_double_pop(&stk);
    }



    return 0;
}
