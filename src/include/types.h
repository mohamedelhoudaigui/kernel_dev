#ifndef TYPES_H
#define TYPES_H

typedef int                 bool;
typedef unsigned char       uint8_t;
typedef unsigned short      uint16_t;
typedef unsigned int        uint32_t;
typedef unsigned long long  uint64_t;
typedef uint8_t             byte_t;
typedef uint32_t            size_t;
typedef uint32_t            paddr_t;
typedef uint32_t            vaddr_t;

#define va_list __builtin_va_list
#define va_start __builtin_va_start
#define va_end __builtin_va_end
#define va_arg __builtin_va_arg

#define align_up(value, align)   __builtin_align_up(value, align)
#define is_aligned(value, align) __builtin_is_aligned(value, align)
#define offsetof(type, member)   __builtin_offsetof(type, member)

#define true  1
#define false 0

#define NULL ((void *)0)
#define STR_NULL 0

#define PAGE_SIZE 4096 /* 4kb = 4096 = 0x1000 */

typedef struct sbiret
{
    long value;
    long error;
}   sbiret;




#endif
