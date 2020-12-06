#include "search_algos.h"

/**
* search - search function
* @array: array
* @min: min value array
* @max: max value array
* @value: value to look for
* Return: the index of the value searched
*/
int search(int *array, int min, int max, int value)
{
	int mid = (min + max)  / 2, i, flag = 0;
	int new_min = min, new_max = max, index = mid;

	if (min > max)
		return (-1);
	if (array[mid] < value)
		new_min = mid + 1;
	else if (array[mid] > value)
		new_max = mid - 1;
	else
		flag = 1;
	printf("Searching in array: ");
	for (i = min; i <= max; i++)
	{
		if (flag == 1 && array[index - 1] == value)
			index = index - 1;
		if (i == max)
			printf("%d\n", array[i]);
		else
			printf("%d, ", array[i]);
	}
	if (index != mid)
		flag = 0, new_max = mid;
	if (flag == 0)
		return (search(array, new_min, new_max, value));
	else
		return (index);
}
/**
* advanced_binary - binary search
* @array: pointer of array to search in
* @size: numbers of elements in array
* @value: value to search for
* Return: the index of the value searched
*/
int advanced_binary(int *array, size_t size, int value)
{
	int min = 0, max = (int)size - 1;

	if (array == NULL || size <= 0)
		return (-1);
	return (search(array, min, max, value));
}
