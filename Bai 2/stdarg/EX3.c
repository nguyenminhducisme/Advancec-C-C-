#include<stdio.h>
#include<stdarg.h>

typedef enum sensor{ //enum: kieu liet ke
    temperature_sensor,
    pressure_sensor
}sensor;

void SENSOR_DATA(sensor type,...){
    va_list parameter;
    va_start(parameter, type);
    
    switch(type){
        case(temperature_sensor):
        {
            int numArgs= va_arg(parameter, int);
            int sensorID= va_arg(parameter, int);
            int temperature= va_arg(parameter, int);
            printf("Temperature sensor ID: %d\nTemperature: %d\n", sensorID, temperature);
            break;
        }
        case(pressure_sensor): 
        {
            int numArgs= va_arg(parameter, int);
            int sensorID= va_arg(parameter, int);
            int pressure= va_arg(parameter, int);
            printf("Pressure sensor ID: %d\nPressure: %d", sensorID, pressure);
            break;
        }
    }

}
int main(){
    SENSOR_DATA(temperature_sensor, 2, 1234, 36);
    SENSOR_DATA(pressure_sensor, 2, 1543, 56);
}
