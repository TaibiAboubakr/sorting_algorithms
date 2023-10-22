#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending
 * order using the Counting sort algorithm
 * @array: pointer to the array to be sorted
 * @size: the number of elements in the array
 * Return: no return
 */
void counting_sort(int *array, size_t size)
{
	int k_max = array[0];
	size_t i;
	int *count = (int *)malloc(sizeof(int) * (k_max + 1));
	int *array2 = (int *)malloc(sizeof(int) * size);

	if (!array || size < 2 || count == NULL || array2 == NULL)
	{
		free(count);
		free(array2);
		return;
	}

	for (i = 0; i < size; i++)
	{
		if (array[i] > k_max)
			k_max = array[i];
	}

	for (i = 0; i <= (size_t)k_max; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[array[i]]++;

	for (i = 1; i <= (size_t)k_max; i++)
		count[i] += count[i - 1];
	print_array(count, k_max + 1);

	for (i = size - 1; i < size; i--)
	{
		array2[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = array2[i];
}
