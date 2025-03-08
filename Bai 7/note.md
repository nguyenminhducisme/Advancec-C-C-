# STRUCT
- Là 1 kiểu dữ liệu ta tự định nghĩa
```c
#include<stdio.h>

// struct SinhVien
// {
//     char *name;
//     int    age;
//     double gpa;
// };

// struct  SinhVien sv1, sv2, sv3;
typedef struct 
{
    char *name;
    int    age;
    double gpa;
}SinhVien;

SinhVien sv1, *sv2, sv3;

int main()
{
    sv1.name = "anh";
    sv1.age  = 23;
    sv1.gpa  = 8.0;
    printf("Ten sinh vien 1: %s\n", sv1.name);
    
    sv2->name = "Trung";
    sv2->age  = 30;
    sv2->gpa  = 7.8;
    printf("Ten sinh vien 2: %s\n", sv2->name);

    return 0;
}
```

# Data alignment
- Là quá trình sắp xếp nhứng biến thành viên sao cho các biến đó nằm ở những nơi phù hợp với cách sắp xếp của CPU.
- Ví dụ:
int(4 bytes) int32_t, uint32_t: 0x00, 0x04, 0x08...
double(8 bytes): 0x00, 0x08, 0x0f...
char(1 bytes), int8_t, uint8_t

### tại sao cpu lại quy định vậy:
Để truy xuất dữ liệu nhanh hơn

# Data padding
```c
typedef struct 
{
    int   x; // 4 bytes  0xa0 0xa1 0xa2 0xa3  lần cấp phát 1
    short y; // 2 bytes  0xa4 0xa5 0xa6 0xa7 sử dụng 0xa4 và 0xa5 còn 0xa6 0xa7    lần cấp phát 2
    short z; // 2 bytes  sử dụng 0xa6 0xa7    lần 3
    short a; // 2 bytes  cấp phát thêm 0xa8 0xa9 (0xaa 0xab)->2 byte padding: là những ô địa chỉ trống, không có dữ liệu.    lần 4
}SinhVien;
```
- sizeof(struct) = 12 bytes;
- Cấp phát bộ nhớ từ trên xuống.
- Cấp phát vùng nhớ cho biến có size lớn nhất.

```markdown
- Biến toàn cục giải phóng dữ liệu khi kết thúc toàn chương trình.
- Biến cục bộ giải phóng khi kết thúc hàm.
```

### Ứng dụng:
- cấu hình (gpio, uart, spi, ...)
- json
- list


# Union

## Định nghĩa:
- Là 1 cấu trúc dữ liệu giúp liên kê nhiều kiểu dữ liệu khác nhau vào vùng nhớ.
- Mục đích: Tiết kiệm bộ nhớ bằng cách chia sẻ cùng một vùng nhớ cho các thành viên của nó. ==> trong 1 thời điểm, chỉ một thành viên của Union có thể được sử dụng ==> Giúp tiết kiệm bộ nhớ.

```c
union TenUnion {
    data_type1 thanhVien1;
    data_type2 thanhVien2;
};
```
## Ứng dụng:
- Tiết kiệm bộ nhớ.
- Tại 1 thời điểm chỉ đọc 1 giá trị.

* Kết hợp struct và union
MCU A                                              MCU B
Data:                                              Data
{                                                Data_Frame
    id
    data                ===============>
    checksum             Data_frame
}data_frame

id           data                   checksum
0x01 0x02   0x03 0z04 0x05 0x06    0x07 0x08 
1    0