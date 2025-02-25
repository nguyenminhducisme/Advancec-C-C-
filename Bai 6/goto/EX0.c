#include<stdio.h>

int main()
{
    int cnt = 0;
    while(1)
    {
        for(int i=0; i<5; i++)
        {
            for(int j = 0; j<5; j++)
            {
                if(i==3 && j==4)
                goto exit_loop;
                else
                {
                    ++cnt;
                    printf("%d\n",cnt);
                }
            }
        }
    }
    exit_loop:
    printf("EXIT LOOP\n");
    return 0;
}