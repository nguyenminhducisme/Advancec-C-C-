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

/* ========================================[ FUNCTION INPLEMENTATION ]======================================*/
/**
 * @brief Dùng để so sánh giữa 2 thông tin 
 * @param str1 Thông tin thứ nhất
 * @param str2 Thông tin thứ hai
 * @return int
 */
int stringCompare(const char *str1, const char *str2);
/**
 * @brief Dùng để so sánh sđt hoặc tên
 * @param str1
 * @param str2
 * @return int
 */
int compare_by_name_or_phone(const char *str1, const char *str2);
/**
 * @brief Con trỏ hàm để quản lý trong việc so sánh sđt hay là tên
 * @return int
 */


#endif // COMPARISON_H