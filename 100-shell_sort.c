#include "sort.h"
/**
 * shell_sort -  sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * @array: pointer to the array to be printed
 * @size: number of the elements in the array
 * Return: no return
 */

#include "sort.h"

void shell_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	size_t gap = 1;

	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
