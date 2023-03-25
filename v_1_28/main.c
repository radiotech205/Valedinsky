/*1.28. Определите и напечатайте все отрезки монотонности после-
довательности с явным указанием типа монотонности. Каждый отрезок
печатается с новой строки.*/
#include <stdio.h>
#include <stdlib.h>

void MonotonePrint(FILE *file, int type);
void MonotonePrint2(FILE *file);
int main()
{
    FILE *file = fopen("../fileGen32.txt", "r");
    if(file == NULL)
    { printf("Error of file\n"); return -1;}

    MonotonePrint(file,1);
    rewind(file);
    MonotonePrint(file,2);
    rewind(file);
    printf("---------------------\n");
    MonotonePrint2(file);

    fclose(file);
    printf("Hello World!\n");
    return 0;
}

void MonotonePrint(FILE *file, int type)
{
    int x1 = 0;
    int x2 = 0;

    int enaInc = 0;
    int enaDec = 0;

    if(1 != fscanf(file, "%i", &x1))
        return;

    while(1 == fscanf(file, "%i", &x2))
    {
        if(type == 1)
        {
            if(x1 < x2)
            {
                if(!enaInc)
                    printf("Increase:");

                printf("%i ", x1);
                enaInc = 1;
            }
            else if(enaInc)
            {
                printf("%i \n", x1);
                enaInc = 0;
            }
        }
        else if(type == 2)
        {
            if(x1 > x2)
            {
                if(!enaDec)
                    printf("Dicrease:");

                printf("%i ", x1);
                enaDec = 1;
            }
            else if(enaDec)
            {
                printf("%i \n", x1);
                enaDec = 0;
            }
        }
        x1 = x2;
    }
}

void MonotonePrint2(FILE *file)
{
    int x1 = 0;
    int x2 = 0;

    int *arrInc = (int*)malloc(sizeof(int) * 1024);
    int arrIncCnt = 0;
    int *arrDec = (int*)malloc(sizeof(int) * 1024);
    int arrDecCnt = 0;

    int enaInc = 0;
    int enaDec = 0;

    if(1 != fscanf(file, "%i", &x1))
        return;

    while(1 == fscanf(file, "%i", &x2))
    {
        if(x1 < x2)
        {
            arrInc[arrIncCnt] = x1;
            arrIncCnt++;
            enaInc = 1;
        }
        else if(enaInc)
        {
            arrInc[arrIncCnt] = x1;
            arrIncCnt++;
            enaInc = 0;
        }
        if((!enaInc) && (arrIncCnt > 0))
        {
            printf("Increase:");
            for(int i = 0; i < arrIncCnt; i++)
                printf("%i ",arrInc[i]);
            printf("\n");
            arrIncCnt = 0;
        }

        if(x1 > x2)
        {
            arrDec[arrDecCnt] = x1;
            arrDecCnt++;
            enaDec = 1;
        }
        else if(enaDec)
        {
            arrDec[arrDecCnt] = x1;
            arrDecCnt++;
            enaDec = 0;
        }
        if((!enaDec) && (arrDecCnt > 0))
        {
            printf("Decrease:");
            for(int i = 0; i < arrDecCnt; i++)
                printf("%i ",arrDec[i]);
            printf("\n");
            arrDecCnt = 0;
        }

        x1 = x2;
    }
}
