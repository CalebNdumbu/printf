#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int print_int(int num);
int print_bin(unsigned int n);
int print_unsigned(unsigned int n);
int print_octal(unsigned int n);
int print_hex(unsigned int n, int uppercase);
void print_buffer(char buffer[], int *buff_ind);

#define BUFF_SIZE 1024

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
    int buffer_ind = 0;
    char buffer[BUFF_SIZE];

    va_list args;
    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;

            if (*format == '%')
            {
                buffer[buffer_ind++] = '%';
            }
            else if (*format == 'u')
            {
                if (buffer_ind + print_unsigned(va_arg(args, unsigned int)) >= BUFF_SIZE)
                    print_buffer(buffer, &buffer_ind);
                count += print_unsigned(va_arg(args, unsigned int));
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                while (*str)
                {
                    buffer[buffer_ind++] = *str;
                    if (buffer_ind == BUFF_SIZE)
                        print_buffer(buffer, &buffer_ind);
                    str++;
                }
            }
            else if (*format == 'd' || *format == 'i')
            {
                int num = va_arg(args, int);
                print = print_int(num);
                if (buffer_ind + print >= BUFF_SIZE)
                    print_buffer(buffer, &buffer_ind);
                count += print;
            }
            else if (*format == 'b')
            {
                unsigned int num = va_arg(args, unsigned int);
                if (buffer_ind + print_bin(num) >= BUFF_SIZE)
                    print_buffer(buffer, &buffer_ind);
                count += print_bin(num);
            }
            else if (*format == 'o')
            {
                if (buffer_ind + print_octal(va_arg(args, unsigned int)) >= BUFF_SIZE)
                    print_buffer(buffer, &buffer_ind);
                count += print_octal(va_arg(args, unsigned int));
            }
            else if (*format == 'x')
            {
                if (buffer_ind + print_hex(va_arg(args, unsigned int), 0) >= BUFF_SIZE)
                    print_buffer(buffer, &buffer_ind);
                count += print_hex(va_arg(args, unsigned int), 0);
            }
            else if (*format == 'X')
            {
                if (buffer_ind + print_hex(va_arg(args, unsigned int), 1) >= BUFF_SIZE)
                    print_buffer(buffer, &buffer_ind);
                count += print_hex(va_arg(args, unsigned int), 1);
            }
            else
            {
                putchar('%');
                putchar(*format);
                count += 2;
            }
        }
        else
        {
            buffer[buffer_ind++] = *format;
            if (buffer_ind == BUFF_SIZE)
                print_buffer(buffer, &buffer_ind);
            count++;
        }

        format++;
    }

    print_buffer(buffer, &buffer_ind);

    va_end(args);
    return count;
}

/**
 * print_int - Print an integer
 * @num: Int to be printed
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
 * print_bin - Print an unsigned int in binary format
 * @n: Unsigned integer to be printed
 *
 * Return: Num of chars printed
 */
int print_bin(unsigned int n)
{
	int count = 0;

	if (n / 2 != 0)
		count += print_bin(n / 2);

	putchar(n % 2 + '0');
	count++;

	return count;
}

/**
 * print_unsigned - Prints an unsigned integer.
 * @n: The unsigned integer to be printed.
 *
 * Return: Number of characters printed.
 */
int print_unsigned(unsigned int n)
{
    int count = 0;

    if (n / 10 != 0)
        count += print_unsigned(n / 10);

    putchar(n % 10 + '0');
    count++;

    return count;
}

/**
 * print_octal - Prints an unsigned integer in octal format.
 * @n: The unsigned integer to be printed.
 *
 * Return: Number of characters printed.
 */
int print_octal(unsigned int n)
{
    int count = 0;

    if (n / 8 != 0)
        count += print_octal(n / 8);

    putchar(n % 8 + '0');
    count++;

    return count;
}

/**
 * print_hex - Prints an unsigned integer in hexadecimal format.
 * @n: The unsigned integer to be printed.
 * @uppercase: Flag indicating uppercase letters (1) or not (0).
 *
 * Return: Number of characters printed.
 */
int print_hex(unsigned int n, int uppercase)
{
    int count = 0;
    char hexDigits[] = "0123456789abcdef";

    if (uppercase)
        hexDigits[10] = 'A';

    if (n / 16 != 0)
        count += print_hex(n / 16, uppercase);

    putchar(hexDigits[n % 16]);
    count++;

    return count;
}

/**
 * print_buffer - Prints buffered characters and resets the buffer index.
 * @buffer: The character buffer to be printed.
 * @buff_ind: Pointer to the buffer index.
 *
 * Prints characters in the buffer up to the current index and resets it to 0.
 */
void print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
    {
        fwrite(buffer, 1, *buff_ind, stdout);
    }
    *buff_ind = 0;
}
