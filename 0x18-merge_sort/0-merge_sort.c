#include "sort.h"
/**
 * print_split - Prints an array of integers
 *
 * @array: The array to be printed
 * @start: start of array to print
 * @end: end of array to print
 */
void print_split(const int *array, size_t start, size_t end)
{
	size_t i;

	for (i = start; i < end; i++)
	{
		if (i > start)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}
/**
* top_down_merge - merge the splited array
* @B: source array
* @start: start of the array to split
* @middle: middle of the array to merge
* @end: end of the array to split
* @A: array to be sorte
*/
void top_down_merge(int *A, size_t start, size_t middle, size_t end, int *B)
{
	size_t s = start, m = middle, i;

	printf("Merging...\n");
	printf("[left]: ");
	print_split(A, start, middle);
	printf("[right]: ");
	print_split(A, middle, end);
	for (i = start; i < end; i++)
	{
		if (s < middle && (m >= end || A[s] <= A[m]))
		{
			B[i] = A[s];
			s  = s + 1;
		}
		else
		{
			B[i] = A[m];
			m = m + 1;
		}
	}
	printf("[Done]: ");
	print_split(B, start, end);
}
/**
* top_down_split - split the array
* @B: source array
* @start: start of the array to split
* @end: end of the array to split
* @A: array to be sorte
*/
void top_down_split(int *B, size_t start, size_t end, int *A)
{
	size_t middle;

	if (end - start <= 1)
		return;
	middle = (start + end) / 2;
	top_down_split(A, start, middle, B);
	top_down_split(A, middle, end, B);
	top_down_merge(B, start, middle, end, A);
}
/**
* merge_sort - Sort algorithm using top-down
* merge sort algorithm
* @array: sorting array
* @size: length array
*/
void merge_sort(int *array, size_t size)
{
	int *B;
	size_t i;

	B = malloc(sizeof(int) * size);
	if (B == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		B[i] = array[i];
	}
	top_down_split(B, 0, 10, array);
	free(B);
}
