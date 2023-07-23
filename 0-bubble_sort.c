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
	size_t i = 0, j = 1;
	int a, flag = 0;

	if (!array || size < 2)
	{
		return;
	}
	while (i < size)
	{
		for (; j < size; j++)
		{
			if (array[j] < array[j - 1])
			{
				flag = 1;
				a = array[j];
				array[j] = array[j - 1];
				array[j - 1] = a;
				print_array(array, size);
			}
		}
		i++;
		if (flag == 0)
		{
			break;
		}
		flag = 0;
		size--;
	}
}
