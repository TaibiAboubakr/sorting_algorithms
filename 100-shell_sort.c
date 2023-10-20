#include <stddef.h>

void shell_sort(int *array, size_t size) 
{
    // Calculate the initial gap using the Knuth sequence
    size_t gap = 1;
    while (gap < size / 3) {
        gap = gap * 3 + 1;
    }

    while (gap > 0) {
        // Perform insertion sort on subarrays with the given gap
        for (size_t i = gap; i < size; i++) {
            int temp = array[i];
            size_t j = i;

            // Shift elements that are greater than the current element
            while (j >= gap && array[j - gap] > temp) {
                array[j] = array[j - gap];
                j -= gap;
            }

            // Place the current element in its correct position
            array[j] = temp;
        }

        // Calculate the next gap using the Knuth sequence
        gap = (gap - 1) / 3;
    }
}
