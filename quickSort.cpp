#include "quickSort.h"

int partition(std::vector<int>& v, int start, int end)
{
    auto pivot = v[start];

    int count = 0;

    for (int i = start + 1; i <= end; i++)
    {
        if (v[i] <= pivot)
        {
            count++;
        }
    }

    int pivotIndex = start + count;

    std::swap(v[pivotIndex], v[start]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex)
    {

        while (v[i] <= pivot)
        {

            i++;
        }

        while (v[j] > pivot)
        {

            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            std::swap(v[i++], v[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(std::vector<int>& v, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int p = partition(v, start, end);

    quickSort(v, start, p - 1);

    quickSort(v, p + 1, end);
}
 