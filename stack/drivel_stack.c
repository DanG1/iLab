#ifndef DRIVEL_STACK_C
#define DRIVEL_STACK_C

#include <stdint.h>
#include <stddef.h>
#include "drivel_stack.h"
#include "errlib.h"

drivel_stk_double_t* drivelStkDoubleCtor(int size)
{
    drivel_stk_double_t* stk;
    stk = (drivel_stk_double_t *) calloc(1, sizeof(drivel_stk_double_t));
        stk->size = size;
        stk->data = (stk_value_t*) calloc (size, sizeof(stk_value_t));
        stk->current = stk->data - 1;
    if ((!stk->data)||(!stk->current)) assert ((printf("some prt==0 in drivelStkDoubleCtor"),0));
    return stk;
}

int drivelStkDoubleDelete( drivel_stk_double_t * stk)
{
    stk->current = stk->data - 1;
    free(stk->data);
    free(stk);
    return noERR;
}

int drivelStkDoubleSize( drivel_stk_double_t * stk)
{
    return (stk->current - (stk->data - 1));
}

int drivelStkDoubleEmpty( drivel_stk_double_t * stk)
{
    int empt = (stk->current + 1) == (stk->data);
    return empt;
}

int drivelStkDoublePush( drivel_stk_double_t * stk, stk_value_t data)
{
    int shift;
    ///When everything's OK
    if (stk->current < stk->data + (stk->size - 1)) {
        stk->current++;
        *(stk->current) = data;
        return noERR;
    }

    /// If not enough space
    stk->size = stk->size*2;
    shift = (stk->current) - (stk->data); // Remember the shift (difference)
    if (!realloc(stk->data, stk->size))
        {
            return rlcERR; // If realloc somehow falls down
        }
    stk->current = stk->data + shift; // Restoring stk->current

    /// Pushing as it is OK
    stk->current++;
    *(stk->current) = data;
    return noERR;
}
int drivelStkDoubleSwap( drivel_stk_double_t * stk)
{
    if (stk->current <= stk->data)
        return ptrERR;

    stk_value_t temp;
    temp = *(stk->current);
    *(stk->current) = *(stk->current - 1);
    *(stk->current - 1) = temp;

    return noERR;
}

stk_value_t drivelStkDoubleTop( drivel_stk_double_t * stk)
{
    return *(stk->current);
}

stk_value_t drivelStkDoublePop( drivel_stk_double_t * stk)
{
    /// If stack is empty or smth went wrong
    if (stk->current == stk->data - 1) return ptrERR;
    /// If everything's OK
    (stk->current)--;

    return noERR;
}

void drivelStkDoubleDump( drivel_stk_double_t * stk)
{
    int i;
    printf("\nSlot values from %d to 0:\n", stk->size - 1);
    for (i=0; i < stk->size; i++)
        printf("%lf\t", *(stk->data + (stk->size - 1) - i));
    printf("\nTop significant slot out of [0..%d] is %d\n", stk->size - 1, stk->current - stk->data);
}

#endif
