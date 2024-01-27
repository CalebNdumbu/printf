#include "main.h"
#include <stdio.h>

/**
 * _printf - Printf function
 * @format: format.
 *
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
    int count = 0;

    va_list args;
    va_start (args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    count += putchar(va_arg(args, int));
                    break;

                case 's':
                    {

                        char *str;
                        str = va_arg(args, char*);
                        while (*str != '\0')
                        {
                            count += putchar(*str);
                            str++;
                        }
                    }   
                    break;

                case '%':
                    count += putchar('%');
                    break;

                default:
                    count += putchar('%');
                    putchar(*format);
                    break;
            }
        }
        else
        {
            count += putchar(*format);
        }

        format++;
    }
    va_end(args);
    return count;
}

int main()
{
        char mes[] = "secret";
        int num = 1946;

        _printf(" My %s is that I was born in %d\n", mes,num);
        return 0;
}