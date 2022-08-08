
#include "heap_sort.h"
#include "stdint.h"

void HeapSort(int32_t* arr, uint16_t size, uint8_t dir);
void MaxMinHeapify(int32_t* arr, uint16_t maxIndex, uint8_t dir, int32_t index);
void Swap(int32_t* a, int32_t* b);

void HeapSort(int32_t* arr, uint16_t size, uint8_t dir)
{
    uint16_t maxIndex = size - 1;
    int32_t index, tempIdx, temp, son;
    int16_t i;
    
    //find parent of last index
    if ((maxIndex) % 2 == 0)
    {
        index = (maxIndex-2)/2;
    }
    else
    {
        index = (maxIndex-1)/2;
    }

    for (i = maxIndex; i >= 0; i--)
    {
        MaxMinHeapify(arr, maxIndex, dir, i);
    }
    
    for (i = maxIndex; i > 0; i--)
    {
        Swap(&arr[0], &arr[i]);
        MaxMinHeapify(arr, (i-1), dir, 0);
    }

}

void MaxMinHeapify(int32_t* arr, uint16_t maxIndex, uint8_t dir, int32_t index)
{
    int32_t son;
    
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

void Swap(int32_t* a, int32_t* b)
{
    int32_t temp = *a;
    *a = *b;
    *b = temp;
}

