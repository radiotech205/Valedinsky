#include <stdio.h>
#include <stdlib.h>

int NodComputer(int xValue, int yValue);

int main(int argc, char *argv[])
{
    int xValue = (argc >= 2) ? atoi(argv[1]) : 1;
    int yValue = (argc >= 3) ? atoi(argv[2]) : 1;

    int nodValue =  NodComputer(xValue, yValue);

    printf("xValue = %i, yValue = %i, nodValue = %i\n",
           xValue, yValue, nodValue);

    printf("Hello World!\n");
    return 0;
}

int NodComputer(int xValue, int yValue)
{
    int zValue = 0;
    int aValue = 1;

    int nodValue = 0;
    int cnt = 0;

    while(aValue)
    {
        zValue = xValue / yValue;
        aValue = xValue % yValue;

        if(aValue == 0)
        {
            nodValue = yValue;
            break;
        }

        xValue = yValue;
        yValue = aValue;


        cnt++;
    }

    return nodValue;
}
