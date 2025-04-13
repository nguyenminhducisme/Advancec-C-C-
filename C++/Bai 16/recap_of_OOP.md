# Các nguyên lý cơ bản của OOP

## Lập trình hướng đối tượng có tổng cộng 4 nguyên lý cơ bản nhất, bao gồm: Encapsulation, Polymorphism, Inheritance và Abstraction. Mỗi nguyên lý cơ bản này sẽ có tính vận hành cùng những ưu điểm cực kỳ riêng biệt như sau:

1. Tính đóng gói (Encapsulation)

**Encapsulation thường thể hiện qua việc các đối tượng và phương thức có liên quan đến việc đóng gói thành từng lớp nhỏ. Đồng thời được xây dựng để thực hiện một nhóm có chức năng đặc trưng riêng biệt. Thường xuyên che giấu một số thông tin và những cài đặt nội bộ để tránh sự rò rỉ thông tin ra bên ngoài**.

     Ví dụ: Hãy tưởng tượng một class đại diện cho một tài khoản ngân hàng (Account). Tài khoản này có hai thuộc tính chính là tên (name) và số dư (balance). Để bảo vệ thông tin nhạy cảm này, chúng ta sẽ khai báo chúng là private.

Để tương tác với các thuộc tính private, chúng ta sử dụng các method public như:

```cpp
     - GetName(): Trả về tên của tài khoản.
     - GetBalance(): Trả về số dư hiện tại của tài khoản.
     - Deposit(amount): Nạp tiền vào tài khoản.
     - Withdraw(amount): Rút tiền từ tài khoản.
```

2. Tính kế thừa (Inheritance):

**Inheritance là nguyên lý cơ bản chuyên kế thừa các lớp dữ liệu, ví dụ như những lớp dữ liệu cha sẽ chia sẻ thông tin và phương thức cho các lớp dữ liệu con. Qua đó các lớp con có thể kế thừa và bổ sung thêm nhiều thành phần mới cho riêng mình**. Trong đó có một số loại kế thừa phổ biến như:

     - Đơn kế thừa.
     - Đa kế thừa.
     - Kế thừa đa cấp.
     - Kế thừa thứ bậc.

- Với 4 loại trên, lập trình viên sẽ tiết kiệm được tối ưu thời gian và công sức trong việc lập trình lên các lớp sở hữu những đặc tính giống nhau.

```bash
     - Ví dụ: Hãy xem xét hai lớp phổ biến trong thế giới smartphone là Android và iPhone. Cả hai đều có những thuộc tính chung như khả năng gọi điện, nhắn tin và chụp hình.Thay vì viết lại các mã này cho từng lớp, chúng ta có thể tạo một lớp cha có tên là Smartphone để chứa các thuộc tính chung này. Sau đó, các lớp Android và iPhone sẽ kế thừa từ lớp Smartphone và chỉ cần định nghĩa những đặc điểm riêng biệt của mình.
```

3. Tính đa hình (Polymorphism)

**Polymorphism là một hành động giúp người dùng có thể thực hiện bằng nhiều cách khác nhau, nói một cách đơn giản thì tính đa hình là khái niệm. Trong đó có nhiều lớp sở hữu các phương thức giống nhau nhưng lại phát triển bằng các cách thức riêng biệt**.

```bash
     Ví dụ: Chó và mèo đều kế thừa từ lớp động vật. Cả hai đều có phương thức kêu. Tuy nhiên, khi gọi phương thức kêu cho từng đối tượng, chúng sẽ ghi đè lại phương thức này và tạo ra những âm thanh khác nhau: chó sẽ kêu “gâu gâu”, mèo sẽ kêu “meo meo”.
```

4. Tính trừu tượng (Abstraction)

**Abstraction là nguyên lý cơ bản của OOP có tính tổng quát hóa, thường không quá chú ý đến những cái bên trong. Do đó khi sử dụng, người dùng cần chọn ra các thuộc tính và phương thức của đối tượng trong việc lập trình**.

```bash
- Ví dụ: Chúng ta có thể tạo một class trừu tượng tên là UIElement để đại diện cho tất cả các thành phần trong giao diện người dùng (UI). Class này sẽ có một phương thức trừu tượng là render() để hiển thị các thành phần này.
- Tại sao lại cần một phương thức trừu tượng? Bởi vì chúng ta chưa biết chính xác loại element nào sẽ được tạo ra (ví dụ: Button, Link, Image). Mỗi loại element sẽ có cách hiển thị khác nhau. Do đó, phương thức render() sẽ được định nghĩa cụ thể trong các class con kế thừa từ UIElement.
```
