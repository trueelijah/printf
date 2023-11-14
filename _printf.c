#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: Format string with conversion specifiers
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	const char *ptr;
	int count = 0;

	va_start(args, format);

	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%' && *(ptr + 1) != '\0')
		{
			switch (*(ptr + 1))
			{
				case 'c':
					count += write(1, va_arg(args, int), 1);
					break;
				case 's':
					count += write(1, va_arg(args, char *), 1);
					break;
				case '%':
					count += write(1, "%", 1);
					break;
				default:
					count += write(1, "%", 1);
					count += write(1, (ptr + 1), 1);
			}
			ptr++;
		}
		else
		{
			count += write(1, ptr, 1);
		}
	}

	va_end(args);

	return (count);
}
