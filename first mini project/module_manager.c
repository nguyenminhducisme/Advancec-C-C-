#include "module_manager.h"
#include "bitmask_utils.h"

void initialize_module(Module *module, const uint8_t ID, char *name, uint8_t status, uint8_t access, uint8_t action, uint8_t addtionnal_Options)
{
    module->ID = ID;
    strcpy(module->name, name);
    module->status = status;
    module->access = access;
    module->action = action;
    module->addtionnal_Options = addtionnal_Options;
}