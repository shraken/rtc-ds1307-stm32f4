/**
 * @filename rtc_ds1307.h
 * @description ds1307 I2C Real Time Clock Driver for stm32f4 boards
 * @author Nicholas Shrake, <shraken@gmail.com>
 */

#ifndef RTC_DS1307_H
#define RTC_DS1307_H

/**
 * CONSTANTS
 */

#define RTC_DS1307_OK       0
#define RTC_DS1307_BAD     -1

#define DS1307_ADDRESS      0x68

#define SECOND_REGISTER    0x00
#define MINUTE_REGISTER    0x01
#define HOUR_REGISTER      0x02
#define DAY_REGISTER       0x03
#define DATE_REGISTER      0x04
#define MONTH_REGISTER     0x05
#define YEAR_REGISTER      0x06
#define CONTROL_REGISTER   0x07

#define SECOND_MASK        0x7F
#define MINUTE_MASK        0x7F
#define HOUR_MASK          0x3F
#define DAY_MASK           0x07
#define DATE_MASK          0x3F
#define MONTH_MASK         0x1F
#define YEAR_MASK          0xFF
#define FLAG_MASK          0xFF

#define RESET_FLAG_ON      0x80
#define RESET_FLAG_OFF     0x00
#define TRICKLE_SETTING    0xA7

/**
 * FUNCTION PROTOTYPES
 */
typedef struct {
    uint8_t year;       // year (0 - 99)
    uint8_t month;      // month (01 - 12)
    uint8_t date;       // date (01 - 31)
    uint8_t day;        // day (01 - 07)
    uint8_t hour;       // hour (00 - 23)
    uint8_t minutes;    // minutes (00 - 59)
    uint8_t seconds;    // seconds (00 - 59)
} rtc_ds1307_datetime_t;

unsigned int ds1307_bcd2bin (unsigned int bcd_value);
unsigned int ds1307_bin2bcd (unsigned int binary_value);
int ds1307_set_rtc_data (char register_value, char data);
int ds1307_get_rtc_data (char register_value, char register_mask,
    unsigned int *return_value);
void ds1307_set_rtc_second (unsigned int value);
void ds1307_set_rtc_minute (unsigned int value);
void ds1307_set_rtc_hour (unsigned int value);
void ds1307_set_rtc_day (unsigned int value);
void ds1307_set_rtc_date (unsigned int value);
void ds1307_set_rtc_month (unsigned int value);
void ds1307_set_rtc_year (unsigned int value);
void ds1307_reset_osf (void);
int ds1307_set_rtc_datetime (rtc_ds1307_datetime_t* datetime);
int ds1307_get_rtc_second (void);
int ds1307_get_rtc_minute (void);
int ds1307_get_rtc_hour (void);
int ds1307_get_rtc_day (void);
int ds1307_get_rtc_date (void);
int ds1307_get_rtc_month (void);
int ds1307_get_rtc_year (void);
int ds1307_get_rtc_datetime (rtc_ds1307_datetime_t *datetime);
int ds1307_init_rtc (int first_run_flag);

#endif
