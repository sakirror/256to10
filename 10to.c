#include <stdio.h>
#include <stdlib.h>
#include "conv.h"

UINT32 conv_10to256(UINT32 a10)
{
    UINT32 ip = a10 / 10;
    UINT32 mod = a10 % 10;
    UINT32 a256 = ip << 8;

    switch (mod) {
    case 9:
        a256 += 0xe6; // 1/2 + 1/4 + 1/8 + 1/64 + 1/128
        break;
    case 8:
        a256 += 0xcd; // 1/2 + 1/4 + 1/32 + 1/64 + 1/256
        break;
    case 7:
        a256 += 0xb3; // 1/2 + 1/8 + 1/16 + 1/128 + 1/256
        break;
    case 6:
        a256 += 0x9a; // 1/2 + 1/16 + 1/32i + 1/128
        break;
    case 5:
        a256 += 0x80; // 1/2
        break;
    case 4:
        a256 += 0x66; // 1/4 + 1/8 + 1/64 + 1/128
        break;
    case 3:
        a256 += 0x4d; // 1/4 + 1/32 + 1/64 + 1/256
        break;
    case 2:
        a256 += 0x33; // 1/8 + 1/16 + 1/128 + 1/256
        break;
    case 1:
        a256 += 0x1a; // 1/16 + 1/32 + 1/128
        break;
    case 0:
    default:
        break;
    }

    return a256;
}

static UINT32 conv_check(UINT32 sec10)
{
    return (UINT32)(((float)sec10) * 25.6);
}

void test10to(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++) {
        UINT32 in = atoi(argv[i]);
        printf("%d -> %u %u\n", in, conv_10to256(in), conv_check(in));
    }
}
