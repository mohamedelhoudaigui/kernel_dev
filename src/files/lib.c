#include "../include/kernel.h"

void *memset(void *buf, byte_t b, size_t len)
{
    byte_t *tmp = (byte_t *) buf;
    while (len--)
        *tmp++ = b;
    return buf;
}

void *memcpy(void *dst, void *src, size_t len)
{
    byte_t* tmp1 = (byte_t *)dst;
    byte_t* tmp2 = (byte_t *)src;
    while (len--)
        tmp1[len] = tmp2[len];
    return dst;
}

int memcmp(void* m1, void* m2, size_t len)
{
    byte_t* s1 = (byte_t *)m1;
    byte_t* s2 = (byte_t *)m2;
    while (*s1 == *s2 && len > 0){--len; ++s1; ++s2;}
    if (*s1 > *s2)
        return (1);
    else if (*s1 < *s2)
        return (-1);
    return (0);
}

void putbyte(byte_t ch)
{
    sbi_call(ch, 0, 0, 0, 0, 0, 0, 1);
}

void    putmem(const void *s, size_t size)
{
    byte_t *tmp = (byte_t *)s;
    for (size_t i = 0; i < size; ++i)
        putbyte(tmp[i]);
}

size_t    memlen(const void *s, byte_t stop)
{
    byte_t *tmp = (byte_t *)s;
    size_t  i;

    for (i = 0; tmp[i] != stop; ++i)
        ;
    return (i);
}


void printf(const void *arg, ...)
{
    va_list vargs;
    va_start(vargs, arg);

    const byte_t *fmt = (const byte_t *)arg;
    while (*fmt)
    {
        if (*fmt == '%')
        {
            fmt++;
            switch (*fmt)
            {
                case '\0':
                    putbyte('%');
                    goto end;

                case '%':
                    putbyte('%');
                    break;

                case 's':
                {
                    const byte_t *s = va_arg(vargs, const byte_t *);
                    putmem(s, memlen(s, STR_NULL));
                    break;
                }

                case 'd':
                {
                    int value = va_arg(vargs, int);
                    if (value < 0)
                    {
                        putbyte('-');
                        value = -value;
                    }

                    int divisor = 1;
                    while (value / divisor > 9)
                        divisor *= 10;

                    while (divisor > 0)
                    {
                        putbyte('0' + value / divisor);
                        value %= divisor;
                        divisor /= 10;
                    }

                    break;
                }

                case 'x':
                {
                    size_t value = va_arg(vargs, size_t);
                    for (int i = 7; i >= 0; i--)
                    {
                        int nibble = (value >> (i * 4)) & 0xf;
                        putbyte("0123456789abcdef"[nibble]);
                    }
                }

                case 't':
                {
                    size_t value = va_arg(vargs, size_t);

                    int divisor = 1;
                    while (value / divisor > 9)
                        divisor *= 10;

                    while (divisor > 0)
                    {
                        putbyte('0' + value / divisor);
                        value %= divisor;
                        divisor /= 10;
                    }

                    break;
                }
            }
        }
        else
        {
            putbyte(*fmt);
        }
        fmt++;
    }

    end:
        va_end(vargs);
}
