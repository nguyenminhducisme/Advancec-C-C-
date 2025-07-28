#ifndef search_h
#define search_h

#include "../Header/definition.h"
#include "../Header/Compare.h"




void add_node(Node **head, Node *value, int (*compareFunc)(const void *, const void *));



  /**
  * @brief   Xây dựng cây nhị phân từ danh sách liên kết.
  * @details Tìm điểm giữa danh sách và chia danh sách thành cây nhị phân tìm kiếm.
  * @param   head   Con trỏ đến danh sách liên kết.
  * @param   start  Vị trí bắt đầu của danh sách.
  * @param   end    Vị trí kết thúc của danh sách.
  * @return  CenterPoint*   Gốc của cây nhị phân tìm kiếm.
  */
 CenterPoint *buildTree(Node *head, int start, int end);

  /**
  * @brief   Chuyển danh sách liên kết thành cây nhị phân tìm kiếm (BST).
  * @details Tính độ dài danh sách liên kết và gọi `buildTree()` để xây dựng BST.
  * @param   head  Con trỏ đến danh sách liên kết.
  * @return  CenterPoint*  Gốc của cây nhị phân tìm kiếm.
  */
 CenterPoint *centerPoint(Node *head);


  /**
  * @brief   Thực hiện tìm kiếm nhị phân trên cây BST.
  * @details Duyệt cây nhị phân để tìm kiếm giá trị cần tìm.
  * @param   root   Gốc của cây nhị phân.
  * @param   value  Giá trị cần tìm.
  * @return  CenterPoint*   Trả về con trỏ đến node tìm thấy, NULL nếu không tìm thấy.
  */
 CenterPoint *binarySearch(CenterPoint *root, char *search_result);

   /**
  * @brief   In danh sách liên kết.
  * @details Duyệt danh sách liên kết và in ra từng phần tử.
  * @param   head  Con trỏ đến danh sách liên kết.
  * @return  void
  */
 void print_list(Node *head);


  void free_list(Node *head) ;



#endif