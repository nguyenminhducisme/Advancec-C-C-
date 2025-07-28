#include "../Header/data_handler.h"
#include "../Header/search.h" // Thêm include này để sử dụng các hàm của search.h
#include "../Header/Compare.h"

int main()
{
    Node *head = NULL;
    if (readCSV(FILE_PATH, &head)) {
        // Sau khi đọc xong, head đã chứa danh sách liên kết đã sắp xếp
        // Bạn có thể xây dựng cây nhị phân tìm kiếm từ danh sách này
        CenterPoint *bst_root = centerPoint(head);
        
        // Ví dụ tìm kiếm
        char search_name[50];
        printf("Insert name: ");
        scanf("%s", search_name);
        CenterPoint *found_node = binarySearch(bst_root, search_name); // cần định nghĩa compareCharNames

        if (found_node != NULL) {
            printf("Found: Name: %s | Age: %d | Phone: %s | Address: %s\n",
                   found_node->name, found_node->age, found_node->phone, found_node->address);
        } else {
            printf("Not found.\n");
        }

        // Giải phóng danh sách liên kết và cây nhị phân sau khi sử dụng
        free_list(head); 
        // Cần thêm hàm free_tree cho CenterPoint nếu bạn cấp phát động cho các trường
        // free_tree(bst_root);
    } else {
        printf("Có lỗi khi đọc file CSV.\n");
    }

    return 0;
}