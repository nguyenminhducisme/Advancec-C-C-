#include "../Header/search.h"

void add_node(Node **head, Node *value, int (*compareFunc)(const void *, const void *))
{
    // Node *new_node = (Node *)malloc(sizeof(Node)); // Không cần cấp phát ở đây nữa, vì 'value' đã là một node mới
    // new_node->address = value->address;
    // new_node->age = value->age;
    // new_node->name = value->name;
    // new_node->phone = value->phone;
    // new_node->next = NULL; // 'value' đã có next = NULL từ readCSV

    /*kiem tra list va them node theo thu tu min -> max*/
    
    //Nếu node đầu trong list lớn hơn node mới*/
    if (*head == NULL || compareFunc(value, *head) < 0){ // So sánh value với *head
        value->next = *head;
        *head = value;
        return;
    }
    //nếu các node nhỏ hơn node mới
    Node *current = *head;
    // Sửa điều kiện vòng lặp
    while (current->next != NULL && compareFunc(value, current->next) > 0) {
        current = current->next;
    }
    //chen node mới vào trước node hiện tại có giá trị lớn hơn nó
    value->next = current->next; 
    current->next = value; 
}

CenterPoint *buildTree(Node *head, int start, int end)
 {
     if (head == NULL || start > end)
     {
         return NULL;
     }
 
     int mid = (start + end) / 2;
     Node *node = head;
 
     for (int i = start; i < mid; i++)
     {
         if (node->next == NULL) break;
         node = node->next;
     }
 
     CenterPoint *root = (CenterPoint *) malloc(sizeof(CenterPoint));
     root->address = node->address;
     root->age = node->age;
     root->name = node->name;
     root->phone = node->phone;
     root->left = buildTree(head, start, mid - 1);
     root->right = buildTree(node->next, mid + 1, end);
     return root;
 }


CenterPoint *centerPoint(Node *head)
 {
     int length = 0;
     Node *node = head;
     while (node != NULL)
     {
         node = node->next;
         length++;
     }
     return buildTree(head, 0, length - 1);
 }




// Giả sử bạn có hàm stringCompare nhận hai char*
extern int stringCompare(const char *str1, const char *str2); // Khai báo nếu nó ở file khác

CenterPoint *binarySearch(CenterPoint *root, char *search_result)
{
    static int loop = 0; // Static biến này sẽ giữ giá trị giữa các lần gọi
    loop++;


    // Không cần cấp phát Node *value ở đây
    // free(value); // Loại bỏ lệnh free này vì value không được cấp phát đúng cách

    if (root == NULL) {
        return NULL; // Nếu root là NULL, không tìm thấy
    }

    // So sánh chuỗi search_result với tên của node hiện tại (root->name)
    // Sử dụng stringCompare trực tiếp hoặc một hàm compareByName đã được điều chỉnh
    int cmp_result = stringCompare(search_result, root->name);

    if (cmp_result == 0) // Nếu tìm thấy (chuỗi bằng nhau)
    {
        return root; // Trả về node tìm thấy
    }
    else if (cmp_result < 0) // Nếu search_result nhỏ hơn root->name, tìm ở cây con trái
    {
        return binarySearch(root->left, search_result);
    }
    else // Nếu search_result lớn hơn root->name, tìm ở cây con phải
    {
        return binarySearch(root->right, search_result);
    }
}
 

void print_list(Node *head) {
    while (head != NULL) {
        printf("Name: %s | Age: %d | Phone: %s | Address: %s\n",
               head->name, head->age, head->phone, head->address);
        head = head->next;
    }
}

 void free_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        Node *next = current->next;

        // Giải phóng từng thành phần được cấp phát động
        free(current->name);
        free(current->phone);
        free(current->address);

        // Giải phóng node
        free(current);

        current = next;
    }
}