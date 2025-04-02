#include<stdio.h>
#include<time.h>

// register int i; ERROR

int main(){
    //gán thời gian bắt đầu
    clock_t start = clock();

    //khai báo biến để kiểm tra
     register int data; // take 0.122s
    //int data; // take 0.143s
    //thực hiện công việc nào đó
    for(data = 0; data < 500000000; data++);

    //gán thời gian kết thúc
    clock_t end = clock();
    
    //in ra thời gian xử lý 
    double time_differece = ((double)(end - start)/CLOCKS_PER_SEC);
    printf("time : %f",time_differece);

    return 0;
}