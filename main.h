#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int write_char(va_list args);
int write_string(va_list args);
int write_integer(va_list args);
int write_percent(va_list args);
int write_binary(va_list args);  // New function for %b

#endif /* MAIN_H */
