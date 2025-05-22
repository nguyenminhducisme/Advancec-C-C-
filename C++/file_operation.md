| STT | Hàm / Phương thức | Syntax ví dụ                           | Chức năng / Ghi chú                                   |
| --- | ----------------- | -------------------------------------- | ----------------------------------------------------- |
| 1   | `std::ifstream`   | `std::ifstream in("file.txt");`        | Mở file để **đọc**                                    |
| 2   | `std::ofstream`   | `std::ofstream out("file.txt");`       | Mở file để **ghi**                                    |
| 3   | `std::fstream`    | `std::fstream file("file.txt", mode);` | Mở file để **đọc + ghi**                              |
| 4   | `is_open()`       | `if (file.is_open())`                  | Kiểm tra file đã mở thành công chưa                   |
| 5   | `open()`          | `file.open("file.txt", mode);`         | Mở file nếu chưa mở khi khởi tạo                      |
| 6   | `close()`         | `file.close();`                        | Đóng file                                             |
| 7   | `<<`              | `file << "Hello";`                     | Ghi dữ liệu vào file                                  |
| 8   | `>>`              | `file >> x;`                           | Đọc dữ liệu từ file (bỏ qua khoảng trắng)             |
| 9   | `getline()`       | `std::getline(file, str);`             | Đọc **nguyên 1 dòng** từ file                         |
| 10  | `eof()`           | `while (!file.eof())`                  | Kiểm tra đã đến cuối file chưa                        |
| 11  | `peek()`          | `char c = file.peek();`                | Nhìn ký tự tiếp theo **nhưng không đọc**              |
| 12  | `get()`           | `char c = file.get();`                 | Đọc **1 ký tự** từ file                               |
| 13  | `put()`           | `file.put('A');`                       | Ghi **1 ký tự** vào file                              |
| 14  | `read()`          | `file.read(buf, size);`                | Đọc dữ liệu **nhị phân**                              |
| 15  | `write()`         | `file.write(buf, size);`               | Ghi dữ liệu **nhị phân**                              |
| 16  | `seekg()`         | `file.seekg(pos);`                     | Di chuyển con trỏ đọc đến vị trí `pos`                |
| 17  | `seekp()`         | `file.seekp(pos);`                     | Di chuyển con trỏ ghi đến vị trí `pos`                |
| 18  | `tellg()`         | `pos = file.tellg();`                  | Trả về vị trí con trỏ đọc hiện tại                    |
| 19  | `tellp()`         | `pos = file.tellp();`                  | Trả về vị trí con trỏ ghi hiện tại                    |
| 20  | `flush()`         | `file.flush();`                        | Đẩy dữ liệu trong buffer ra file ngay                 |
| 21  | `bad()`           | `if (file.bad())`                      | Kiểm tra lỗi nghiêm trọng khi thao tác file           |
| 22  | `fail()`          | `if (file.fail())`                     | Kiểm tra thao tác thất bại (mở file, đọc sai kiểu...) |
| 23  | `good()`          | `if (file.good())`                     | Kiểm tra trạng thái tốt                               |
| 24  | `clear()`         | `file.clear();`                        | Xóa cờ lỗi (sau khi đọc/ghi lỗi)                      |
