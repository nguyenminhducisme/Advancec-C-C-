#include<stdio.h>

int main()
{
    int choice;
    int condition = 1;
    
    main_menu:
    do
    {
        printf("---MAIN MENU---\n");
        printf("1. Channel 1\n");
        printf("2. Channel 2\n");
        printf("3. EXIT\n");
        printf("0. Exit and back to menu\n");
        scanf("%d", &choice);
    } while (choice <0 || choice >3);
    printf("\n");
   
    switch(choice) {
    case(0):
    {
        goto main_menu;   
    };
    case(1):
    {
        goto Channel_1;
    }
    case(2):
    {
        goto Channel_2;
    }
    case(3):
    {
        goto exit_menu;
    }
}

    Channel_1:
    do{
    printf("1. Volumn up\n");
    printf("2. Volumn down\n");
    printf("0. Switch channel\n\n");
    scanf("%d", &choice);
    }while(choice<0 || choice >2);
    
    if(choice == 0)
    goto main_menu;
    else if(choice ==1)
    {
        printf("1. Volumn up\n");
        goto Channel_1;
    }
    else if(choice ==2)
    {
        printf("2. Volumn down\n");
        goto Channel_1;
    }

    Channel_2:
    do{
        printf("1. Volumn up\n");
        printf("2. Volumn down\n");
        printf("0. Switch channel\n");
        scanf("%d", &choice);
    }while(choice<0 || choice >2);
    if(choice == 0)
    goto main_menu;
    else if(choice ==1)
    {
        printf("1. Volumn up\n");
        printf("\n");
        printf("\n");
        goto Channel_1;
    }
    else if(choice ==2)
    {
        printf("2. Volumn down\n");
        printf("\n");
        printf("\n");
        goto Channel_1;
    }
    exit_menu:
    printf("Exit menu\n");


    printf("%d\n", 'A');
    return 0;
    
}