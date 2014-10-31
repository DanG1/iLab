#ifndef MY_STACK_H
#define MY_STACK_H
#include <stdint.h>
#include <stddef.h> //reqired for size_t


#define stk_value double

typedef struct
{
    stk_value * data;
    int next;
   //double * stk_ptr;
    int size;
    int last_operation_status;
} drivel_stk_double;

drivel_stk_double* drivel_stk_double_ctor(int size){
    int i;
    drivel_stk_double* stk;
        stk->size = size;
        stk->next = 0;
        stk->data = ( stk_value *) malloc (size* sizeof(stk_value));
    drivel_stk_double_dump(stk);
    if (!stk->data) assert ((printf("errmem in drivel_stk_double_ctor"),0));
    return stk;
}

int drivel_stk_double_delete( drivel_stk_double * this);
size_t drivel_stk_double_size( drivel_stk_double * this);
int drivel_stk_double_empty( drivel_stk_double * this);

int drivel_stk_double_push( drivel_stk_double * stk, stk_value data)
{
    if (stk->next +1 < stk->size)
        {
            stk->data[stk->next] = data;
            (stk->next)++; return 0;
        }
        stk->size = stk->size*2;
    if (!realloc(stk->data, stk->size)) return 77777;
    return 0;
}

void drivel_stk_double_swap( drivel_stk_double * this);

stk_value drivel_stk_double_top( drivel_stk_double * stk)
{
    return stk->data[stk->next - 1];
}

int drivel_stk_double_pop( drivel_stk_double * stk)
{
    if (stk->next == 0) return 777;
    (stk->next)--;

    return 0;
}

void drivel_stk_double_dump( drivel_stk_double * stk)
{
    int i;
    for (i = 0; i < stk->size; i++)
        printf("%d\t", stk->data[(stk->size - 1) - i]);
    printf("\nFirst free slot out of [0..%d] is %d\n", stk->size - 1, stk->next);
}

#endif
