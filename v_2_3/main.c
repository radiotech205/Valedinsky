#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double FactCalc(double n)
{
    if(n > 1.0)
       return n * FactCalc(n - 1.0);
    else
        return 1.0;
}

int main(int argc, char **argv)
{
    int numMemb = argc > 1 ? atoi(argv[1]) : 0;

    double sum = 0.0;
    // forwardSum;
    for(int k = 1; k <= numMemb; k++)
    {
        sum += pow(-1.0, (double)k) * 1.0/sqrt((double)k);
    }
    printf("forwardSum = %lf\n", sum);
    sum = 0.0;

    // backwardSum;
    for(int k = numMemb; k > 0; k--)
    {
        sum += 1.0/sqrt((double)k);
    }
    printf("backwardSum = %lf\n", sum);
        sum = 0.0;
    printf("/********************************/\n");
    // forwardSum;
    for(int k = 1; k <= numMemb; k++)
    {
        sum += pow(-1.0, (double)k) *log((double)k)/sqrt((double)k);
    }
    printf("forwardSum = %lf\n", sum);
    sum = 0.0;

    // backwardSum;
    for(int k = numMemb; k > 0; k--)
    {
        sum += log((double)k)/sqrt((double)k);
    }
    printf("backwardSum = %lf\n", sum);
    sum = 0.0;
    printf("/********************************/\n");
    // forwardSum;
    for(int k = 1; k <= numMemb; k++)
    {
        sum += pow(-1.0, (double)k) *1.0/((double)k);
    }
    printf("forwardSum = %lf\n", sum);
    sum = 0.0;

    // backwardSum;
    for(int k = numMemb; k > 0; k--)
    {
        sum += 1.0/((double)k);
    }
    printf("backwardSum = %lf\n", sum);
    sum = 0.0;
    printf("/********************************/\n");
    // forwardSum;
    for(int k = 1; k <= numMemb; k++)
    {
        sum += pow(-1.0, (double)k) *1.0/pow((double)k, 2.0);
    }
    printf("forwardSum = %lf\n", sum);
    sum = 0.0;

    // backwardSum;
    for(int k = numMemb; k > 0; k--)
    {
        sum += 1.0/pow((double)k, 2.0);
    }
    printf("backwardSum = %lf\n", sum);
    sum = 0.0;
    printf("/********************************/\n");
    // forwardSum;
    for(int k = 1; k <= numMemb; k++)
    {
        sum += pow(-1.0, (double)k) *1.0/FactCalc((double)k);
    }
    printf("forwardSum = %lf\n", sum);
    sum = 0.0;

    // backwardSum;
    for(int k = numMemb; k > 0; k--)
    {
        sum += 1.0/FactCalc((double)k);
    }
    printf("backwardSum = %lf\n", sum);
    sum = 0.0;
    printf("/********************************/\n");



    printf("Hello World!\n");
    return 0;
}


