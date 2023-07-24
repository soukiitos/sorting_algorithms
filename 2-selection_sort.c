#include "sort.h"
/**
 * selection_sort - Sort an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: The array
 * @size: The size
 *
 * Return: 0
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		size_t min_i = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_i])
			{
				min_i = j;
			}
		}
		if (min_i != i)
		{
			tmp = array[i];
			array[i] = array[min_i];
			array[min_i] = tmp;
			print_array(array, size);
		}
	}
}
