#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef union
{
    struct
    {
        uint8_t id[2];
        uint8_t data[4];
        uint8_t check_sum[2];
    } data;
   
    uint8_t frame[8];
} Data_Frame;

int main(int argc, char const *argv[])
{
    Data_Frame transmit_data;
    strcpy((char*)transmit_data.data.id, "1");
    strcpy((char*)transmit_data.data.data, "1");
    strcpy((char*)transmit_data.data.check_sum, "1");

    Data_Frame receive_data;
    strcpy((char*)receive_data.frame, (char*)transmit_data.frame);
    return 0;
}
