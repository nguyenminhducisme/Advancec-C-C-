#include "../Header/data_handler.h"

bool readCSV(const char* path_file, Node **head)
{
    char line[100];
    int choice;

    printf("Path file: %s\n", path_file);
    printf("Please choose type of information you want to sort:\n");
    printf("1. Name\n");
    printf("2. Phone number\n");
    scanf("%d", &choice);

    FILE *database = fopen(path_file, "r");
    if (database == NULL) {
        printf("Cannot open database\n");
        return FAIL_CREATED_FILE;
    }

    // Bỏ qua dòng tiêu đề
    fgets(line, sizeof(line), database);

    while (fgets(line, sizeof(line), database) != NULL)
    {
        Node *info = (Node *)malloc(sizeof(Node)); // Cấp phát node mới trong mỗi lần lặp
        if (info == NULL) {
            printf("Memory allocation failed\n");
            fclose(database);
            return FAIL_CREATED_FILE;
        }

        // Parse name
        char *token = strtok(line, ",");
        info->name = strdup(token);

        // Parse age
        token = strtok(NULL, ",");
        info->age = atoi(token);

        // Parse phone
        token = strtok(NULL, ",");
        info->phone = strdup(token);

        // Parse address
        token = strtok(NULL, "\r\n");
        info->address = strdup(token);
        info->next = NULL; // Đảm bảo next được khởi tạo là NULL

        // Thêm node vào danh sách
        if (choice == 1) {
            add_node(head, info, compareByName);
        }
        else if (choice == 2)
        {
            /* code */
            add_node(head, info, compareByPhone);
        }
        
        else {
            printf("Invalid choice\n");
            // Giải phóng bộ nhớ của node vừa cấp phát nếu không sử dụng
            free(info->name);
            free(info->phone);
            free(info->address);
            free(info);
            continue;
        }
    }
    fclose(database);

    if (*head == NULL) {
        printf("Danh sách rỗng hoặc lỗi khi đọc file\n");
    } else {
        print_list(*head);
    }

    // Không free_list ở đây, danh sách sẽ được sử dụng ở main
    return true;
}