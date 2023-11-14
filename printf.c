#include "main.h"
#include <unistd.h>

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++; /* Move past '%' */
            switch (*format)
            {
            case 'c':
                count += write_char(args);
                break;
            case 's':
                count += write_string(args);
                break;
            case 'd':
            case 'i':
                count += write_integer(args);
                break;
            case '%':
                count += write_percent(args);
                break;
            case 'b':  // New case for %b
                count += write_binary(args);
                break;
            }
        }
        else
        {
            count += write(1, format, 1);
        }
        format++;
    }

    va_end(args);
    return count;
}

int write_char(va_list args)
{
    /* Implement character printing logic */
    return write(1, &va_arg(args, int), 1);
}

int write_string(va_list args)
{
    /* Implement string printing logic */
    return write(1, va_arg(args, char *), 1);
}

int write_integer(va_list args)
{
    /* Implement integer printing logic */
    return 0;
}

int write_percent(va_list args)
{
    return write(1, "%", 1);
}

int write_binary(va_list args)
{
    /* Implement binary printing logic for %b */
    return 0;
}
