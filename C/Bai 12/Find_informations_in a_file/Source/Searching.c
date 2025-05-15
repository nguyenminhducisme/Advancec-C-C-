#include "C:\Users\nguynduc\advanceC\C\Bai 12\Find_informations_in a_file\Header\Searching.h"


/**
 * @brief Con trỏ hàm để quản lý trong việc so sánh sđt hay là tên
 * @return int
 */
int (*compare_function)(const void *, const void *) = NULL;


void add_Information(Node **head, Info info)
{
    Node *new_info = (Node *)malloc(sizeof(Node));
    new_info->User_Information.name = (char *)malloc(strlen(info.name)+1);
    new_info->User_Information.address = (char *)malloc(strlen(info.address)+1);
    new_info->User_Information.phone = (char *)malloc(strlen(info.phone)+1);
    new_info->next = NULL;
    
    
    strcpy(new_info->User_Information.name, info.name);
    new_info->User_Information.age = info.age;
    strcpy(new_info->User_Information.address, info.address);
    strcpy(new_info->User_Information.phone, info.phone);


    if(*head == NULL || compare_function(&(*head)->User_Information, &info) > 0 )
    {
        new_info->next = *head;
        *head = new_info;
    }

    Node *current_info = *head;

    

    while (current_info->next != NULL && compare_function(current_info->next->User_Information.name, info.name)<0)
    {
        current_info = current_info->next;
    }

    new_info->next = current_info->next;
    current_info->next = new_info;
    // print_list(new_info);
    // free_list(new_info);
   

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
    strcpy(root->User_Information->name, node->User_Information.name);
    strcpy(root->User_Information->address, node->User_Information.address);
    strcpy(root->User_Information->phone, node->User_Information.phone);
    root->User_Information->age = node->User_Information.age;
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




 CenterPoint *binarySearch(CenterPoint *root, Info info)
 {
     static int loop = 0;
     loop++;
     printf("So lan lap: %d\n", loop);
 
     if (root == NULL) return NULL;
 
     if (compare_function(root->User_Information, &info) == 0)
     {
         return root;
     }
     else if (compare_function(&info, root->User_Information->address))
     {
         return binarySearch(root->left, info);
     }
     else
     {
         return binarySearch(root->right, info);
     }
 }


void print_list(Node *new_info)
{
    while(new_info != NULL)
    {
        printf("%s %d %s %s\n", new_info->User_Information.name, new_info->User_Information.age, new_info->User_Information.address, new_info->User_Information.phone);
        new_info = new_info->next;
    }
    printf("\n");
}

 void free_list(Node *new_info)
{
    free(new_info->User_Information.address);
    free(new_info->User_Information.name);
    free(new_info->User_Information.phone);
    free(new_info);
    new_info = NULL;
}