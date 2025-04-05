# BINARY SEARCH
# 1. Linear Seach?
- Muốn tìm hiểu về binary search thì trước tiên là cân biết về Linear seach. Vậy Linear search là gì?
- Linear search - Tìm kiếm tuyến tính là thuật toán đơn giản để tìm kiếm một phần tử trong mảng.
- Đơn giản là duyệt tuần tự cách phần tử trong mảng rồi so sánh với giá trị cần tìm kiếm.
- Khi tìm kiếm thì sẽ có 2 trường hợp xảy ra là tồn tại giá trị tìm kiếm và không tồn tại giá trị tìm kiếm.
  ![image](https://github.com/user-attachments/assets/c3decd30-4c5e-4314-84c7-93d66b056d28)

- Đoạn code sau đây tìm kiếm một giá trị trong mảng và in ra có xuất hiện hoặc không.
```cpp
int arr[5] = {1,2,3,4,5};
int x = 3;
for(int i = 0; i < 5; i++){
  if(arr[i] == x) {printf("Found!");return;}
}
printf("Not Found!");
```
# 2. Binary Search?
- Binary Search là thuật toán tìm kiếm nhị phân hoạt động bằng cách chia đôi mảng để tìm kiếm.
- Điều kiện để thực hiện Binary Search đó là mảng đã được sắp xếp tăng dần hoặc giảm dần.
- Để đi vào `Binary Search` ta cần tìm hiểu qua một số thuật toán sắp xếp trước.
## 2.1 Bubble Sort
- Bubble Sort - sắp xếp nổi bọt, là kiểu sắp xếp dựa trên việc hoán đổi hai phần tử liền kề để đưa phần tử lớn hơn về cuối dãy hoặc nhỏ hơn về đầu dãy.
```cpp
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
```
* Giải thích:
  - Duyệt phần tử đầu tiên đến phần tử kế cuối
  - Với mỗi phần tử đang duyệt ta duyệt tiếp từ đầu đến phần tử trước đó của phần tử đang duyệt.
  - Do sánh 2 phần tử đang duyệt lần 2 đấy đưa phần tử lớn hơn về sau. Kết quả mỗi lần duyệt lần 2 này là đưa phần tử lớn nhất trong khoảng đó về cuối cùng.
- Việc sắp xếp như này sẽ có độ phức tạp O(n^2).

![image](https://github.com/user-attachments/assets/9f2fdf7f-8e7b-4994-b997-a4be3cbcd583)

![image](https://github.com/user-attachments/assets/e0a88e0b-62eb-42ca-a1f9-b785d1b9aed4)

![image](https://github.com/user-attachments/assets/2caa82b8-2562-45bf-a8ba-fac80a9096cf)
## 2.2 Binary search.
- Sau khi mảng đã được sắp xếp ta sử dụng 'binary search' để tìm kiếm.
- Bản chất của binary search là phân đôi mảng ra để tìm, khi phần đôi mảng thì ta so sánh phần tử cần tìm với phần tử chính giữa nếu lớn hơn thì nằm bên phải (với mảng tăng dần) bé hơn thì nằm bên trái và nếu bằng thì ta tìm được phần tử đó.
* Thuật toán như sau:
```cpp
int binary_search(int arr[], int n, int x){
  int left = 0, right = n-1;
  while(left >= right){
    int mid = (left + right)/2;
    if(arr[mid] == x) return 1;
    else if(arr[mid] > x) right = mid - 1; //tim ben trai
    else left = mid + 1; // tim ben phai
  }
  return -1;
}
```
![image](https://github.com/user-attachments/assets/42789fb7-7da0-4024-8a84-6bef255e1b73)

## 2.3 Binary Search Tree
- Cấu trúc dữ liệu phân cấp (Tree) là một cấu trúc dữ liệu phi tuyến tính trong đó các phần tử là node được tổ chức theo một thứ bậc phân cấp. Cây là một _cấu trúc dữ liệu_ biểu diễn các quan hệ phân cấp, tìm kiếm, sắp xếp là lưu trữ.
![image](https://github.com/user-attachments/assets/a51b1c79-7543-4ed3-9d67-bfaa21f7421c)
- BST là một cấu trúc dữ liệu dạng cây trong đó:
  - Mỗi nút có tối đa 2 nút con.
  - Nút con bên trái có giá trị nhỏ hơn nút gốc, nút con bên phải có giá trị lớn hơn nút gốc.
Dưới đây là chương trình xây dựng một cây nhị phân.
```cpp
//***************************************************************************
 * @file    Binary_Search_Tree.c
 * @brief   Chuyển đổi danh sách liên kết thành cây nhị phân và tìm kiếm nhị phân.
 * @details Chương trình xây dựng danh sách liên kết đơn, sau đó chuyển đổi danh sách
 *          thành cây nhị phân tìm kiếm (BST). Hỗ trợ thêm node, tìm điểm giữa danh sách,
 *          và thực hiện tìm kiếm nhị phân.
 * @version 1.0
 * @date    2024-11-12
 * @author  Anh Nguyen
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @struct  Node
 * @brief   Cấu trúc của một node trong danh sách liên kết đơn.
 */
typedef struct Node
{
    int data;          /**< Giá trị của node */
    struct Node *next; /**< Con trỏ đến node tiếp theo */
} Node;

/**
 * @brief   Thêm node vào danh sách liên kết và sắp xếp theo thứ tự tăng dần.
 * @param   head   Con trỏ đến con trỏ head của danh sách liên kết.
 * @param   value  Giá trị cần thêm vào danh sách.
 * @return  void
 */
void add_node(Node **head, int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL || (*head)->data >= value)
    {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    Node *current = *head;
    while (current->next != NULL && current->next->data < value)
    {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
}

/**
 * @struct  CenterPoint
 * @brief   Cấu trúc của một node trong cây nhị phân tìm kiếm.
 */
typedef struct CenterPoint
{
    int value;                  /**< Giá trị của node */
    struct CenterPoint *left;   /**< Con trỏ đến node con trái */
    struct CenterPoint *right;  /**< Con trỏ đến node con phải */
} CenterPoint;

/**
 * @brief   Xây dựng cây nhị phân từ danh sách liên kết.
 * @details Tìm điểm giữa danh sách và chia danh sách thành cây nhị phân tìm kiếm.
 * @param   head   Con trỏ đến danh sách liên kết.
 * @param   start  Vị trí bắt đầu của danh sách.
 * @param   end    Vị trí kết thúc của danh sách.
 * @return  CenterPoint*   Gốc của cây nhị phân tìm kiếm.
 */
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
    root->value = node->data;
    root->left = buildTree(head, start, mid - 1);
    root->right = buildTree(node->next, mid + 1, end);
    return root;
}

/**
 * @brief   Chuyển danh sách liên kết thành cây nhị phân tìm kiếm (BST).
 * @details Tính độ dài danh sách liên kết và gọi `buildTree()` để xây dựng BST.
 * @param   head  Con trỏ đến danh sách liên kết.
 * @return  CenterPoint*  Gốc của cây nhị phân tìm kiếm.
 */
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

/**
 * @brief   Thực hiện tìm kiếm nhị phân trên cây BST.
 * @details Duyệt cây nhị phân để tìm kiếm giá trị cần tìm.
 * @param   root   Gốc của cây nhị phân.
 * @param   value  Giá trị cần tìm.
 * @return  CenterPoint*   Trả về con trỏ đến node tìm thấy, NULL nếu không tìm thấy.
 */
CenterPoint *binarySearch(CenterPoint *root, int value)
{
    static int loop = 0;
    loop++;
    printf("Số lần lặp: %d\n", loop);

    if (root == NULL) return NULL;

    if (root->value == value)
    {
        return root;
    }
    else if (value < root->value)
    {
        return binarySearch(root->left, value);
    }
    else
    {
        return binarySearch(root->right, value);
    }
}

/**
 * @brief   In danh sách liên kết.
 * @details Duyệt danh sách liên kết và in ra từng phần tử.
 * @param   head  Con trỏ đến danh sách liên kết.
 * @return  void
 */
void print_list(Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}


int main()
{
    Node *head = NULL;

    /**
     * @brief   Tạo ngẫu nhiên 10000 node trong danh sách liên kết.
     */
    srand(time(NULL));
    for (int i = 0; i < 10000; i++)
    {
        int value = rand() % 10000 + 1;
        add_node(&head, value);
    }

    // add_node(&head, 5639); // Thêm node cụ thể nếu cần

    /**
     * @brief   In danh sách liên kết.
     */
    print_list(head);

    /**
     * @brief   Chuyển danh sách liên kết thành cây nhị phân tìm kiếm (BST).
     */
    CenterPoint *ptr = centerPoint(head);

    /**
     * @brief   Thực hiện tìm kiếm nhị phân trong cây BST.
     * @details Tìm kiếm giá trị ngẫu nhiên vừa được thêm vào danh sách.
     */
    CenterPoint *result = binarySearch(ptr, rand() % 10000 + 1);
    if (result != NULL)
    {
        printf("Tìm thấy giá trị: %d\n", result->value);
    }
    else
    {
        printf("Không tìm thấy giá trị.\n");
    }
    return 0;
}



``` 