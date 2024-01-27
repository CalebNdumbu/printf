#include "main.h"

/**
 * _printf - Printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    int count = 0;

    va_list args;
    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;

            if (*format == '%')
            {
                putchar('%');
                count++;
            }
            else if (*format == 'c')
            {
                char cha = va_arg(args, int);
                putchar(cha);
                count++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char*);
                while (*str)
                {
                    putchar(*str);
                    count++;
                    str++;
                }
            }
            else
            {
                putchar('%');
                putchar(*format);
                count +=2;
            }
        }
        else
        {
            putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);
    return count;
}
