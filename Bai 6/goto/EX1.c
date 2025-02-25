#include<stdio.h>

int main()
{
    // thanh ghi programcounter sẽ thực thi các câu lệnh
    int i = 0; 
    // Đặt nhãn
    start: 
    if(i>=5)
    {
        goto end; // chuyển control đến nhãn end
    }
    printf("%d ", i);
    i++;
    goto start;  // Chuyển control đến nhãn start

    // Nhãn end
    end: 
    printf("\n");

    printf("End of goto");

    return 0;
}