#include "kernel.h"

void *memset(void *buf, char c, size_t n)
{
    byte_t *p = (byte_t *) buf;
    while (n--)
        *p++ = c;
    return buf;
}

void putbyte(byte_t ch)
{
    sbi_call(ch, 0, 0, 0, 0, 0, 0, 1 /* Console Putchar */);
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

