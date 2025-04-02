# LINKED LIST

  
## 1. Khái niệm

  **Danh sách liên kết** (`Linked List`) là một cấu trúc dữ liệu dạng danh sách, trong đó các phần tử (được gọi là "node") được liên kết với nhau bằng con trỏ. Mỗi node chứa hai thông tin chính:

- **Dữ liệu**: Giá trị thông tin của node.
- **Con trỏ**: Trỏ đến node tiếp theo trong danh sách.

  **Đặc điểm của danh sách liên kết**
- Không yêu cầu kích thước cố định như mảng.
- Các phần tử không nằm liên tiếp trong bộ nhớ, giúp quản lý bộ nhớ linh hoạt hơn.
- Dễ dàng thêm hoặc xóa phần tử mà không cần dịch chuyển dữ liệu như mảng.

## 2. Các thao tác với danh sách liên kết

### Định nghĩa struct
```c
typedef struct Node /* Chương trình biên dịch từ trên xuống dưới nên ta phải định nghĩa struct là Node ở ngay đầu*/
{
    int data;
    struct Node *next; // Lí do phải để kiểu con trỏ là struct Node, vì con trỏ next này chứa 2 thành phần là giá trị và một con trỏ
}Node;
```

### Hàm tạo node
```c
Node* createNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}
```

### Hàm thêm một node vào cuối list
```c
/*
vì ở đây ta muốn thay đổi địa chỉ của con trỏ cấp 1, nên phải dùng con trỏ cấp 2
- Thực tế, con trỏ cấp 1 cũng có thể thay đổi địa chỉ của con trỏ cấp 1. Nhưng khi thoát ra khỏi hàm thì con trỏ đó vẫn quay về vị trí cũ, cũng như việc mà ta truyền
1 biến vào hàm, thì ra khỏi hàm, biến đó quay trở lại giá trị cũ, để giữ được giá trị mới thì ta cần con trỏ cấp 1. Tương tự với con trỏ cấp 2 muốn giữ lại địa chỉ mới
của con trỏ cấp 1.
*/
void push_back(Node **head, int data) 
{
    Node *new_node = createNode(data);

    if(*head == NULL)
    {
        *head = new_node; // vừa là node đầu vừa là node cuối
    }
    else
    {
        Node *p = *head;
        while(p->next != NULL) p = p->next;

        p->next = new_node;
    }
}
```

### Hàm tính số lượng node
```c
int size(Node *head)
{
    int count = 0;
    if(head == NULL)
    return 0;

    while(head != NULL)
    {
        head = head->next;
        ++count;
    }
    return count;
}
```

### Hàm xóa phần tử ở cuối
```c
void pop_back(Node **head) // xoa phan tu
{
    if(*head == NULL)
    {   
        printf("Khong co node\n");
        return;
    }
    if ((*head)->next == NULL) { // Nếu chỉ có một nút
        free(*head);
        *head = NULL;
        return;
    }
    Node *p = *head;
    int index = 0;
    while(p->next != NULL && index != size(*head)-2)
    {
        p = p->next;
       index++;
    }
    free(p->next);
    p->next = NULL;
}
```

### Hàm chèn một phần tử lên đầu
```c
void push_front(Node **head, int data)
{
    Node *new_node = createNode(data);
    if(*head == NULL)
    {
        *head = new_node; // vừa là node đầu vừa là node cuối
        return;
    }
    new_node->next = *head;
    *head = new_node;
}
```

### Hàm xóa phần tử ở đầu
```c
void pop_front(Node **head)
{
    if(*head == NULL)
    {
        printf("Khong co node !!!\n");
        return;
    }
    Node *p = *head;
    *head = (*head )->next;
    free(p);
    p = NULL;
    return;
    
}
```

### Hàm lấy giá trị node đầu tiên
```c
void front(Node *head)
{
    if(head == NULL)
    {
        printf("Khong co node !!!\n");
        return;
    }
    printf("Value of the first node: %d\n", head->data);
    
}
```

### Hàm lấy giá trị node cuối cùng
```c
void back(Node *head)
{
    if(head == NULL)
    {
        printf("Khong co node !!!\n");
        return;
    }
    Node *p = head;
    while(p->next != NULL)
    p = p->next;

    printf("Value of the last node: %d\n", p->data);
    return;
}
```

### Hàm chèn một node vào vị trí bất kì
```c
void insert(Node **head, int data, int pos)
{
    Node* new_node = createNode(data);
    if(*head == NULL)
    {
        *head = new_node;
    }
    else if(pos == size(*head)-1)
    {
        push_back(head, data);
    }
    else if(pos == 0)
    {
        push_front(head, data);
    }
    else if(pos == size(*head))
    {
        printf("Can not insert element into this position\n");
    }
    else
    {
    Node *p = *head;
    int index = 0;
    while(p->next != NULL && index != pos-1)
    {
        ++index;
        p = p->next;
    }
    if (index == pos -1)
    {
        new_node->next = p->next;
        p->next = new_node;
    }
    return;
    }
}
```

### Hàm xóa node ở vị trí bất kì
```c
void erase(Node **head, int pos)
{
    if(*head == NULL)
    {
        printf("Can not erase\n");
    }
    else if(pos == size(*head)-1)
    {
        pop_back(head);
    }
    else if(pos == 0)
    {
        pop_front(head);
    }
    else
    {
        Node *p = *head;
        int index = 0;
        while(p != NULL && index != pos - 1)
        {
            index++;
            p = p->next;
        }
        if(index == pos -1)
        {
            p->next = p->next->next;
        }
    }

}
```

### Hàm lấy giá trị một node bất kì
```c
void get(Node *head, int pos)
{
    if(head == NULL)
    {
        printf("Khong co node !!!\n");
    }
    else if(pos == 0)
    {
        front(head);
    }
    else if(pos == size(head)-1)
    {
        back(head);
    }
    else
    {
        Node *p = head;
        int index = 0;
        while(p->next != NULL && index != pos)
        {
            p = p->next;
            index++;
        }
        if(index == pos)
        {
            printf("Value of node %d: %d\n", index, p->data);
        }
        return;
    }
}
```

### Hàm kiểm tra xem list có trống hay không
```c 
bool empty(Node *head)
{
    return head == NULL;
}
```

### Hàm xóa toàn bộ node
```c 
void clear(Node **head)
{
    while((*head) != NULL)
    {
        Node *p = *head;
        *head = (*head)->next;
        free(p);
        p = NULL;
    }
}
```

### Hàm hiển thị các node
```c
void display(Node *head)
{
    int i = 0;
    if(head == NULL)
    {
        printf("Khong co Node!\n");
    }
    else
    {
        while(head != NULL)
        {
            printf("Node %d: %d\n", i, head->data);
            head = head->next;
            i++;
        }
    }
}
```