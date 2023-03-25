#include <stdio.h>
#include <stdlib.h>

int Reverse(int xValue);
int MakePower(int base, int pointer);


int main(int argc, char *argv[])
{
    int xValue = (argc >= 2) ? atoi(argv[1]) : 0;

    int yValue = Reverse(xValue);

    printf("xValue = %i, yValue = %i\n", xValue, yValue);

    printf("Hello World!\n");
    return 0;
}


int Reverse(int xValue)
{
    int tenOrder = 0;
    int mullFactor = 10;
    for(; xValue/mullFactor; tenOrder++, mullFactor *= 10) ;

    tenOrder++;

    int *arr = (int*)malloc(sizeof(int) * (tenOrder + 1));
    int value = 0;
    mullFactor = 1;
    int result = 0;
    int power = 0;
    for(int i = 0; i < tenOrder; i++)
    {
        value = (xValue / (mullFactor))%10;
        mullFactor *= 10;
        arr[i] = value;
    }

    for(int i = tenOrder-1; i >= 0; i--)
    {
        power = MakePower(10, (tenOrder-1)-i);
        result += arr[i] * power;

    }

    free(arr);

    return result;
}

int MakePower(int base, int pointer)
{
    int result = 1;
    for(int i = 1; i <= pointer; i++)
    {
        result *= base;
    }
    return result;
}
