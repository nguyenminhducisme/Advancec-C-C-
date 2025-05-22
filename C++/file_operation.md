# 📁 Các Xử Lý File Phổ Biến Trong C++ (`<fstream>`)

| Tác Vụ                | Lớp & Hàm Dùng                           | Mô Tả Ngắn Gọn                                           | Ví Dụ Minh Họa                                     |
|------------------------|------------------------------------------|----------------------------------------------------------|----------------------------------------------------|
| Mở file để ghi         | `std::ofstream ofs("file.txt");`        | Mở file để ghi (xóa nội dung cũ nếu có)                  | `ofs << "Hello";`                                 |
| Mở file để đọc         | `std::ifstream ifs("file.txt");`        | Mở file để đọc nội dung                                  | `std::string s; ifs >> s;`                         |
| Mở file để đọc & ghi   | `std::fstream fs("file.txt", mode);`    | Mở file để vừa đọc vừa ghi (dùng các mode)               | `fs << "abc"; fs >> s;`                            |
| Ghi dòng vào file      | `ofs << "Hello\n";`                     | Ghi chuỗi hoặc biến vào file                             |                                                    |
| Đọc dòng từ file       | `std::getline(ifs, line);`              | Đọc từng dòng của file                                   | `while (getline(ifs, line))`                       |
| Kiểm tra file tồn tại  | `ifs.is_open()`                         | Kiểm tra file đã mở thành công chưa                      | `if (!ifs.is_open()) return;`                      |
| Đóng file              | `ofs.close();`                          | Đóng file sau khi xử lý xong                             | `ifs.close();`                                     |
| Đọc toàn bộ file       | Dùng vòng lặp + `getline()` hoặc `>>`   | Đọc toàn bộ nội dung file                                | `while (ifs >> word)` hoặc `getline(...)`          |
| Thêm dữ liệu vào file  | Mở với `std::ios::app`                  | Không xóa nội dung cũ, ghi thêm vào cuối file            | `std::ofstream f("file.txt", std::ios::app);`      |
| Đặt con trỏ vị trí     | `seekg()`, `seekp()`                    | Di chuyển con trỏ đọc (`get`) hoặc ghi (`put`)           | `ifs.seekg(0);`                                    |
| Lấy vị trí con trỏ     | `tellg()`, `tellp()`                    | Trả về vị trí hiện tại của con trỏ đọc/ghi               | `auto pos = ofs.tellp();`                          |
| Xoá nội dung file      | Ghi đè mà không có `ios::app`           | Ghi file như bình thường (nội dung cũ bị xóa)            | `std::ofstream f("file.txt");`                     |

> 📝 Ghi chú: Cần `#include <fstream>` để dùng các lớp `ifstream`, `ofstream`, `fstream`.
