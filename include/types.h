/* Include guard */
#ifndef TF_TYPES_H
#define TF_TYPES_H

/* Base */
#include "base.h"

/* Weekday enum */
typedef enum {
  Monday,
  Tuesday,
  Wednesday,
  Thursday,
  Friday,
  Saturday,
  Sunday,
} weekday_t;
/* Month enum */
typedef enum {
  January,
  February,
  March,
  April,
  May,
  June,
  July,
  August,
  September,
  October,
  November,
  December,
} month_t;
/* IP Address type enum */
typedef enum {
  IPv4 = 4,
  IPv6 = 6,
} ip_addr_type_t;
/* Time of day struct */
typedef struct {
  u8 hour;
  u8 minutes;
  u8 seconds;
} time_t;
/* Date struct */
typedef struct {
  month_t month;
  weekday_t weekday;
  u8 day;
  u16 year;
} date_t;

#endif /* end of include guard: TF_TYPES_H */
