#include "sort.h"
/**
 * radix_sort - Sort an array of integers in ascending order
 * using the Radix sort algorithm
 * @array: The array
 * @size: The size
 *
 * Return: 0
 */
void radix_sort(int *array, size_t size)
{
	int *buff, max, s, k;
	int count[10] = {0};
	size_t i, j, l;

	if (array == NULL || size < 2)
		return;
	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;
	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	for (s = 1; max / s > 0; s *= 10)
	{
		for (j = 0; j < size; j++)
			count[(array[j] / s) % 10] += 1;
		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];
		for (k = size - 1; k >= 0; k--)
		{
			buff[count[(array[k] / s) % 10] - 1] = array[k];
			count[(array[k] / s) % 10] -= 1;
		}
		for (l = 0; l < size; l++)
			array[l] = buff[l];
		print_array(array, size);
	}
	free(buff);
}
