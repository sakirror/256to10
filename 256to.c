#include <stdio.h>
#include <stdlib.h>
#include "conv.h"

UINT32 conv_256to10(UINT32 a256)
{
    UINT32 ip = (a256 >> 8) & 0x00ffffff;
    UINT32 mod = (a256 & 0xff);
    UINT32 a10 = ip * 10;

    if (mod & 0x80)
        a10 += 5; // 1/2 * 10 (0.5 * 10)
    if (mod & 0x40)
        a10 += 3; // 1/4 * 10 (0.25 * 10)
    if (mod & 0x20)
        a10 += 1; // 1/8 * 10 (0.125 * 10)
    if (mod & 0x10)
        a10 += 1; // 1/16 * 10 (0.0625 * 10)

    return a10;
}

static UINT32 conv_check(UINT32 sec256)
{
    return (UINT32)(((float)sec256) / 25.6);
}

void test256to(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++) {
        UINT32 input = atoi(argv[i]);
        printf("%d -> %u %u\n", input, conv_256to10(input), conv_check(input));
    }
}
