#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

Node* createNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void push_back(Node **head, int data)
{
    Node *new_node = createNode(data);

    if(*head = NULL)
    {
        *head = new_node; // vừa là node đầu vừa là node cuối
        return;
    }
    else
    {
        Node *p = *head;
        while(p->next != NULL)
        {
            p = p->next;
        }

        p->next = new_node;
    }
}

void pop_back(Node **head)
{
    if(*head == NULL)
    {
        printf("Khong co node\n");
        return;
    }
    Node *p = *head;
    while((p->next != NULL))
    p = p->next;

    free(p->next);
    p->next = NULL;
}

int size(Node *head)
{
    int count = 0;
    if(head == NULL)
    return 0;
    while(head!=NULL)
    {
        count++;
        head = head->next;
    }
    return count;
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




    return 0;
}