# Các Hàm Phổ Biến Trong `<algorithm>` C++

| Tên Hàm        | Mô Tả Ngắn Gọn                                                | Ví Dụ Cách Dùng                                |
|----------------|---------------------------------------------------------------|------------------------------------------------|
| `sort`         | Sắp xếp các phần tử trong phạm vi [first, last)               | `sort(v.begin(), v.end());`                   |
| `reverse`      | Đảo ngược các phần tử trong phạm vi [first, last)             | `reverse(v.begin(), v.end());`                |
| `find`         | Tìm phần tử đầu tiên bằng giá trị cho trước                   | `find(v.begin(), v.end(), 5);`                |
| `count`        | Đếm số lần xuất hiện của một giá trị                          | `count(v.begin(), v.end(), 10);`              |
| `max_element`  | Trả về iterator tới phần tử lớn nhất                          | `max_element(v.begin(), v.end());`            |
| `min_element`  | Trả về iterator tới phần tử nhỏ nhất                          | `min_element(v.begin(), v.end());`            |
| `accumulate`   | Tính tổng hoặc gộp các phần tử (cần `<numeric>`)              | `accumulate(v.begin(), v.end(), 0);`          |
| `all_of`       | Kiểm tra nếu tất cả phần tử thỏa mãn điều kiện                | `all_of(v.begin(), v.end(), pred);`           |
| `any_of`       | Kiểm tra nếu có ít nhất một phần tử thỏa mãn điều kiện       | `any_of(v.begin(), v.end(), pred);`           |
| `none_of`      | Kiểm tra nếu không có phần tử nào thỏa mãn điều kiện          | `none_of(v.begin(), v.end(), pred);`          |
| `for_each`     | Áp dụng hàm cho từng phần tử                                  | `for_each(v.begin(), v.end(), func);`         |
| `remove`       | Xóa logic (cần `erase` để xóa thực sự)                        | `v.erase(remove(v.begin(), v.end(), 3), v.end());` |
| `unique`       | Loại bỏ các phần tử trùng nhau liên tiếp                      | `v.erase(unique(v.begin(), v.end()), v.end());`|
| `binary_search`| Tìm kiếm nhị phân (cần sắp xếp trước)                         | `binary_search(v.begin(), v.end(), x);`       |
| `lower_bound`  | Trả iterator tới phần tử ≥ x (phải sắp xếp trước)            | `lower_bound(v.begin(), v.end(), x);`         |
| `upper_bound`  | Trả iterator tới phần tử > x (phải sắp xếp trước)            | `upper_bound(v.begin(), v.end(), x);`         |
| `next_permutation` | Sinh hoán vị kế tiếp (theo từ điển)                     | `next_permutation(v.begin(), v.end());`       |
| `prev_permutation` | Sinh hoán vị trước đó (theo từ điển)                    | `prev_permutation(v.begin(), v.end());`       |
| `partition`    | Sắp xếp lại theo điều kiện, trả iterator điểm chia cắt       | `partition(v.begin(), v.end(), pred);`        |
| `stable_sort`  | Giống `sort` nhưng giữ thứ tự tương đối ban đầu              | `stable_sort(v.begin(), v.end());`            |

> 📌 Ghi chú: Hầu hết các hàm này yêu cầu `#include <algorithm>`, một số như `accumulate` cần `#include <numeric>`.
