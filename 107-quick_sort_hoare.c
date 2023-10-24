#include "sort.h"

/**
 * swap_numbers - function that swaps two integers
 * @a: pointer to the number 1
 * @b: pointer to the number 2
 */
void swap_numbers(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * hoare_partition - Hoare partition scheme
 * @array: array to be partitioned
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: the size of the array
 * Return: the index of the pivot
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[low];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		swap_numbers(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * quick_sort_hoare - Quick sort using Hoare partition scheme
 * @array: array to be sorted
 * @size: the size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_sort_rec_hoare(array, 0, size - 1, size);
}

/**
 * quick_sort_rec_hoare - function that calls hoare_partition
 * @array: array to be sorted
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: the size of the array
 */
void quick_sort_rec_hoare(int *array, int low, int high, size_t size)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = hoare_partition(array, low, high, size);
		quick_sort_rec_hoare(array, low, pivot_idx, size);
		quick_sort_rec_hoare(array, pivot_idx + 1, high, size);
	}
}
