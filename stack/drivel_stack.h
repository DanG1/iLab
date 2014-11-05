#ifndef MY_STACK_H
#define MY_STACK_H
#include <stdint.h>
#include <stddef.h> //reqired for size_t


#define stk_value double

typedef struct
{
    stk_value * data;
    stk_value * current;
    int size;
    int last_operation_status;
} drivel_stk_double;

drivel_stk_double* drivel_stk_double_ctor(int size)
{
    drivel_stk_double* stk;
    stk = (drivel_stk_double *) calloc(1, sizeof(drivel_stk_double));
        stk->size = size;
        stk->data = (stk_value*) calloc (size, sizeof(stk_value));
        stk->current = stk->data - 1;
    if ((!stk->data)||(!stk->current)) assert ((printf("some prt==0 in drivel_stk_double_ctor"),0));
    return stk;
}

int drivel_stk_double_delete( drivel_stk_double * stk)
{
    stk->current = stk->data - 1;
    free(stk->data);
    free(stk);
return 0;
}

int drivel_stk_double_size( drivel_stk_double * stk)
{
    return (stk->current - (stk->data - 1));
}

int drivel_stk_double_empty( drivel_stk_double * stk)
{
    int empt = (stk->current + 1) == (stk->data);
    return empt;
}

int drivel_stk_double_push( drivel_stk_double * stk, stk_value data)
{
    int shift;
    ///When everything's OK
    if (stk->current < stk->data + (stk->size - 1)) {
        stk->current++;
        *(stk->current) = data;
        return 0;
    }

    /// If not enough space
    stk->size = stk->size*2;
    shift = (stk->current) - (stk->data); // Remember the shift (difference)
    if (!realloc(stk->data, stk->size))
        {
            return 77777; // If realloc somehow falls down
        }
    stk->current = stk->data + shift; // Restoring stk->current

    /// Pushing as it is OK
    stk->current++;
    *(stk->current) = data;
    return 0;
}

void drivel_stk_double_swap( drivel_stk_double * stk)
{
    stk_value temp;
    temp = *(stk->current);
    *(stk->current) = *(stk->current - 1);
    *(stk->current - 1) = temp;
}

stk_value drivel_stk_double_top( drivel_stk_double * stk)
{
    return *(stk->current);
}

stk_value drivel_stk_double_pop( drivel_stk_double * stk)
{
    /// If stack is empty or smth went wrong
    if (stk->current == stk->data - 1) return 777;
    /// If everything's OK
    (stk->current)--;

    return 0;
}

void drivel_stk_double_dump( drivel_stk_double * stk)
{
    int i;
    printf("\nSlot values from %d to 0:\n", stk->size - 1);
    for (i=0; i < stk->size; i++)
        printf("%lf\t", *(stk->data + (stk->size - 1) - i));
    printf("\nTop significant slot out of [0..%d] is %d\n", stk->size - 1, stk->current - stk->data);
}

#endif
