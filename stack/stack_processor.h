///DO NOT USE this library until it's finally fixed.
#ifndef STACK_PROCESSOR_H
#define STACK_PROCESSOR_H

#include "drivel_stack.h"

enum {
    STKCMD_EXIT,
    STKCMD_PUSH,
    STKCMD_ADD,
    STKCMD_MUL,
    STKCMD_SWAP,
    STKCMD_POP0, // Out to register n.ZERO
    STKCMD_POP1, // Out to register n.ONE
    STKCMD_POP2, // Out to register n.TWO
    STKCMD_POP3, // Out to register n.THREE
    STKCMD_POP4  // just OUTPUT
    };



typedef stk_value_t* stk_cmd_lst_t;

int exeStkCmd(drivel_stk_double_t* stk, stk_value_t* procregs, stk_value_t* dothis);
stk_value_t exeStkCmdLst (stk_cmd_lst_t list, int size);

#endif
