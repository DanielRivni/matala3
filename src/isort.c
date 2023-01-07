#include <stdio.h>

void shift_element(int *arr, int i)
{

    int *p = arr + i - 1;

    while (p >= arr)
    {
        *(p + 1) = *(p);
        p--;
    }
}

void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d,", arr[i]);
    }

    printf("\n");
}

void insertion_sort(int *arr, int len)
{
    for (int i = 1; i < len; i++)
    {
        int select = *(arr + i);

        int j = i - 1;
        while (j >= 0 && *(arr + j) > select)
        {
            shift_element(arr + j, 1);
            j--;
        }

        *(arr + j + 1) = select;
    }
}
