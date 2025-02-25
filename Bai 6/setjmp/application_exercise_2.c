#include<stdio.h>
#include<setjmp.h>
#include<string.h>

jmp_buf buf;
char str1[10000], str2[10000];
int a, b;
char error_message[50];
int exception ;

void copy_message(char str[50], char *original_string)
{
    for(int i=0;i<strlen(original_string);i++)
    {
        str[i] = original_string[i];
    }
    str[strlen(str)-1]='\0';
}

typedef enum{
    NO_ERROR, 
    FILE_ERROR, 
    NETWORK_ERROR, 
    CALCULATION_ERROR
}ErrorCodes;

#define TRY if((exception = setjmp(buf)) == 0)
#define CATCH(x) else if(exception == x) 
#define THROW(x, cmd) { \
   copy_message( error_message, #cmd);  \
   longjmp(buf,x);  \
}
void readFile( char *str) 
{
    printf("Doc file...\n");
    if(str == NULL)
    THROW(FILE_ERROR, "Loi doc file: File khong ton tai."); // x= 1
    printf("Doc file thanh cong\n");
}

void networkOperation(char *str)
{
    printf("Kiem thu ket noi mang\n");
    if(str == NULL)
    THROW(NETWORK_ERROR, "Loi mang: Khong chay duoc he thong"); // x=2
    printf("Ket noi mang thanh cong\n");
}

void calculateData(int a, int b)
{
    printf("Tinh toan thong so\n");
    if((a == 0 && b ==0) || (a!=0 && b==0))
    THROW(CALCULATION_ERROR, "Loi tinh toan: He thong khong the tinh toan"); // x=3
    printf("Tinh toan thanh cong: %.3lf\n", (double)a/b);
}

int main()
{
   
   fgets(str1, sizeof(str1), stdin);
   str1[strlen(str1)-1]='\0';
   fgets(str2, sizeof(str2), stdin);
   str2[strlen(str2)-1]='\0';

   scanf("%d %d", &a, &b);

    
    TRY {
        readFile(str1);
        networkOperation(str2);
        calculateData(a, b);
    }
    CATCH(FILE_ERROR){
    printf("%s\n", error_message); 
    }
    CATCH(NETWORK_ERROR){
    printf("%s\n", error_message);
    }
    CATCH(CALCULATION_ERROR){
    printf("%s\n", error_message);
    }
    printf("Ket thuc chuong trinh\n");
    return 0;
}
