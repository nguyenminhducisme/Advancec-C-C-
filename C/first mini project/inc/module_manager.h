#ifndef MODULE_MANAGER_H
#define MODULE_MANAGER_H

#include<stdint.h>
#include<stdlib.h>
#include<string.h>

#define DEFAULT_AC_SPECS 25

typedef struct Module
{
    uint8_t ID : 2;
    char name[20];
    uint8_t status : 3;
    uint8_t access : 1;
    uint8_t action ;
    uint8_t addtionnal_Options;
}Module;

// Khởi tạo Module
void initialize_module(Module *module, const uint8_t ID, char *name, uint8_t status, uint8_t access, uint8_t action, uint8_t addtionnal_Options);

#endif