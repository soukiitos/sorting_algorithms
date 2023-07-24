#include "sort.h"
/**
 * shell_sort - Sort an array of integers in ascending order
 * using the Shell sort algorithm,
 * using the Knuth sequence
 * @array: The array
 * @size: The size
 *
 * Return: 0
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, tmp, l;

	if (array == NULL || size < 2)
		return;
	for (tmp = 1; tmp < (size / 3);)
		tmp = tmp * 3 + 1;
	for (; tmp >= 1; tmp /= 3)
	{
		for (i = tmp; i < size; i++)
		{
			j = i;
			while (j >= tmp && array[j - tmp] > array[j])
			{
				l = array[j];
				array[j] = array[j - tmp];
				array[j - tmp] = l;
				j -= tmp;
			}
		}
		print_array(array, size);
	}
}
