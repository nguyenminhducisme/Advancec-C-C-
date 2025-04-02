#ifndef BITMASK_UTILS_H
#define BITMASK_UTILS_H

/* INCLUDE */
#include<string.h>
#include<stdio.h>
#include "module_manager.h"
/*==============================*/

// Bitmask quản lý trạng thái
#define STATUS_ON        (1 << 0)  // Module đang bật
#define STATUS_ERROR     (1 << 1)  // Module gặp lỗi
#define STATUS_WARNING   (1 << 2)  // Cảnh báo lỗi

// Trạng thái đầu
#define INIT_STATUS 0

// Bitmask quản lý hành động AC (thêm)
#define turn_up   1<<0
#define turn_down 1<<1

// quản lý quyền truy cập
#define USER  0
#define ADMIN 1

// Không có hành động gì
#define NO_ACTION 0

// Khởi tạo hành động
#define INIT_ACTION 0

// Bật module
void enable_module(Module *module, uint8_t Status);

// Tắt module
void disable_module(Module *module, uint8_t Status);

// Cài đặt hành động
void set_action(Module *module, uint8_t action);

// Hiển thị module
void display_module(const Module Module);

#endif