#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conv.h"

static void test10to256to10(int argc, char *argv[])
{
    printf("---------------\n");
    printf("10 -> 256 -> 10\n");
    printf("---------------\n");
    for (int i = 1; i < argc; i++) {
        UINT32 input = atoi(argv[i]);
        UINT32 out_10to256 = conv_10to256(input);
        UINT32 out_256to10 = conv_256to10(out_10to256);
        printf("%d -> %d -> %d\n", input, out_10to256, out_256to10);
    }
}

int main(int argc, char *argv[])
{
    if (!strcmp(argv[0], "./256to"))
        test256to(argc, argv);
    else if (!strcmp(argv[0], "./10to"))
        test10to(argc, argv);
    else if (!strcmp(argv[0], "./loop"))
        test10to256to10(argc, argv);
    else
        printf("cmd\n");
    return 0;
}
