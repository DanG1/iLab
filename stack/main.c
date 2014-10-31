#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdfix.h>
#include "drivel_stack.h"


int main()
{
    int k=5;
    int stk_counter;
    drivel_stk_double *stk = drivel_stk_double_ctor(k);

  //  drivel_stk_double_dump(&stk);

    for (stk_counter = 0; stk_counter < k; stk_counter++)
    {
        printf("%d\n",drivel_stk_double_push(stk, stk_counter)); //Пушаю и печатаю код (0 - нормально)
        drivel_stk_double_dump(stk);
    }

 //   drivel_stk_double_dump(&stk);
     printf("\n");

    {
  //      printf("%g\n",drivel_stk_double_top(&stk)); //смотрю верхний элемент

   //     printf("%d\n",drivel_stk_double_pop(&stk)); //передвигаю указатель влево и печатаю код выполнения
                                                    //(0 - нормально, 777 - стэк уже пустой)
    }

    return 0;
}
