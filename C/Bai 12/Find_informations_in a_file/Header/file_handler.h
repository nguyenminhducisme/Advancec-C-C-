/********************************************************************************
 * @file     file_handler.h 
 * @brief    Dùng để triển khai các hàm xử lí file chứa database
 * @details  Gồm các hàm xử lí file, đồng thời sắp xếp các dữ liệu để dễ dàng 
 *           trong việc dùng cây nhị phân tìm kiếm thông tin
 * @version  1.0
 * @date     3/5/2025
 * @author   Nguyen Minh Duc
********************************************************************************/

#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

/*========================================[FILES INCLUDED]========================================*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


/*========================================[TYPES DEFINITIONS]========================================*/
#define FILE_PATH "database.csv"
#define MAXIMUM_LINE 100
typedef struct Info
{
    char *name;
    int age;
    char *phone;
    char *address;
}Info;
/*========================================[FILES INCLUDED]========================================*/
#include "Searching.h"
/* ========================================[ FUNCTION INPLEMENTATION ]======================================*/
/**
 * @brief  Đọc file và in ra dữ liệu trong file
 * @return void
 */
void open_file();
#endif // FILE_HANDLER_H