#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

int eq_quadr(double koeffA, double koeffB, double koeffC, double *x1, double *x2);

int main(int argc, char **argv)
{
    double koeffA = argc >= 2 ? atof(argv[1]) : 0.0;
    double koeffB = argc >= 3 ? atof(argv[2]) : 0.0;
    double koeffC = argc >= 4 ? atof(argv[3]) : 0.0;

    double x1, x2;

    int result = eq_quadr(koeffA, koeffB, koeffC, &x1, &x2);
    switch (result) {
    case -2:
        printf("no roots\n");
        break;
    case -1:
        printf("complex roots: %lf + j%lf\n", x1, x2);
        break;
    case 0:
        printf("single root: x1 = %lf, x2 = %lf\n", x1, x2);
        break;
    case 1:
        printf("two roots: x1 = %lf, x2 = %lf\n", x1, x2);
        break;
    }

    printf("Hello World!\n");
    return 0;
}


int eq_quadr(double koeffA, double koeffB, double koeffC, double *x1, double *x2)
{
    double norma = sqrt(koeffA*koeffA + koeffB*koeffB + koeffC*koeffC);
    if(norma > DBL_MAX_EXP)
        return -2;


    if((fabs(koeffA) < 1.0e-9) && (fabs(koeffB) < 1.0e-9) && (fabs(koeffC) > 1.0e-9))
        return -2;

    koeffA /= norma;
    koeffB /= norma;
    koeffC /= norma;

    double diskr = koeffB*koeffB - 4.0 * koeffA * koeffC;
    if(diskr < 0.0)
    {
        *x1 = -koeffB/(2.0 * koeffA);
        *x2 = sqrt(fabs(diskr))/2.0*koeffA;
        return -1;
    }
    else if(fabs(diskr) < 1.0e-23)
    {
        *x1 = -koeffB/(2.0 * koeffA);
        return 0;
    }
    else
    {
        *x1 = (-koeffB - sqrt(diskr))/(2.0*koeffA);
        *x2 = (-koeffB + sqrt(diskr))/(2.0*koeffA);
        return 1;
    }
    return -2;
}
