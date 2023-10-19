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
 * quick_sort_rec - function that call lomuto_part
 * @array: array to be sorted
 * @size: the size of the array
 * @low: subset 1
 * @high: subset 2
 */
void quick_sort_rec(int *array, int low, int high, size_t size)
{
int pivot_idx;

if (low >= high)
	return;
pivot_idx = lomuto_part(array, low, high, size);
quick_sort_rec(array, low, pivot_idx - 1, size);
quick_sort_rec(array, pivot_idx + 1, high, size);
}

/**
 * lomuto_part - function that divide array to subsets
 * @array: array to be sorted
 * @size: the size of the array
 * @low: subset 1
 * @high: subset 2
 * Return: the index of the pivot
*/
int lomuto_part(int *array, int low, int high, size_t size)
{
int pivot, i, j;

pivot = array[high];
i = low;

for (j = low; j < high; j++)
{
	if (array[j] < pivot)
	{
		if (i < j)
		{	swap_numbers(&array[i], &array[j]);
			print_array(array, size); }
		i++;
	}
}
	if (array[i] > pivot)
	{swap_numbers(&array[i], &array[high]);
	print_array(array, size); }
return (i);
}

/**
 * quick_sort - function that sorts an array of integers in ascending order
 *				using the quick sort algorithm
 * @array: array to be sorted
 * @size: the size of the array
*/

void quick_sort(int *array, size_t size)
{
if (!array || size < 2)
	return;

quick_sort_rec(array, 0, size - 1, size);

}
