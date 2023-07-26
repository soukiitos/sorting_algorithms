#include "sort.h"
/**
 * sort_hoare_partition - The partition of quick sort hoare
 * @array: The array
 * @size: The size
 * @left: The left
 * @right: The right
 *
 * Return: 0
 */
int sort_hoare_partition(int *array, size_t size, int left, int right)
{
	int i, up, down, tmp;

	i = array[right];
	for (up = left - 1, down = right + 1; up < down;)
	{
		do {
			up++;
		} while (array[up] < i);
		do {
			down--;
		} while (array[down] > i);
		if (up < down)
		{
			tmp = array[up];
			array[up] = array[down];
			array[down] = tmp;
			print_array(array, size);
		}
	}
	return (up);
}
/**
 * sort_hoare - The sort hoare
 * @array: The array
 * @size: The size
 * @left: The left
 * @right: The right
 *
 * Return: 0
 */
void sort_hoare(int *array, size_t size, int left, int right)
{
	int j;

	if (right - left > 0)
	{
		j = sort_hoare_partition(array, size, left, right);
		sort_hoare(array, size, left, j - 1);
		sort_hoare(array, size, j, right);
	}
}
/**
 * quick_sort_hoare - Sort an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: The array
 * @size: The size
 *
 * Return: 0
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sort_hoare(array, size, 0, size - 1);
}
