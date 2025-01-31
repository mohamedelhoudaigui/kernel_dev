#ifndef LIB_H
#define LIB_H

#include "types.h"

void    *memset(void *buf, byte_t b, size_t len);
void    *memcpy(void *dst, void *src, size_t len);
int     memcmp(void* m1, void* m2, size_t len);
size_t  memlen(const void *s, byte_t stop);

void    putbyte(byte_t ch);
void    putmem(const void *s, size_t size);
void    printf(const void *arg, ...);


#endif
