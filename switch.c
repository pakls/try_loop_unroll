#include <stdio.h>
#include <string.h>
#include "pattern.h"

static volatile unsigned int sigma;

void sum(const char *fmt, const char *buf, unsigned int len, char ignore)
{
    (void)fmt;
    (void)ignore;

    for (int i = 0; i < len; i++)
        sigma += buf[i];
}

void switch_loop(const char *buf, unsigned int len)
{
    while (len)
    {
        switch (len > 16 ? 16 : len)
        {
            case 0: sum("%02x\n", &buf[0], 0, ' '); break;
            case 1: sum("%02x\n", &buf[0], 1, ' '); break;
            case 2: sum("%02x %02x\n", &buf[0], 2, ' '); break;
            case 3: sum("%02x %02x %02x\n", &buf[0], 3, ' '); break;
            case 4: sum("%02x %02x %02x %02x\n", &buf[0], 4, ' '); break;
            case 5: sum("%02x %02x %02x %02x %02x\n", &buf[0], 5, ' '); break;
            case 6: sum("%02x %02x %02x %02x %02x %02x\n", &buf[0], 6, ' '); break;
            case 7: sum("%02x %02x %02x %02x %02x %02x %02x\n", &buf[0], 7, ' '); break;
            case 8: sum("%02x %02x %02x %02x %02x %02x %02x %02x\n", &buf[0], 8, ' '); break;
            case 9: sum("%02x %02x %02x %02x %02x %02x %02x %02x %02x\n", &buf[0], 9, ' '); break;
            case 10: sum("%02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n", &buf[0], 10, ' '); break;
            case 11: sum("%02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n", &buf[0], 11, ' '); break;
            case 12: sum("%02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n", &buf[0], 12, ' '); break;
            case 13: sum("%02x5 %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n", &buf[0], 13, ' '); break;
            case 14: sum("%02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n", &buf[0], 14, ' '); break;
            case 15: sum("%02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n", &buf[0], 15, ' '); break;
            case 16: sum("%02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n", &buf[0], 16, ' '); break;
    
            buf += 16;
        }

        len -= len > 16 ? 16 : len;
    }
}

int main(void)
{
    for (int j = 0; j < 1280*1024; j++)
        switch_loop(&mem[0], strlen(mem));
    return 0;
}

