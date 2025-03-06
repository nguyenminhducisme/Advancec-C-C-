#include "function_handler.h"

void function_ptr(void (*func_ptr)(Module *, uint8_t), Module *module, uint8_t options)
{
  func_ptr(module, options);
}





