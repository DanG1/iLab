#ifndef DRIVEL_STACK_H
#define DRIVEL_STACK_H

#include <stdint.h>
#include <stddef.h> //reqired for size_t
#include <assert.h>
#include <stdio.h>
#include <malloc.h>
#include "errlib.h"
//#include

//#define stk_value_t double


typedef double stk_value_t;
typedef struct
{
    stk_value_t * data;
    stk_value_t * current;
    int size;
    int last_operation_status;
} drivel_stk_double_t;

drivel_stk_double_t* drivelStkDoubleCtor(int size);

int drivelStkDoubleDelete( drivel_stk_double_t * stk);

int drivelStkDoubleSize( drivel_stk_double_t * stk);
int drivelStkDoubleEmpty( drivel_stk_double_t * stk);

int drivelStkDoublePush( drivel_stk_double_t * stk, stk_value_t data);
int drivelStkDoubleSwap( drivel_stk_double_t * stk);

stk_value_t drivelStkDoubleTop( drivel_stk_double_t * stk);

stk_value_t drivelStkDoublePop( drivel_stk_double_t * stk);

void drivelStkDoubleDump( drivel_stk_double_t * stk);

#endif
