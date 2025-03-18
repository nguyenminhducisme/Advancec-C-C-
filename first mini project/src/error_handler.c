#include "error_handler.h"

uint8_t exception;
jmp_buf buf;
char error_message[50];





void copy_message(char str[50], char *original_string)
{
    for(int i=0;i<strlen(original_string);i++)
    {
        str[i] = original_string[i];
    }
    str[strlen(str)-1]='\0';
}


void warning_Message(Module module)
{
    if(module.addtionnal_Options <=WARNING_POINT_1 || module.addtionnal_Options >=WARNING_POINT_2)
    {THROW(WARNING, your module is encountering some problems );}
}

void error_Message(Module module)
{
    if(module.addtionnal_Options <= ERROR_POINT_1 || module.addtionnal_Options >=ERROR_POINT_2)
    {THROW(ERROR, your module is not active anymore!!! Back to default settings);}
}