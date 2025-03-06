#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include <string.h>
#include <setjmp.h>
#include "function_handler.h"

// Các điểm cảnh báo và lỗi chương trình
#define WARNING_POINT_1 20
#define WARNING_POINT_2 35
#define ERROR_POINT_1   15
#define ERROR_POINT_2   40

extern uint8_t exception;;
extern jmp_buf buf;
extern char error_message[50];

typedef enum
{
    NO_ERROR,
    WARNING,
    ERROR
}ErrorCodes;

// Define try catch throw
#define TRY if((exception = setjmp(buf)) == 0)
#define CATCH(x)  if(exception == x) 
#define THROW(x, cmd) { \
   copy_message( error_message, #cmd);  \
   longjmp(buf,x);  \
}


// Hàm sao chép tin nhắn
void copy_message(char str[50], char *original_string);

// Hàm cảnh báo
void warning_Message(Module module);

// Hàm báo lỗi
void error_Message(Module module);

#endif