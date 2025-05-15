/********************************************************************************
 * @file     main.c 
 * @brief    Dùng để triển khai các hàm tìm kiếm thông tin người dùng
 * @version  1.0
 * @date     3/5/2025
 * @author   Nguyen Minh Duc
********************************************************************************/

/*========================================[FILES INCLUDED]========================================*/
#include "file_handler.h"
#include "Searching.h"


int main()
{
    Info user = {
        .name = "John Doe",
        .age = 30,
        .address = "123 Main St",
        .phone = "555-1234"
     };
    Node *head = NULL;


    open_file(&head);

    print_list(head);


    CenterPoint *ptr = centerPoint(head);

    

    CenterPoint *result = binarySearch(ptr, user);
    if(result != NULL)
    {
        printf( "Found informations\n");
    }
    else
    {
        printf("Can not find anything match\n");
    }
    free_list(head);


    return 0;
}