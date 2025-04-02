/*
#include "stm32f4xx.h"                  // Device header

uint8_t *addr = (uint8_t *)0x20000000;

 "add" volatile uint8_t var = 0;

int main()
{
   while(1){
   var = *addr;
   if(var!=0) break;
   }
}

- Sau nhiều lần chạy đầu tiên, trình biên dịch để ý thấy ta không đụng đến biến var nên nó mặc định là 0. Để khắc phục điều này
thì thêm volatile vào biến var


*/
/*
- Ứng dụng của nó:
volatile int sensor = 26;
+ Giả dụ cảm biến áp suất lốp đọc áp suất lốp trong suất 1 năm là 26, vậy nếu trình biên dịch tối ưu hóa nó, và xảy ra trường hợp
áp suất lốp xuống thấp mà chương trình lại không cập nhật thì sẽ gây nguy hiểm. Để khắc phục ta phải thêm keyword volatile.
*/