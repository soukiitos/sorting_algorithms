#include "sort.h"
/**
 * counting_sort - Sort an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: The array
 * @size: The size
 *
 * Return: 0
 */
void counting_sort(int *array, size_t size)
{
	size_t i, max = 0;
	int *count, *sort;

	if (array == NULL || size < 2)
		return;
	sort = malloc(sizeof(int) * size);
	if (sort == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		if ((size_t)array[i] > max)
			max = (size_t)array[i];
	}
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sort);
		return;
	}
	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i]] += 1;
	for (i = 1; i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);
	for (i = 0; i < size; i++)
	{
		sort[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}
	for (i = 0; i < size; i++)
		array[i] = sort[i];
	free(sort);
	free(count);
}
