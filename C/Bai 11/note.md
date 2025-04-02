# JSON
- Là viết tắt của "Javascript Object Notation". Là 1 định dạng truyền tải dữ liệu
- Sử dụng 1 cú pháp trên cặp key - value
- Sử dụng trong giao tiếp giữa server và ng dùng trong lập trình web là phổ biến

```c
- object
{
    "name": "John Doe",  
    "age": "30",              // key: age  value: 30
    "city": "New York",
    "isStudent": false,
    "grades" :[85, 90, 78]
}
```

- Mảng
```c
[
  {
    "name": "John Doe",
    "age": 30,
    "city": "New York",
    "occupation": "Software Engineer",
    "isStudent": false
  },
  {
    "name": "Jane Smith",
    "age": null,
    "city": "Los Angeles",
    "contact": {
      "email": "jane.smith@example.com",
      "phone": "555-1234"
    }
  },
  {
    "name": "Bob Johnson",
    "age": 35,
    "city": "Chicago"
  },
  20, 3.14, “Hello word”, true, null
]
```
### Trong mảng trong json, các phần tử không cần phải giống kiểu dữ liệu như mảng bình thường (int a[]...)
### Đối với struct 

# Ứng dụng:
- google form: 
1. Tên (*): thông tin bắt buộc điền vào
2. Địa chỉ (Khong bắt buộc phải điền vào) 
===> Số lượng thông tin không cố định: Không sử dụng struct, sử dụng JSON