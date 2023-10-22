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
	int k_max = array[0], *count_arr, *array2;
	size_t i;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
		{
		if (array[i] > k_max)
			k_max = array[i]; }

	count_arr = (int *)malloc(sizeof(int) * (k_max + 1));
	array2 = (int *)malloc(sizeof(int) * size);

	if (!count_arr || !array2)
	{	free(count_arr);
		free(array2);
		return;	}

	for (i = 0; i <= (size_t)k_max; i++)
		count_arr[i] = 0;

	for (i = 0; i < size; i++)
		count_arr[array[i]] += 1;

	for (i = 1; i <= (size_t)k_max; i++)
		count_arr[i] += count_arr[i - 1];

	print_array(count_arr, k_max + 1);

	for (i = 0; i < size ; i++)
	{	tmp = array[i];
		count_arr[tmp] = count_arr[tmp] - 1;
		array2[count_arr[tmp]] = tmp;
		}

	for (i = 0; i < size; i++)
		array[i] = array2[i];
	free(array2);
}
