# MAP
- Là 1 container trong STL của C++, cung cấp 1 cấu trúc dữ liệu key-value (tương tự JSON), cũng là một class Template
- Mỗi phần tử trong std::map là một std::pair<const Key, t>:
    - Key là hằng số (Không thể thay đổi sau khi thêm vào map)
    - T là kiểu dữ liệu của giá trị value
- Các đặc điểm chính
| **Đặc điểm**                 | **Mô tả**                                                           |
| ---------------------------- | ------------------------------------------------------------------- |
| **Sắp xếp theo key**         | Các phần tử được tự động sắp xếp theo thứ tự tăng dần theo **key**. |
| **Không cho phép trùng key** | Mỗi key chỉ xuất hiện một lần duy nhất.                             |
| **Key là hằng số**           | Key không thể thay đổi sau khi được thêm vào `map`.                 |


- Sự khác biệt với Json trong C


## Các cú pháp trong map

| STT | Tên hàm / thao tác    | Cú pháp                                            | Mô tả chức năng                                                               |
| --- | --------------------- | -------------------------------------------------- | ----------------------------------------------------------------------------- |
| 1   | Thêm phần tử          | `map.insert({key, value});`<br>`map[key] = value;` | Thêm cặp `key-value` vào `map`.                                               |
| 2   | Truy cập phần tử      | `map.at(key);`<br>`map[key];`                      | Truy cập giá trị tương ứng với `key`. `at()` an toàn hơn vì kiểm tra phạm vi. |
| 3   | Xóa phần tử           | `map.erase(key);`                                  | Xóa phần tử có `key`.                                                         |
| 4   | Kiểm tra tồn tại      | `map.count(key);`<br>`map.find(key) != map.end();` | Kiểm tra `key` có tồn tại trong `map`.                                        |
| 5   | Kích thước            | `map.size();`                                      | Số lượng phần tử trong `map`.                                                 |
| 6   | Xóa toàn bộ           | `map.clear();`                                     | Xóa toàn bộ phần tử trong `map`.                                              |
| 7   | Duyệt map             | `for (auto &p : map) { ... }`                      | Duyệt qua tất cả các cặp `key-value`.                                         |
| 8   | `begin()` / `end()`   | `map.begin()`<br>`map.end()`                       | Trả về iterator đầu/cuối map.                                                 |
| 9   | `rbegin()` / `rend()` | `map.rbegin()`<br>`map.rend()`                     | Iterator ngược từ cuối về đầu.                                                |
| 10  | Kiểm tra rỗng         | `map.empty();`                                     | Trả về `true` nếu map rỗng.                                                   |
| 11  | Lower/Upper Bound     | `map.lower_bound(key);`<br>`map.upper_bound(key);` | Trả iterator đến phần tử >= hoặc > `key`.                                     |
