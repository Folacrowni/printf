#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "main.h"
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
int count = 0;
va_list args;
va_start(args, format);
while (*format != '\0')
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
{
int c = va_arg(args, int);
putchar(c);
count++;
break; }
case 's':
{
char *s = va_arg(args, char *);
fputs(s, stdout);
count += strlen(s);
break; }
case '%':
{
putchar('%');
count++;
break;
}
default: {
break;
}
}
}
else
{
putchar(*format);
count++; }
format++; }
va_end(args);
return (count);
}
