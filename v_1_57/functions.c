#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Swap(double *val01, double *val02)
{
    double temp = *val01;
    *val01 = *val02;
    *val02 = temp;
}

void Print(double const *arrX, int start, int stop)
{
    for(int k = start; k <= stop; k++)
        printf("%4.1lf ",arrX[k]);
    printf("\n");
}



// Метод перестановки максимального элемента.
void Sort00(double *arrX, int arrXSize)
{
    double maxJVal = 0.0;
    int maxJPos = 0;

    for(int i = arrXSize-1; i > 0; i--)
    {
        maxJVal = 0.0;
        for(int j = 0; j < i; j++)
        {
            if(arrX[j] > maxJVal)
            {
                maxJVal = arrX[j];
                maxJPos = j;
            }
        }
        if(arrX[maxJPos] > arrX[i])
        {
            Swap(&arrX[i], &arrX[maxJPos]);
        }

    }
}
// “Пузырьковая” сортировка.
void Sort01(double *arrX, int arrXSize)
{
    for(int k = arrXSize-1; k > 0; k--)
    {
        // подъём до к-й позиции.
        for(int i = 1; i <= k; i++)
        {
            if(arrX[i-1] > arrX[i])
                Swap(&arrX[i-1], &arrX[i]);
        }
    }
//    for(int i = 0; i < arrXSize; i++)
//    {
//        for(int j = (arrXSize-1); j > i; j--)
//        {
//            if(arrX[j-1] > arrX[j])
//                Swap(&arrX[j-1], &arrX[j]);
//        }
//    }
}
// Сортировка вставками с последовательным поиском.
void Sort02(double *arrX, int arrXSize)
{
    for(int i = 1; i < arrXSize; i++)
    {
        for(int j = i; j > 0; j--)
        {


            if(arrX[j-1] < arrX[j])
                break;

            Swap(&arrX[j-1], &arrX[j]);
            Print(arrX, 0, arrXSize-1);
        }
    }
}

int BinSearch(double *arrX, int arrXSize, double xValue, int *xPosition)
{
    int result = 0;
    int left, right, mid;

    if((xValue < arrX[0]))
    {
        *xPosition = 0;
        return 0;
    }
    if(xValue > arrX[arrXSize-1])
    {
        *xPosition = arrXSize;
        return 0;
    }

    left = 0;
    right = arrXSize-1;

    while((right-left) > 1)
    {
        mid = (left + right)/2;
        if(xValue == arrX[mid])
        {
            *xPosition = mid;
            return 1;
        }
        if(xValue > arrX[mid])
            left = mid;
        else
            right = mid;
    }

    //printf("l = %i, m = %i, r = %i\n", left, mid, right);
    if(xValue == arrX[right])
    {
        result = 1;
        *xPosition = right;
    }
    else
    {
        result = 0;
        *xPosition = right;
    }

    return result;
}
// Сортировка вставками с бинарным поиском
void Sort03(double *arrX, int arrXSize)
{
    int xPosition = 0;
    for(int i = 1; i < arrXSize; i++)
    {
        BinSearch(arrX, i-1, arrX[i], &xPosition);
        //printf("arrX[%i] = %lf, pos = %i\n", i, arrX[i], xPosition);
        for(int j = i; j > xPosition; j--)
        {


            if(arrX[j-1] < arrX[j])
                break;

            Swap(&arrX[j-1], &arrX[j]);
            Print(arrX, 0, arrXSize-1);
        }
    }
}
// Сортировка просеиванием.
void Sort04(double *arrX, int arrXSize)
{
    for(int i = 0; i < arrXSize-1; i++)
    {
        if(arrX[i] > arrX[i+1])
        {
            Swap(&arrX[i], &arrX[i+1]);
            for(int k = i; k >= 1; k--)
            {
                if(arrX[k-1] > arrX[k])
                {
                    Swap(&arrX[k-1], &arrX[k]);
                }
            }
        }
    }
}
// Быстрая сортировка (quicksort).
void Sort05(double *arrX, int first, int last)
{
    int f = first;
    int l = last;
    double mid = arrX[(l+f)/2];
    do
    {
        while(arrX[f] < mid)
            f++;
        while(arrX[l] > mid)
            l--;

        if(f <= l)
        {
            Swap(&arrX[f], &arrX[l]);
            f++;
            l--;
        }
    }
    while(f < l);

    if(first < l)
    {
        Print(arrX, first, l);
        Sort05(arrX, first, l);
    }
    if(f < last)
    {
        Print(arrX, f, last);
        Sort05(arrX, f, last);
    }

}
// Пирамидальная (или турнирная) сортировка (heapsort)
void SiftDown(double *arrX, int root, int bottom)
{
    int maxChild;
    int done = 0;
    while((root*2 <= bottom) && (!done))
    {
        // если в последнем ряду.
        if(root*2 == bottom)
            maxChild = root*2; // запомнить левого потомка.
        else if(arrX[root*2] > arrX[root*2+1]) // иначе запоминаем большего потомка из двух.
            maxChild = root*2;
        else
            maxChild = root*2+1;
        //если элемент вершины меньше максимального потомка
        if(arrX[root] < arrX[maxChild])
        {
            Swap(&arrX[root], &arrX[maxChild]);
            root = maxChild;
        }
        else
            done = 1;
    }
}

void Heapify(double *arrX, int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if((l < n) && (arrX[l] > arrX[largest]))
        largest = l;
    if((r < n) && (arrX[r] > arrX[largest]))
        largest = r;

    if(largest != i)
    {
        Swap(&arrX[i], &arrX[largest]);
        Heapify(arrX, n, largest);
    }

}

void Sort06(double *arrX, int arrXSize)
{
//    // формируем нижний ряд пирамиды.
//    for(int i = (arrXSize/2); i >= 0; i--)
//    {
//        SiftDown(arrX, i, arrXSize-1);
//        printf("([%i]) ", i);
//        Print(arrX, 0, arrXSize-1);
//    }
//    printf("-----\n");
//    Print(arrX, 0, arrXSize-1);
//    printf("-----\n");
//    // просеиваем пирамиду через остальные элементы
//    for(int i = arrXSize-1; i >= 1; i--)
//    {
//        Swap(&arrX[0], &arrX[i]);
//        printf("\t");
//        Print(arrX, 0, arrXSize-1);
//        SiftDown(arrX, 0, i-1);
//        Print(arrX, 0, arrXSize-1);
//    }
    for(int i = (arrXSize/2-1); i >= 0; i--)
        Heapify(arrX, arrXSize, i);

    for(int i = arrXSize-1; i>=0; i--)
    {
        Swap(&arrX[0], &arrX[i]);
        Heapify(arrX, i, 0);
    }
}

void Sort07a(double *arrX, int arrXSize, double *arrY, int arrYSize,
            double *arrZ, int *arrZSize)
{
    int i = 0;
    int j = 0;
    *arrZSize = arrXSize + arrYSize;
    for(int k = 0; k < *arrZSize; k++)
    {
        if(i > (arrXSize-1))
        {
            arrZ[k] = arrY[j];
            j++;
        }
        else if(j > (arrYSize-1))
        {
            arrZ[k] = arrX[i];
            i++;
        }
        else if(arrX[i] < arrY[j])
        {
            arrZ[k] = arrX[i];
            i++;
        }
        else if(arrX[i] >= arrY[j])
        {
            arrZ[k] = arrY[j];
            j++;
        }
    }
}
void Sort07(double *arrX, int lo, int hi)
{
    if(lo >= hi)
        return;
    //printf("lo = %i, hi = %i\n", lo, hi);

    int mid = lo + (hi-lo)/2;
    Sort07(arrX, lo, mid);
    //Print(arrX, lo, mid);
    //printf("\n");
    Sort07(arrX, mid+1, hi);
    //Print(arrX, mid+1, hi);
    //printf("\n");

    double* arrBuf = (double*)malloc(sizeof(double) * (hi - lo));
    for(int k = lo; k <= hi; k++)
        arrBuf[k] = arrX[k];

    int i = lo;
    int j = mid+1;
    for(int k = lo; k <= hi; k++)
    {
        if(i > mid)
        {
            arrX[k] = arrBuf[j];
            j++;
        }
        else if(j > hi)
        {
            arrX[k] = arrBuf[i];
            i++;
        }
        else if(arrBuf[j] < arrBuf[i])
        {
            arrX[k] = arrBuf[j];
            j++;
        }
        else
        {
            arrX[k] = arrBuf[i];
            i++;
        }
    }
}

void Merge(double *arrX, uint lb, uint split, uint ub);


void Sort08(double *arrX, uint lb, uint ub)
{
    uint split = 0;

    if(lb < ub)
    {
        split = (lb + ub)/2;
        Sort08(arrX, lb, split);
        Sort08(arrX, split+1, ub);
        Merge(arrX, lb, split, ub);
    }
}




void Merge(double *arrX, uint lb, uint split, uint ub)
{
    uint pos1 = lb;
    uint pos2 = split + 1;
    uint pos3 = 0;

    double *arrTemp = (double*)malloc(sizeof(double) * (ub - lb + 1));
    if(arrTemp == NULL) {printf("Error malloc\n"); return;}

    while((pos1 <= split) && (pos2 <= ub))
    {
        if(arrX[pos1] < arrX[pos2])
        {
            arrTemp[pos3] = arrX[pos1];
            pos1++;
        }
        else
        {
            arrTemp[pos3] = arrX[pos2];
            pos2++;
        }
        pos3++;
    }

    while(pos2 <= ub)
    {
        arrTemp[pos3] = arrX[pos2];
        pos3++;
        pos2++;
    }
    while(pos1 <= split)
    {
        arrTemp[pos3] = arrX[pos1];
        pos3++;
        pos1++;
    }

    for(pos3 = 0; pos3 < (ub - lb + 1); pos3++)
    {
        arrX[lb + pos3] = arrTemp[pos3];
    }

    free(arrTemp);
}


