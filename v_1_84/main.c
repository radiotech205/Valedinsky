#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *strcpy2(char *dst, char *src);

int main()
{
    char *src = strdup("Copy Me!");
    char *dst = (char*)malloc(1024);
    char *dstS = strcpy2(dst, src);

    printf("src: %s\n", src);
    printf("dst: %s\n", dst);
    printf("dstS %s\n", dstS);

    free(src);
    printf("Hello World!\n");
    return 0;
}

char *strcpy2(char *dst, char *src)
{
    int i = 0;
    for(i = 0; src[i] != '\0'; i++)
        dst[i] = src[i];
    dst[i+1] = '\0';
    char *s = dst;
    return s;
}
