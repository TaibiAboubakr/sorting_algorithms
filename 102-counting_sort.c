#include "sort.h"
/**
 * counting_sort - sorts an array of integers in ascending
 * order using the Counting sort algorithm
 * @array: pointer to the array to be printed
 * @size: the number of elements in the array
 * Return: no return
 */
void counting_sort(int *array, size_t size)
{
	int k_max = array[0];
	int j;
	size_t i;
	int *count = (int *)malloc(sizeof(int) * (k_max + 1));
	int *array2 = (int *)malloc(sizeof(int) * size);

	if (!array || size < 2)
	{
		free(count);
		free(array2);
		return;
	}

	for (i = 1; i < size; i++)
	{
		if (array[i] > k_max)
			k_max = array[i];

	}
	if (count == NULL || array2 == NULL)
	{
		free(count);
		free(array2);
		return;
	}
	for (j = 0; j <= k_max; j++)
		count[j] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (j = 1; j <= k_max; j++)
		count[j] += count[j - 1];
	for (j = size - 1; j >= 0; j--)
	{
		array2[count[array[j]] - 1] = array[j];
		count[array[j]]--;
	}
	for (i = 0; i < size; i++)

		array[i] = array2[i];
	print_array(count, k_max + 1);
}
