#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    int count = 0;

    va_list args;
    va_start(args, format);

    while (*format) {
        if (*format == '%') {
            format++;
            if (*format == '%') {
                putchar('%');
                count++;
            } else if (*format == 'c') {
                int cha = va_arg(args, int);
                putchar(cha);
                count++;
            } else if (*format == 's') {
                char *str = va_arg(args, char*);
                while (*str) {
                    count += putchar(*str);
                    str++;
                }
            }
        } else {
            count += putchar(*format);
        }

        format++;
    }

    va_end(args);
    return count;
}
