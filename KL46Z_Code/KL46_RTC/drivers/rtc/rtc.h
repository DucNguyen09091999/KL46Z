#include <stdint.h>
#include <MKL46Z4.h>

typedef struct RtcDatetime
{
   uint16_t year;    /*!< Range from 1970 to 2099.*/
   uint16_t month;   /*!< Range from 1 to 12.*/
   uint16_t day;     /*!< Range from 1 to 31 (depending on month).*/
   uint16_t hour;    /*!< Range from 0 to 23.*/
   uint16_t minute;  /*!< Range from 0 to 59.*/
   uint8_t second;   /*!< Range from 0 to 59.*/
} rtc_datetime_t;

void RTC_ConvertSecsToDatetime(const uint32_t * seconds, rtc_datetime_t * datetime);
int RTC_IsDatetimeCorrectFormat(const rtc_datetime_t * datetime);
void RTC_ConvertDatetimeToSecs(const rtc_datetime_t * datetime, uint32_t * seconds);

int RTC_SetDatetime(rtc_datetime_t *datetime);
void RTC_GetDatetime(rtc_datetime_t *datetime);


/*******************************************************************************
 * EOF
 ******************************************************************************/

