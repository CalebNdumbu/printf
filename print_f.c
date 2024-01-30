#include "main.h"

int print_int(int num);
int print_bin(unsigned int n);

/**
 * _printf - Printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */



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
            else if (*format == 'b')
            {
                unsigned int num = va_arg(args, unsigned int);
                count += print_bin(num);
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

/**
 * print_int - Print an integer
 * num: Int to be printed
 *
 * Return: Num of chars printed
 */

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


/**
 * print_binary - Print an unsigned int in binary format
 * @n: Unsigned integer to be print
 *
 * Return: Num of chars print
 */

int print_bin(unsigned int n)
{ 
    int count = 0;

    if (n / 2 != 0)
    {
        count += print_bin(n / 2);
    }

    putchar(n % 2 + '0');
    count++;

    return count;
}