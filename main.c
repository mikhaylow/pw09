#include "matrixfunc.h"
#include <stdio.h>

void clear_buffer();
char get_choice_char();
void enter_to_main_menu();
void print_start_menu();
void with_vla_mat(int row, int column);

int main(void)
{
    // option 5

    int row, column;
    row = 0;
    column = 0;

    print_start_menu();

    char choice = get_choice_char();

    if (choice == 'a')
    {
        printf("Введите число строк и столбцов для создания двумерного массива\n");

        if (scanf("%d %d", &row, &column) == 2)
        {
            clear_buffer();

            if (row <= 0 || column <= 0)
            {
                printf("Размерность массива не может быть 0 или отрицательный\n");
            }
        }
        else
        {
            printf("Некорректный ввод. Введите целое число\n");
            clear_buffer();
        }

        enter_to_main_menu();
    }
    else
    {
        printf("Сначала задайте размер массива\n");
        return -1;
    }

    with_vla_mat(row, column);

    return 0;
}

void with_vla_mat(int row, int column)
{
    int choice, flag, status;

    choice = 0;
    flag = 1;
    status = 0;

    int matptr[row][column];

    while (flag)
    {
        print_start_menu();

        choice = get_choice_char();

        if (choice < 'a' || choice > 'g')
        {
            printf("Неверный ввод. Введите символ (a-g)\n");
            continue;
        }

        switch (choice)
        {
        case 'a':
            printf("Размер массива уже задан\n");
            continue;
            
        case 'b':
            printf("Введите значения для заполнения массива\n");

            status = insert_array(row, column, &matptr[0][0]);
            if (status == 0)
            {
                printf("Массив успещно заполнен\n");
            }

            enter_to_main_menu();

            break;

        case 'c':
            status = print_array_and_address(&matptr[0][0], row, column);
            if (status != 0)
                break;

            enter_to_main_menu();

            break;

        case 'd':
            mat_row_average(&matptr[0][0], row, column);

            enter_to_main_menu();

            break;

        case 'e':
            int count = count_negative_numbers(&matptr[0][0], row, column);

            printf("Количество отрицательных элементов в матрице: %d\n", count);

            enter_to_main_menu();

            break;

        case 'f':
            int last_positive = last_positive_number(&matptr[0][0], row, column);

            printf("Последнее положительный элемент: %d\n", last_positive);

            enter_to_main_menu();

            break;

        case 'g':
            printf("До свидания!.\n");
            flag = 0;
            break;
        }
    }
}

void clear_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

char get_choice_char()
{
    char choice = '0';

    while (1)
    {
        if (scanf("%c", &choice) == 1)
        {
            clear_buffer();

            return choice;
        }

        clear_buffer();

        printf("Введите корректный символ\n");
    }
}

void enter_to_main_menu()
{
    printf("Введите ENTER для возврата в главное меню\n");

    clear_buffer();
}

void print_start_menu(void)
{
    printf("a\tЗадать размер матрицы\n"
           "b\tЗаполнить матрицу\n"
           "c\tПредставление матрицы\n"
           "d\tСреднее арифметическое в каждой строке\n"
           "e\tКоличество отрицательных элементов в матрице\n"
           "f\tПоследний положительный элемент в матрице\n"
           "g\tВыход\n");
}