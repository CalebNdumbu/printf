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
            case '%':
                count += write_percent();
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

int write_percent(void)
{
    return write(1, "%", 1);
}
