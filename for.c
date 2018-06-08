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

void for_loop(const char *buf, unsigned int len)
{
    for (int i = 0; i < len; i++)
        sum("%02x%c", &buf[i], 1, ((i & 15) == 15 || i == len - 1) ? '\n' : ' ');
        //printf("%02x%c", buf[i], ((i & 15) == 15 || i == len - 1) ? '\n' : ' ');
}

int main(void)
{
    for (int j = 0; j < 1280*1024; j++)
        for_loop(&mem[0], strlen(mem));
    printf("sigma %u\n", sigma);
    return 0;
}

