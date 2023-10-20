#include "sort.h"
/**
 * shell_sort -  sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * @array: pointer to the array to be printed
 * @size: number of the elements in the array
 * Return: no return
 */

void shell_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	size_t h = 1;

	while (h <= size / 3)
	{
		h = (h * 3) - 1;
	}
	while (h > 0)
	{
		for (i = h; i < size; i++)
		{
			temp = array[i];
			j = i;
			while (j > h - 1 && array[j - h] > temp)
			{
				array[j] = array[j - h];
				j = j - h;
			}
			array[j] = temp;
		}
		print_array(array, size);
		h = (h - 1) / 3;
	}
}
