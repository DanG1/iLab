///DO NOT USE this library until it's finally fixed.

#ifndef STACK_PROCESSOR_H
#define STACK_PROCESSOR_H
#include <stdint.h>
#include <stddef.h>
#include "drivel_stack.h" //reqired for size_t

#define STKCMD_PUSH 1.0
#define STKCMD_ADD  2.0
#define STKCMD_MUL  3.0
#define STKCMD_SWAP 4.0
#define STKCMD_POP0 5.0 // Out to register n.ZERO
#define STKCMD_POP1 6.0 // Out to register n.ONE
#define STKCMD_POP2 7.0 // Out to register n.TWO
#define STKCMD_POP3 8.0 // Out to register n.THREE
#define STKCMD_POP4 9.0 // Out to register n.FOUR (does not exist, just OUTPUT)
#define STKCMD_EXIT 0.0

#define stk_value_t double

typedef stk_value_t* stk_cmd_lst_t;

int exeStkCmd(drivel_stk_double_t* stk, stk_value_t* procregs, stk_value_t* dothis)
{
    stk_value_t temp0, temp1;
    int stop = 0;

    switch ((int) *dothis)
    {
    case (int) STKCMD_PUSH:
        drivelStkDoublePush(stk, *(dothis + 1));
        dothis++;
        break;

    case (int) STKCMD_ADD:
        temp0 = drivelStkDoubleTop(stk);
        drivelStkDoublePop(stk);
        temp0 = temp0 + drivelStkDoubleTop(stk);
        drivelStkDoublePop(stk);
        drivelStkDoublePush(stk, temp0);
        break;

    case (int) STKCMD_MUL:
        temp0 = drivelStkDoubleTop(stk);
        drivelStkDoublePop(stk);
        temp0 = temp0 * drivelStkDoubleTop(stk);
        drivelStkDoublePop(stk);
        drivelStkDoublePush(stk, temp0);
        break;

    case (int) STKCMD_SWAP:
        temp0 = drivelStkDoubleTop(stk);
        drivelStkDoublePop(stk);
        temp1 = drivelStkDoubleTop(stk);
        drivelStkDoublePop(stk);
        drivelStkDoublePush(stk, temp0);
        drivelStkDoublePush(stk, temp1);
        break;

    case (int) STKCMD_POP0:
        procregs[0] = drivelStkDoubleTop(stk);
        drivelStkDoublePop(stk);
        break;

    case (int) STKCMD_POP1:
        procregs[1] = drivelStkDoubleTop(stk);
        drivelStkDoublePop(stk);
        break;

    case (int) STKCMD_POP2:
        procregs[2] = drivelStkDoubleTop(stk);
        drivelStkDoublePop(stk);
        break;

    case (int) STKCMD_POP3:
        procregs[3] = drivelStkDoubleTop(stk);
        drivelStkDoublePop(stk);
        break;

    case (int) STKCMD_POP4:
        procregs[4] = drivelStkDoubleTop(stk);
        drivelStkDoublePop(stk);
        break;

    default:
        stop = 1;
        break;

    }
    dothis++;
    return stop;
}

stk_value_t exeStkCmdLst (stk_cmd_lst_t list, int size)
{
    stk_value_t procregs[5];// = {0,0,0,0,0};
    drivel_stk_double_t* stk = drivelStkDoubleCtor(10);
    stk_value_t* dothis = list;
    while (dothis < list + size - 1) {
            if(exeStkCmd(stk, procregs, dothis)) break;
    }
    drivelStkDoubleDelete(stk);
    return procregs[4];
}


#endif
