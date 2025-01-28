#ifndef TYPES_H
#define TYPES_H

typedef unsigned char   byte_t;
typedef unsigned int    size_t;

#define va_list __builtin_va_list
#define va_start __builtin_va_start
#define va_end __builtin_va_end
#define va_arg __builtin_va_arg

#define NULL (void *)0
#define STR_NULL 0

typedef struct sbiret
{
    long value;
    long error;
}   sbiret;




#endif
