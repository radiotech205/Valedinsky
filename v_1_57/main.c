/*Реализуйте функцию сортировки массива вещественных чисел
по возрастанию
+1. Метод перестановки максимального элемента.
+2. “Пузырьковая” сортировка.
+3. Сортировка вставками с последовательным поиском.
+4. Сортировка вставками с бинарным поиском
+5. Сортировка просеиванием.
6. Быстрая сортировка (quicksort).
7. Пирамидальная (или турнирная) сортировка (heapsort).
8. Сортировка простым слиянием.
9. 2k -ленточное слияние.
10. Естественное слияние
11. Многофазная сортировка.
*/
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#define NUM_MEMB    7



int main(int argc, char* argv[])
{
    const int argNumber = 2;
    if(argc != argNumber)
    {
        printf("Error: argc = %i, must be %i.\n", argc, argNumber);
        return -1;
    }

    double *arrX = (double*)malloc(sizeof(double) * NUM_MEMB);
    int arrXSize = NUM_MEMB;

    int sortMode = 0;

    if(argc >= 2)
        sortMode = atoi(argv[1]);
    else
        sortMode = 0;


    for(int i = 0; i < arrXSize; i++)
    {
        arrX[i] = (double)(rand()%32);
    }
    printf("arrX:\n");
    Print(arrX, 0, arrXSize-1);
    printf("\n");
    /*********************************/
    switch (sortMode) {
    case 0:
        Sort00(arrX, arrXSize);
        break;
    case 1:
        Sort01(arrX, arrXSize);
        break;
    case 2:
        Sort02(arrX, arrXSize);
        break;
    case 3:
        Sort03(arrX, arrXSize);
        break;
    case 4:
        Sort04(arrX, arrXSize);
        break;
    case 5:
        Sort05(arrX, 0, arrXSize-1);
        break;
    case 6:
        Sort06(arrX, arrXSize);
        break;
    case 7:
        Sort07(arrX, 0, arrXSize-1);
        break;
    case 8:
    {
        arrX[0] = 0.3;
        arrX[1] = 0.7;
        arrX[2] = 0.8;

        arrX[3] = 2.0;
        arrX[4] = 4.0;
        arrX[5] = 6.0;
        arrX[6] = 8.0;
        Sort08(arrX, 0, arrXSize-1);

        break;
    }
    default:

        printf("Error of sortMode!\n");
        break;
    }



    /*********************************/
    printf("Sorted:\n");
    Print(arrX, 0, arrXSize-1);
    printf("Hello World!\n");
    return 0;
}



