
#include "heap_sort.h"
#include "stdint.h"

void HeapSort(int16_t* arr, uint16_t size);
void MaxMinHeapify(int16_t* arr, uint16_t maxIndex, int16_t index);
void Swap(int16_t* a, int16_t* b);

void HeapSort(int16_t* arr, uint16_t size)
{
    uint16_t maxIndex = size - 1;
    int16_t i;

    for (i = ((maxIndex-1)/2); i >= 0; i--)//(maxIndex-1)/2) = Last parent
    {
        MaxMinHeapify(arr, maxIndex, i);
    }
    
    for (i = maxIndex; i > 0; i--)
    {
        Swap(&arr[0], &arr[i]);
        MaxMinHeapify(arr, (i-1), 0);
    }
}

void MaxMinHeapify(int16_t* arr, uint16_t maxIndex, int16_t index)
{
    int16_t son;
    
    son = index*2+1;
    
    while (son <= maxIndex)
    {
        if (((son+1) <= maxIndex) && (arr[son+1] > arr[son]))//find bigger son
        {   
            son++; //right son is bigger
        }

        if (arr[index] < arr[son])
        {
            Swap(&arr[index], &arr[son]);
        }

        index = son;
        son = son*2 + 1;
    }
}

void Swap(int16_t* a, int16_t* b)
{
    int16_t temp = *a;
    *a = *b;
    *b = temp;
}

