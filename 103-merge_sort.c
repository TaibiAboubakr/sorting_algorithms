#include "sort.h"
/**
 * merge_sort_rec - function that calls
 * sorted_array_merge function
 * @array: pointer to the array
 * @left: left most element in the array
 * @right: right most element in the array
 * Return: no return
 */
void merge_sort_rec(int *array, int left, int right)
{
	int mid = left + (right - left) / 2;
	int i;

	if (left < right)
	{
		merge_sort_rec(array, left, mid);
		merge_sort_rec(array, mid + 1, right);
		sorted_array_merge(array, left, mid, right);

		printf("Merging...\n");
		printf("[left]: ");
		for (i = left; i <= mid; i++)
		{
			printf("%d", array[i]);
			if (i < mid)
				printf(", ");
		}
		printf("\n[right]: ");
		for (i = mid + 1; i <= right; i++)
		{
			printf("%d", array[i]);
			if (i < right)
				printf(", ");
		}
		printf("\n[Done]: ");
		for (i = left; i <= right; i++)
		{
			printf("%d", array[i]);
			if (i < right)
				printf(", ");
		}
		printf("\n");
	}
}
/**
 * sorted_array_merge - Merge two sorted sub-arrays into a single sorted array.
 * @array: Pointer to the array.
 * @left: Index of the leftmost element in the array.
 * @mid: Index of the middle element in the array.
 * @right: Index of the rightmost element in the array.
 */
void sorted_array_merge(int *array, int left, int mid, int right)
{
	int left_len = mid - left + 1;
	int right_len = right - mid;
	int *temp_l = (int *)malloc(left_len * sizeof(int));
	int *temp_r = (int *)malloc(right_len * sizeof(int));
	int i, a = 0, b = 0, c = left;

	if (!temp_l || !temp_r)
		exit(1);
	for (i = 0; i < left_len; i++)
		temp_l[i] = array[left + i];
	for (i = 0; i < right_len; i++)
		temp_r[i] = array[mid + 1 + i];

	while (a < left_len && b < right_len)
		array[c++] = (temp_l[a] <= temp_r[b]) ? temp_l[a++] : temp_r[b++];
	while (a < left_len)
		array[c++] = temp_l[a++];
	while (b < right_len)
		array[c++] = temp_r[b++];
	free(temp_l);
	free(temp_r);
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: pointer to the array to be sorted
 * @size: the number of the elements in the array
 * Return: no return
 */
void merge_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	merge_sort_rec(array, 0, size - 1);

}
