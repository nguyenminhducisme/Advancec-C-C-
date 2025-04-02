# Cách chạy chương trình

## 1. Khởi tạo các modules

```c
void initialize_module(Module *module, const uint8_t ID, char *name, uint8_t status, uint8_t access, uint8_t action, uint8_t addtionnal_Options)
{
    module->ID = ID;
    strcpy(module->name, name);
    module->status = status;
    module->access = access;
    module->action = action;
    module->addtionnal_Options = addtionnal_Options;
}

/* Ngoài hàm main */
Module *module = (Module *)malloc(2 * sizeof(Module)); // Cấp phát động để quản lý modules

printf("Starting programme...... \n\n");

initialize_module(module, 1, "ABS", INIT_STATUS, USER, INIT_ACTION, NO_ACTION);
initialize_module(module + 1, 2, "AC", INIT_STATUS, ADMIN, INIT_ACTION, DEFAULT_AC_SPECS);
```

## 2. Bật, tắt modules bằng con trỏ hàm đồng thời ứng dụng bit mask

```c
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

void function_ptr(void (*func_ptr)(Module *, uint8_t), Module *module, uint8_t options)
{
    func_ptr(module, options);
}
```

## 3. Điều chỉnh thông số và in ra các settings đã cài 
```c
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
```

## 4. Chương trình xử lí lỗi
- Kiểm tra lỗi của Air Conditioner để xem có vượt ra khỏi mức nhiệt độ an toàn không
```c 
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
// trong hàm main
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
```

## 5. Cuối cùng là giải phóng bộ nhớ để tránh memory leak

```c
free(module);
```