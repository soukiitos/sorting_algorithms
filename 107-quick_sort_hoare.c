#include "sort.h"
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
	int i, tmp;
	size_t left = 0, right = size - 1;

	if (array == NULL || size < 2)
		return;
	i = array[size / 2];
	while (left <= right)
	{
		while (array[left] < i)
			left++;
		while (array[right] > i)
			right--;
		if (left <= right)
		{
			if (array[left] != array[right])
			{
				tmp = array[left];
				array[left] = array[right];
				array[right] = tmp;
				print_array(array, size);
			}
			left++;
			right--;
		}
	}
	if (right > 0)
		quick_sort_hoare(array, right + 1);
	if (left < size - 1)
		quick_sort_hoare(array + left, size - left);
}
