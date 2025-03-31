# VẤN ĐỀ
- Từ trước tới giờ, chương trình ta viết luôn thực hiện tuần tự. Vậy muốn 2 hay nhiều tác vụ thực thi song song cùng lúc thì sao?
```c
Thư viện unistd để delay trong C
sleep(time);

#include <stdio.h>
#include <unistd.h>
void task1(){
    static int count = 0;
    count++;
    printf("Count taks1: %d\n", count);
    sleep(1);
}
void task2(){
    static int count = 0;
    count++;
    printf("Count taks2: %d\n", count);
    sleep(3);
}
int main(int argc, char const *argv[]){
    while(1){
        task1();
        task2();
    }
    return 0;
}

/* 2 Hàm task1 task2 đang phụ thuộc lẫn nhau */
```
# Thread (Luồng)

## Định nghĩa:
- Là đơn vị thực thi nhỏ nhất của 1 tiến trình (Process). Mỗi tiến trình có thể chứa nhiều thread, và chúng chạy song song với nhau.
- Các thread trong cùng tiến trình chia sẻ tài nguyên với nhau nhưng sẽ có stack và bộ đếm chương trình riêng biệt.

# Thư viện Pthread

## Pthread (POSIX Threads) là thư viện lập trình đa luồng trong C/C++:
1. Giúp viết chương trình đa luồng. 
2. Xử lý nhiều công việc cùng lúc, giúp tăng tốc độ xử lý và phân tán luồng hiệu quả.

## Các hàm quan trọng
1. Hàm pthread_create
```c
pthread_create(pthread_t *th, const pthread_attr_t *attr, void *(* func)(void *), void *arg)
```
- Trong đó:
  - Tham số 1: một con trỏ kiểu pthread_t, đại diện cho một thread mới được tạo ra.
  - Tham số 2: một thuộc tính của thread, đặt là NULL nếu giữ thuộc tính mặc định.
  - Tham số 3: địa chỉ hàm muốn thực thi.
  - Tham số 4: một con trỏ đối số cho hàm thuộc kiểu void.
2. Hàm pthread_join: 
```c 
pthread_join(pthread_t t, void **res) 
```
- Trong đó:
  - Tham số 1: ID của thread mà bạn muốn chờ đợi.
  - Tham số 2: pointer to pointer mà kết quả trả về từ thread sẽ được lưu trữ. Nếu không cần kết quả, có thể đặt NULL .

```c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *task1(void *data){
    static int i = 0;
    for (int i=0; i<8; i++){
        printf("count task1: %d\n", i++);
        sleep(1);
    }
}
void *task2(void *data){
    static int i = 0;
    while(1){
        printf("count task2: %d\n", i++);
        sleep(3);
    }
}
void *display(void *a){
    while(1){
        printf("%s\n", (char*)a);
        sleep(1);
    }
}
/*
hàm main: Vẫn là luồng chính
Các luồng pthread chỉ là luồng phụ. Nếu luồng chính kết thúc thì luồng phụ cũng vậy
*/
int main(int argc, char const *argv[]){
    pthread_t t1; // luồng 1
    pthread_t t2; // luồng 2
    pthread_t t3; // luồng 3

    char *ptr = "Hello\n";
   
    pthread_create(&t1, NULL, task1, NULL);
    pthread_create(&t2, NULL, task2, NULL);
    pthread_create(&t3, NULL, display, ptr);

    pthread_join(t1, NULL); // Hàm này khiến cho luồng chính đợi cho các luồng phụ thực hiện xong thì luồng chính mới thực hiện
    pthread_join(t2, NULL);

    // while(1)
    // {
    //     printf("Hello world\n");
    //     sleep(1);
    // }
    return 0;
}
```


