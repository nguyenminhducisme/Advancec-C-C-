#include "C:\Users\nguynduc\advanceC\C\Bai 12\Find_informations_in a_file\Header\Searching.h"
// void add_Information(Node **head, Info *info)
// {
//     Node *new_info = (Node *)malloc(sizeof(Node));
//     new_info->User_Information->address = info->address;
//     new_info->User_Information->name = info->name;
//     new_info->User_Information->age = info->age;
//     new_info->User_Information->phone = info->phone;
//     new_info->next = NULL;

//     if(*head == NULL || (*head)->User_Information->name > info->name)
//     {
//         new_info->next = *head;
//         *head = new_info;
//         return;
//     }

//     Node *current_info = *head;
//     while(current_info->next != NULL && current_info->next->User_Information->name < info->name)
//     {
//         current_info = current_info->next;
//     }

//     new_info->next = current_info->next;
//     current_info->next = new_info;
// }

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

//  void print_list(Node *head)
//  {
//      while (head != NULL)
//      {
//          printf("%s ", head->User_Information->name);
//          printf("%d ", head->User_Information->age);
//          printf("%s ", head->User_Information->address);
//          printf("%s ", head->User_Information->phone);
//          printf("\n");
//          head = head->next;
//      }
//      printf("\n");
//  }

static void free_list(Node *new_info)
{
    free(new_info->User_Information.address);
    free(new_info->User_Information.name);
    free(new_info->User_Information.phone);
    free(new_info);
    new_info = NULL;
}

void add_Information(Info info)
{
    Node *new_info = (Node *)malloc(sizeof(Node));
    new_info->User_Information.name = (char *)malloc(strlen(info.name)+1);
    new_info->User_Information.address = (char *)malloc(strlen(info.address)+1);
    new_info->User_Information.phone = (char *)malloc(strlen(info.phone)+1);
    

    strcpy(new_info->User_Information.name, info.name);
    new_info->User_Information.age = info.age;
    strcpy(new_info->User_Information.address, info.address);
    strcpy(new_info->User_Information.phone, info.phone);
    print_list(new_info);
    free_list(new_info);
   

}

static void print_list(Node *new_info)
{
    printf("%s %d %s %s\n", new_info->User_Information.name, new_info->User_Information.age, new_info->User_Information.address, new_info->User_Information.phone);
}

// void Execute_memory(Node *new_info)
// {
    
// }