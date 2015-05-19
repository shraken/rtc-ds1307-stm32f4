#include <stdio.h>
#include <string.h>
#include <stm32f4xx.h>
#include <stm32f4xx_i2c.h>
#include "rtc_usart.h"
#include "rtc_i2c.h"
#include "rtc_ds1307.h"

#define MAX_STR_LEN 128
#define DEFAULT_WAIT_TIME 10000000u

void Delay(__IO uint32_t nCount) {
  while(nCount--) {
  }
}

void display_rtc(rtc_ds1307_datetime_t *rtc_datetime) {
    char buffer[MAX_STR_LEN];

    sprintf( (char *) &buffer[0], "rtc_datetime\r\n\t->seconds = %d\r\n" \
            "\t->minutes = %d\r\n\t->hour = %d\r\n\t->day = %d\r\n" \
            "\t->date = %d\r\n\t->month = %d\r\n\t->year = %d\r\n\r\n", 
            rtc_datetime->seconds, rtc_datetime->minutes, rtc_datetime->hour, 
            rtc_datetime->day, rtc_datetime->date, rtc_datetime->month, 
            rtc_datetime->year);


    USART_puts(USART2, (char *) &buffer[0]);

    return;
}

int main(void) {
    char buffer[MAX_STR_LEN];
    uint32_t count;
    rtc_ds1307_datetime_t rtc_datetime;

    init_USART1(115200); // initialize the USART peripheral
    init_I2C1();         // initialize I2C peripheral
    ds1307_init_rtc(1);  // init the ds1307 RTC for first time

    while(1) {
        if (ds1307_get_rtc_datetime(&rtc_datetime) != RTC_DS1307_OK) {
            USART_puts(USART2, "!!!! could not get ds1307 RTC datetime struc\n");
        }

        display_rtc(&rtc_datetime);

        count++;
        Delay(DEFAULT_WAIT_TIME);
    }
}