#include "sort.h"
/**
 * swap_head - swaps two elements if needed
 * @n: pointer 1st element to be swapped
 * @m: pointer to the 2nd element to be swapped
 * Return: no return
 */
void swap_heap(int *m, int *n)
{
	int temp = *m;
	*m = *n;
	*n = temp;
}
/**
 * max_heapify - applis the heapify method on the
 * no-leaf elements starting from the largest index
 * @array: pointer to the array to be sorted
 * @size: the number of elements in the array
 * @i: the index
 * Return: no return
 */
void max_heapify(int *array, size_t size, size_t i)
{
	size_t largest = i;
	size_t left = (2 * i) + 1;
	size_t right = (2 * i) + 2;

	if (left < size && array[left] > array[largest])
		largest = left;
	if (right < size && array[right] > array[largest])
		largest = right;
	if (largest != i)
	{
		swap_heap(&array[i], &array[largest]);
		print_array(arra, size);
		max_heapify(array, size, largest);
	}
}
/**
 * heap_sort - sorts an array of integers in ascending
 * order using the Heap sort algorithm
 * @array: pointer to the array to be printed
 * @size: number of the elements in the array
 * Return: no return
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (!array || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		max_heapify(array, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_heap(&array[0], &array[i]);
		print_array(array, size);
		max_heapify(array, i, 0);
	}
}
