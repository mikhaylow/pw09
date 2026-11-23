#include <stdio.h>
#include "matrixfunc.h"

void mat_row_average(int *matptr, int row, int cols)
{
    double average = 0.0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            average += *(matptr + i * cols + j);
            if (j == cols - 1)
            {
                printf("Среднее арифметическое строки %d: %.2f\n", i, average / cols);
                average = 0;
            }
        }
    }
}

int last_positive_number(int *matptr, int row, int cols)
{
    int num, current;

    num = 0;
    current = 0;

    for (int i = 1; i < row; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            current = *(matptr + i * cols + j);
            if (current > 0)
            {
                num = current;
            }
        }
    }

    return num;
}

int count_negative_numbers(int *matptr, int row, int cols)
{
    int count = 0;

    for (int i = 1; i < row; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (*(matptr + i * cols + j) < 0)
            {
                count++;
            }
        }
    }

    return count;
}

int print_array_and_address(int *matptr, int row, int cols)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("array: [%d][%d] = %d | address[%p]\n", i, j, *(matptr + i * cols + j), matptr + i * cols + j);
        }
    }

    return 0;
}

int insert_array(int row, int column, int *matptr)
{
    int ch;
    int total_el = row * column;

    for (int i = 0; i < total_el; i++)
    {
        if (scanf("%d", matptr) != 1)
        {
            *matptr = 0;

            while ((ch = getchar()) != '\n' && ch != EOF);
        }
        matptr++;
    }

    return 0;
}