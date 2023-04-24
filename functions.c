#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

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
                    char character = (char) va_arg(args, int);
                    write(1, &character, 1);
                    count++;
                    break;
                }
                case 's':
                {
                    char *string = va_arg(args, char *);
                    int i;
                    for (i = 0; string[i] != '\0'; i++)
                    {
                        write(1, &string[i], 1);
                        count++;
                    }
                    break;
                }
                case '%':
                {
                    write(1, "%", 1);
                    count++;
                    break;
                }
                default:
                {
                    break;
                }
            }
        }
        else
        {
            write(1, format, 1);
            count++;
        }

        format++;
    }

    va_end(args);

    return count;
}

