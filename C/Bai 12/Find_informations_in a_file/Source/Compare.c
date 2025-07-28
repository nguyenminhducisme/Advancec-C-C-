#include "../Header/Compare.h"

int stringCompare(const char *str1, const char *str2) {
   while (*str1 && (*str1 == *str2)) {
       str1++;
       str2++;
   }
   return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}

// Hàm so sánh theo tên
int compareByName(const void *a, const void *b) {
   // Ép kiểu về Node* thay vì Info* để phù hợp với hàm add_node
   Node *node1 = (Node *)a;
   Node *node2 = (Node *)b;
   return stringCompare(node1->name, node2->name);
}

int compareByPhone(const void *a, const void *b) {
   // Ép kiểu về Node* thay vì Info* để phù hợp với hàm add_node
   Node *node1 = (Node *)a;
   Node *node2 = (Node *)b;
   return stringCompare(node1->name, node2->name);
}