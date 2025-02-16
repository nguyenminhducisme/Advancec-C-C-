# BIT MASK

- Nếu khai báo kiểu như sau:
int gender; nam = 0, nữ = 1
int status; 0/1
int option1; 0/1   
int option2; 0/1
int option3; 0/1
int option4; 0/1
__+ CHIẾM TỚI 24 BYTES__
__+ Giá trị của int chạy từ 0->2^32-1, trong khi đó ta chỉ cần 2 giá trị 0 và 1
 * NÊN CÓ THỂ KHAI BÁO KIỂU SAU ĐÂY ĐỂ TIẾT KIỆM BỘ NHỚ
int8_t, uint8_t,...
uint8_t status; 0/1
uint8_t option1; 0/1   
uint8_t option2; 0/1
uint8_t option3; 0/1
uint8_t option4; 0/1
__+ CÒN 6 BYTES__
## VẪN CHƯA TỐI ƯU ?

# Bitmask definition:
Là 1 kĩ thuật sử dụng các bit để lưu trữ và thao tác với các flags hoặc trạng thái. Có thể sử dụng bitmask để đặt, xóa và kiểm tra trạng thái của các bit cụ thể trong một từ. Bitmaks thường được sử dụng để tối ưu hóa bộ nhớ, thực hiện các phép toán logic trên một cụm bit, và quản lý các trạng thái, quyền truy cập, hoặc các thuộc tính khác của một đối tượng. 

# Bitwise operation:

__+ NOT__ : ~
__+ AND__ : &
__+ OR__  : |
__+ XOR__ : ^
__+ Shift left__ : <<   
__+ Shift right__: >>

- uint8_t user1 = 0b00001110;
- uint8_t user2 = 0b10101001;

- user1 = ~ user1; // 0b11110001;
- user2 = ~ user2; // 0b01010110;

- user1 & user2 = 0b00001000;
- user1 | user2 = 0b10101110;
- user1 ^ user2 = 0b10100111;

- user1 >> 1 = 0b00000111;
- user1 >> 5 = 0b00000000;
- user1 << 6 = 0b10000000;