#include "sort.h"
/**
 * lomuto_sub - the subset of arrays
 * @array: The array
 * @size: The size
 * @left: The index
 * @right: The index
 *
 * Return: 0
 */
int lomuto_sub(int *array, size_t size, int left, int right)
{
	int up = left, down, n, tmp;

	n = array[right];
	for (down = left; down < right; down++)
	{
		if (array[down] < n)
		{
			if (up != down)
			{
				tmp = array[down];
				array[down] = array[up];
				array[up] = tmp;
				print_array(array, size);
			}
			up++;
		}
	}
	if (array[up] > n)
	{
		tmp = array[up];
		array[up] = array[right];
		array[right] = tmp;
		print_array(array, size);
	}
	return (up);
}

/**
 * lomuto_sort - Implement the quick sort algo
 * @array: The array
 * @size: The size
 * @left: The index
 * @right: The index
 *
 * Return: 0
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int m;

	if (right - left > 0)
	{
		m = lomuto_sub(array, size, left, right);
		lomuto_sort(array, size, left, m - 1);
		lomuto_sort(array, size, m + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: The array
 * @size: The size
 *
 * Return: 0
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}
