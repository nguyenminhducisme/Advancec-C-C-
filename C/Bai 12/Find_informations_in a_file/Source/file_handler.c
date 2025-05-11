#include "file_handler.h"



void open_file()
{
    char line[MAXIMUM_LINE];

    FILE *file = fopen(FILE_PATH, "r");
    
    

    if(file == NULL)
    {
        perror("FAIL TO OPEN FILE\n");
        return;
    }

    fgets(line, sizeof(line), file);

    printf("%s\n", line);

    while(fgets(line, sizeof(line), file) != NULL)
    {
        char *token = NULL;
        Info info;

        

        token = strtok(line, ",");
        if (!token) continue;
        while(*token == ' ')     token++;  
        info.name = (char *)malloc(strlen(token)+1);
        strcpy(info.name, token);

        token = strtok(NULL, ",");
        if (!token) continue;
        while(*token == ' ')     token++;  
        info.age = (int)atoi(token);

        token = strtok(NULL, ",");
        if (!token) continue;
        while(*token == ' ')     token++;  
        info.address = (char *)malloc(strlen(token)+1);
        strcpy(info.address, token);

        token = strtok(NULL, ",");
        if (!token) continue;
        while(*token == ' ')     token++;  
        info.phone = (char *)malloc(strlen(token)+1);
        strcpy(info.phone, token);

       //printf("%s %d %s %s\n",info->name,info->age,info->address, info->phone);
        //add_Information(&head, info);     
        //print_list(head);
        add_Information(info);
        
        free(info.name);
        free(info.phone);
        free(info.address);
    }

    fclose(file);
}