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
    Node *head = NULL;
    open_file();

    print_list(head);

    CenterPoint *ptr = centerPoint(head);

    CenterPoint *result = binarySearch(ptr, "Jone Doe");
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