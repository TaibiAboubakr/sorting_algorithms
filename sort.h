#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
int n;
struct listint_s *prev;
struct listint_s *next;
} listint_t;


void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap_numbers(int *a, int *b);
void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void swap_nodes(listint_t *b, listint_t *c);
void insertion_sort_list(listint_t **list);
void quick_sort(int *array, size_t size);
void quick_sort_rec(int *array, int low, int high, size_t size);
int lomuto_part(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void merge_sort_rec(int *array, int left, int right);
void sorted_array_merge(int *array, int left, int mid, int right);
void merge_sort(int *array, size_t size);
void quick_sort_rec_hoare(int *array, int low, int high, size_t size);
void quick_sort_hoare(int *array, size_t size);
int hoare_partition(int *array, int low, int high, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_nodes1(listint_t **list, listint_t *node1, listint_t *node2);
void heap_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);

#endif /* SORT_H */
