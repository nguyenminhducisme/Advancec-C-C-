#ifndef FUNCTION_HANDLER_H
#define FUNCTION_HANDLER_H


#include "bitmask_utils.h"


void function_ptr(void (*func_ptr)(Module *, uint8_t), Module *module, uint8_t options);

#endif