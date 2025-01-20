#ifndef KERNEL_H
#define KERNEL_H

extern char __bss[], __bss_end[], __stack_top[];

typedef unsigned char   byte_t;
typedef unsigned int    size_t;

typedef struct sbiret
{
    long value;
    long error;
}   sbiret;

void    *memset(void *buf, byte_t c, size_t n);
void    putbyte(byte_t ch);
void    putmem(const void *s, size_t size);
size_t  memlen(const void *s, byte_t stop);

sbiret sbi_call(long arg0, long arg1,
                long arg2, long arg3, long arg4, long arg5,
                long fid, long eid);

#endif
