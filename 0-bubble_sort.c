#include "sort.h"
/**
 * bubble_sort - Sort an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: The array
 * @size: The size
 *
 * Return: 0
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;

	if (array == NULL || size < 2)
		return;
	while (len > 0)
	{
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				array[i] = array[i] + array[i + 1];
				array[i + 1] = array[i] - array[i + 1];
				array[i] = array[i] - array[i + 1];
				print_array(array, size);
			}
		}
		len--;
	}
}
