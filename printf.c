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
                count += write_char(va_arg(args, int));
                break;
            case 's':
                count += write_string(va_arg(args, char *));
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

int write_char(int c)
{
    return write(1, &c, 1);
}

int write_string(const char *str)
{
    return write(1, str, strlen(str));
}

int write_percent(void)
{
    return write(1, "%", 1);
}
