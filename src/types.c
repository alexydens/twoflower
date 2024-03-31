/* Implements the cstr_... functions in types.h */
#include <types.h>

/* String from each type */
/* C string from weekday */
const char* cstr_weekday(weekday_t day) {
  switch (day) {
    case Monday:
      return "Monday";
      break;
    case Tuesday:
      return "Tuesday";
      break;
    case Wednesday:
      return "Wednesday";
      break;
    case Thursday:
      return "Thursday";
      break;
    case Friday:
      return "Friday";
      break;
    case Saturday:
      return "Saturday";
      break;
    case Sunday:
      return "Sunday";
      break;
  }
  return NULL;
}
/* C string from month */
const char* cstr_month(month_t month) {
  switch (month) {
    case January:
      return "January";
      break;
    case February:
      return "February";
      break;
    case March:
      return "March";
      break;
    case April:
      return "April";
      break;
    case May:
      return "May";
      break;
    case June:
      return "June";
      break;
    case July:
      return "July";
      break;
    case August:
      return "August";
      break;
    case September:
      return "September";
      break;
    case October:
      return "October";
      break;
    case November:
      return "November";
      break;
    case December:
      return "December";
      break;
  }
  return NULL;
}
/* C string from ip address type */
const char* cstr_ipaddrtype(ip_addr_type_t type) {
  return (type == IPv4) ? "IPv4" : "IPv6";
}
