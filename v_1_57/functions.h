#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define PRINT_VAR_NAME(var) #var
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


void Print(double const *arrX, int start, int stop);

void Sort00(double *arrX, int arrXSize);
void Sort01(double *arrX, int arrXSize);
void Sort02(double *arrX, int arrXSize);
void Sort03(double *arrX, int arrXSize);
void Sort04(double *arrX, int arrXSize);
void Sort05(double *arrX, int first, int last);
void Sort06(double *arrX, int arrXSize);
void Sort07a(double *arrX, int arrXSize, double *arrY, int arrYSize,
            double *arrZ, int *arrZSize);
void Sort07(double *arrX, int lo, int hi);
void Sort08(double *arrX, uint lb, uint ub);
#endif // FUNCTIONS_H
