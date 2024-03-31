/* Include guard */
#ifndef TF_TYPES_H
#define TF_TYPES_H

/* For C++ */
#ifdef __cplusplus
extern "C" {
#endif

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

/* String from each type */
/* C string from weekday */
extern const char* cstr_weekday(weekday_t day);
/* C string from month */
extern const char* cstr_month(month_t month);
/* C string from ip address type */
extern const char* cstr_ipaddrtype(ip_addr_type_t type);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* end of include guard: TF_TYPES_H */
