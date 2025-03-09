/*
* @author: Nguyen Minh Duc
* @date  : 7/3/2025
* @details: This file is used to run all tasks
*/

#include <stdio.h>
#include "function_handler.h"
#include "module_manager.h"
#include "error_handler.h"



int main()
{
   
    Module *module = (Module *)malloc(2*sizeof(Module));
    
    printf("Starting programme...... \n\n");

    initialize_module(module, 1, "ABS", INIT_STATUS, USER, INIT_ACTION, NO_ACTION);
    initialize_module(module+1, 2, "Air Conditioner", INIT_STATUS, ADMIN, INIT_ACTION, DEFAULT_AC_SPECS);

    function_ptr(disable_module, module, STATUS_ON);
    function_ptr(enable_module, module+1, STATUS_ON);

    function_ptr(set_action, module+1, turn_down );

    display_module(*module);
    display_module(*(module+1));
    
    TRY
    {
        warning_Message(*(module + 1));
        error_Message(*(module + 1));
    }
    CATCH(WARNING)
    {
        printf("------------------------------------------\nIncoming message: %s\n", error_message);
        printf("Stop programme ----- Back to safe settings\n");
    }
    CATCH(ERROR)
    {
        printf("------------------------------------------\nIncoming message: %s\n", error_message);
        printf("Stop programme ----- Back to safe settings\n");
    }

    free(module);
    

    return 0;
}