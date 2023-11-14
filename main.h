#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int write_char(va_list args);
int write_string(va_list args);
int write_percent(void);

#endif /* MAIN_H */
