#ifndef LIB_H
#define LIB_H

#include "types.h"

void    *memset(void *buf, byte_t b, size_t n);
void    putbyte(byte_t ch);
void    putmem(const void *s, size_t size);
size_t  memlen(const void *s, byte_t stop);
void    printf(const void *arg, ...);


#endif
