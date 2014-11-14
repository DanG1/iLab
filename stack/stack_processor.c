///DO NOT USE this library until it's finally fixed.
#ifndef STACK_PROCESSOR_Ñ
#define STACK_PROCESSOR_Ñ

#include "stack_processor.h"

int exeStkCmd(drivel_stk_double_t* stk, stk_value_t* procregs, stk_value_t* dothis)
{
    stk_value_t temp0, temp1;
    int stop = false;

    switch ((int) (*dothis))
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
        stop = true;
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
