# Macro
1. #include: đây là chỉ thị dùng để khai báo 1 file nguồn đã được viết sẵn, ta s4 khai báo chỉ thị này cùng với tên của file mà ta cần thêm vào chương trình chính.
+ __#include" "__ : khi file nguồn của chúng ta đặt trong " ", thì chạy chương trình, hệ thống sẽ tìm trong folder của project hiện tại có file đó không và thay thế vào chương trình

+ __#include <>__ : trong trường hợp này thì hệ thống sẽ tìm trong thư mục cài đặt gốc ở bất kỳ đâu trong máy tính để lấy ra file đó
2. #define: Dùng để thay thế một cái gì đó
3. ##: nối chuỗi
4. #: chuẩn hóa văn bản lên chuỗi để xử lí
5. variadic
+ ...: biểu thị các đối số không xác định số lượng
+ __VA_ARGS__:lấy những cái đối số ra thao tác
6. #undef: 
7. #if, #elif, #else, #endif (if, else if)
8. #ifdef, #ifndef


## Macro functions khác gì gọi functions trực tiếp
- Macro làm tăng size chương trình, nhưng nhanh hơn do mỗi lần gọi là một vùng địa chỉ khác nhau