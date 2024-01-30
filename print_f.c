#include "main.h"

/**
 * _printf - Printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */

int print_int(int num);

int _printf(const char *format, ...)
{
    int count = 0;
    int print = 0;

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
            else if (*format == 'd' || *format == 'i')
            {
                int num = va_arg(args, int);
                print = print_int(num);
                count += print;

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

int print_int(int num)
{
       int count = 0;

    if (num < 0)
    {
        putchar('-');
        count++;
        num = -num;
    }

    if (num / 10 != 0)
        count += print_int(num / 10);

    putchar(num % 10 + '0');
    count++;

    return count;
}
