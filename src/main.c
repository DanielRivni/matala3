#include <stdio.h>
#include <stdlib.h>
#include "isort.c"
#define SIZE 50

int main()
{
    int numbers[SIZE];
    int count = 0;
    while (count < 50)
    {
        scanf("%d", &numbers[count++]);
    }

    insertion_sort(numbers, count);

    for (int i = 0; i < count - 1; i++)
    {
        printf("%d,", numbers[i]);
    }
    printf("%d\n", numbers[count - 1]);

    return 0;
}
