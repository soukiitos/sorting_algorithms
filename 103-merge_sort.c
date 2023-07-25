#include "sort.h"
/**
 * merge_sort - Sort an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: The array
 * @size: The size
 *
 * Return: 0
 */
void merge_sort(int *array, size_t size)
{
	size_t i, j, k, s;
	int *buff;

	if (array == NULL || size < 2)
		return;
	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;
	if (size > 1)
	{
		s = size / 2;
		merge_sort(array, s);
		merge_sort(array + s, size - s);
		printf("Merging...\n[left]: ");
		print_array(array, s);
		printf("[right]: ");
		print_array(array + s, size - s);
		for (i = 0, j = s, k = 0; k < size; k++)
		{
			if (j == size)
				buff[k] = array[i++];
			else if (i == s)
				buff[k] = array[j++];
			else
				buff[k] = (array[i] < array[j]) ? array[i++] : array[j++];
		}
		for (i = 0; i < size; i++)
			array[i] = buff[i];
		printf("[Done]: ");
		print_array(array, size);
	}
	free(buff);
}
