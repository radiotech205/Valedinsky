#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
/*
 * Реализуйте функции, выполняющие стандартные операции с
текстовыми строками: strncpy, strcmp, strstr, strcat, strspn, strcspn
 */
char * strncpy2(char *dst, char *src, size_t n);
int strcmp2(char *arrA, char *arrB);
char * strstr2(char *arrA, char *arrB);
char * strcat2(char *dst, char *src);
size_t strspn2(char *arrA, char *arrB);
size_t strcspn2(char *arrA, char *arrB);


int main()
{
    char *src = strdup("Hello, World\n");
    char *dst = (char*)malloc(1024);

    char *str = strncpy2(dst, src, 10);
    printf("dst = %s\n", dst);
    printf("str = %s\n", str);

    int cmpResult = strcmp2(src, dst);
    printf("cmpResult = %i\n", cmpResult);

    char *strResult = strstr2(src, "World");
    printf("strResult = %s\n", strResult);

    char *catResult = strcat2(dst, src);
    printf("dst = %s\n", dst);
    printf("str = %s\n", str);
    printf("catResult = %s\n", catResult);

    char strSpn[80] = "123 abc";
    size_t spnResult = strspn2(strSpn, "321");
    printf("spnResult = %li\n", spnResult);

    size_t cspnResult = strcspn2(strSpn, "cba");
    printf("cspnResult = %li\n", cspnResult);

    free(src);
    free(catResult);
    printf("Hello World!\n");
    return 0;
}

char * strncpy2(char *dst, char *src, size_t n)
{
    uint32_t i = 0;
    for(i = 0; (i < n) && src[i] != '\0'; i++)
    {
        dst[i] = src[i];
    }
    dst[i+1] = '\0';
    char *s = dst;
    return s;
}

int strcmp2(char *arrA, char *arrB)
{
    int i = 0;
    for(i = 0; arrA[i] == arrB[i]; i++)
    {
        if(arrA[i] == '\0')
            return 0;
    }
    return arrA[i] - arrB[i];
}

char * strstr2(char *arrA, char *arrB)
{
    uint32_t arrASize = strlen(arrA);
    uint32_t arrBSize = strlen(arrB);
    uint32_t arrACnt = 0;
    uint32_t arrBCnt = 1;

    uint32_t trigg = 0;

    char* result = NULL;

    for(uint32_t i = 0; (i < arrASize); i++)
    {
        if(trigg == 0)
        {
            if(arrA[i] == arrB[0])
            {
                arrACnt = i;
                trigg = 1;
            }
        }
        else
        {
            if(arrA[i] == arrB[arrBCnt])
            {
                arrBCnt++;
            }
            else
            {
                trigg = 0;
            }
        }
    }

    if(arrBCnt == arrBSize)
        result = &arrA[arrACnt];
    else
        result = NULL;

    return result;
}

char * strcat2(char *dst, char *src)
{
    uint32_t dstSize = strlen(dst);
    uint32_t srcSize = strlen(src);

    char *stringMalloc = (char*)malloc(dstSize + srcSize + 2);
    for(uint32_t i = 0; i < dstSize; i++)
        stringMalloc[i] = dst[i];

    for(uint32_t i = 0; i < srcSize; i++)
    {
        stringMalloc[dstSize + i] = src[i];
    }
    stringMalloc[dstSize + srcSize + 1] = '\0';

    char *s = stringMalloc;
    dst = stringMalloc;
    return s;
}

size_t strspn2(char *arrA, char *arrB)
{
    uint32_t arrASize = strlen(arrA);// строка.
    uint32_t arrBSize = strlen(arrB);// подстрока.
    uint32_t coincide = 0;
    uint32_t j = 0;
    size_t result = 0;

    for(uint32_t i = 0; i < arrASize; i++)
    {
        for(j = 0; j < arrBSize; j++)
        {
            if(arrA[i] == arrB[j])
            {
                coincide = 1;
                break;
            }
        }
        if((j == arrBSize) && (coincide == 0))
        {
            result = i;
            break;
        }

        coincide = 0;

    }
    return result;
}

size_t strcspn2(char *arrA, char *arrB)
{
    uint32_t arrASize = strlen(arrA);// строка.
    uint32_t arrBSize = strlen(arrB);// подстрока.
    uint32_t coincide = 0;
    uint32_t j = 0;
    size_t result = 0;

    for(uint32_t i = 0; i < arrASize; i++)
    {
        for(j = 0; j < arrBSize; j++)
        {
            if(arrA[i] == arrB[j])
            {
                coincide = 1;
                break;
            }
        }
        if(coincide == 1)
        {
            result = i;
            break;
        }

        coincide = 0;

    }
    return result;
}
