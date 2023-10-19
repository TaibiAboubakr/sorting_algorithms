#include "sort.h"


/**
 * swap_numbers - function that swap two integers
 * @a: pointer to the number 1
 * @b: pointer to the number 2
*/

void swap_numbers(int *a, int *b)
{
int temp;

temp = *a;
*a = *b;
*b = temp;
}

/**
 * bubble_sort - function that sorts an array of integers in ascending order
 *				using the Bubble sort algorithm
 * @array: array to be sorted
 * @size: the size of the array
*/

void bubble_sort(int *array, size_t size)
{
size_t i = 0, j = 0;
bool swap = false;

if (!array || size < 2)
	return;

for (i = 0; i < size; i++)
{
	for (j = 0; j < size - 1 - i; j++)
	{
		if (array[j] > array[j + 1])
			{ swap_numbers(&array[j], &array[j + 1]);
			print_array(array, size);
			swap = true; }
	}
	if (!swap)
		break;

}

}
