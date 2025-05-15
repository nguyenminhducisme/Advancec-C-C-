/********************************************************************************
 * @file     Comparison.h
 * @brief    Dùng để triển khai các hàm so sánh dữ liệu
 * @details  So sánh tên, số điện thoại đồng thời dùng con trỏ hàm để quản lý
 * @version  1.0
 * @date     3/5/2025
 * @author   Nguyen Minh Duc
********************************************************************************/

#ifndef COMPARISON_H
#define COMPARISON_H

/*========================================[FILES INCLUDED]========================================*/
#include <stdio.h>
#include <string.h>
#include "Searching.h"
#include "file_handler.h"
/* ========================================[ FUNCTION INPLEMENTATION ]======================================*/
/**
 * @brief Dùng để so sánh giữa 2 thông tin 
 * @param str1 Thông tin thứ nhất
 * @param str2 Thông tin thứ hai
 * @return int
 */
int stringCompare(const char *str1, const char *str2);

/**
 * @brief Dùng để so sánh tên
 * @param str1
 * @param str2
 * @return int
 */
int compare_by_name(const void *str1, const void *str2);

/**
 * @brief Dùng để so sánh tên
 * @param str1
 * @param str2
 * @return int
 */
int compare_by_phone(const void *str1, const void *str2);



#endif // COMPARISON_H