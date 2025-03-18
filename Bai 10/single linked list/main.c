#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/* Bài tập: Triển khai tất cả các hàm của linked list, giải thích và push lên github, đồng thời ứng dụng makefile để compile */

typedef struct Node /* Chương trình biên dịch từ trên xuống dưới nên ta phải định nghĩa struct là Node ở ngay đầu*/
{
    int data;
    struct Node *next; // Lí do phải để kiểu con trỏ là struct Node, vì con trỏ next này chứa 2 thành phần là giá trị và một con trỏ
}Node;

Node* createNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}
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

void front(Node *head)
{
    if(head == NULL)
    {
        printf("Khong co node !!!\n");
        return;
    }
    printf("Value of the first node: %d\n", head->data);
    
}

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

bool empty(Node *head)
{
    return head == NULL;
}

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

int main()
{
    Node *head = createNode(1);// tạo ra node 1   // 0x00 - 0x0f
    Node *second = createNode(10); // tạo node 2   // 0xb0 - 0xbf
    Node *third = createNode(5); // tạo node 3 // 0xa0 - 0xaf
    
    // Liên kết
    head->next = second;
    second->next = third;  // 1->10->5
   
    display(head);
    printf("\n");

    pop_back(&head);
    pop_back(&head);
    pop_back(&head);
    display(head);

    printf("Amount of nodes: %d\n", size(head));
    
    get(head, 2);

    
    clear(&head);
    display(head);

    if(empty(head))
    printf("List is empty");
    else
    printf("List is not empty");

    return 0;
}