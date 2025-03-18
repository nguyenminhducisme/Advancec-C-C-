#include "bitmask_utils.h"

void enable_module(Module *module, uint8_t Status)
{
    module->status |= Status;
}

void disable_module(Module *module, uint8_t Status)
{
    module->status &= (~Status);
}



void set_action(Module *module, uint8_t action)
{
    module->action |= action;
}

void display_module(Module module)
{
    printf("----ID of module: %d----\n", module.ID);
    printf("Name of module: %s\n", module.name);
    printf("Status of module: %s\n", (module.status & STATUS_ON) ? "Module is on" : "Module is off");

    if(module.status == USER)
    printf("Have limited access to this module \n---< You can not monitor or control this module yourself >---\n");
    else if(module.access == ADMIN)
    printf("Have free access to this module\n");

    uint8_t *set_option = &module.addtionnal_Options;

    if(module.action == turn_down)
    {
        *set_option -= 2;
        printf("Action of module: Turning down...\n");
        printf("Current specifications: %d\n", *set_option);
        set_option = NULL;
    }
    else if(module.action == turn_up)
    {
        set_option += 2;
        printf("Action of module: Turning up...\n");
        printf("Current specifications: %d\n", *set_option);
        set_option = NULL;
    }
    else
    {
        printf("No action available on this module\n");
    }
    

    

    printf("\n");
}



