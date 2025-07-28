#ifndef data_handler_h
#define data_handler_h

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "../Header/definition.h"

#include "../Header/search.h"
#include "../Header/Compare.h"





bool readCSV(const char* path_file, Node **head);



#endif