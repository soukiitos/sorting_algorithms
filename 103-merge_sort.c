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
	size_t i, j, k, front, back;
	int *buff;

	if (array == NULL || size < 2)
		return;
	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;
	for (i = 1; i < size; i *= 2)
	{
		for (front = 0; front < size - i; front += i * 2)
		{
			j = front + i;
			back = front + 2 * i < size ? front + 2 * i : size;
			printf("Merging...\n[left]: ");
			print_array(array + front, j - front);
			printf("[right]: ");
			print_array(array + j, back - j);
			for (k  = front; k < back; k++)
				buff[k] = array[k];
			for (k = front, j = front + i, back = j; k < back && j < front + 2 * i; k++)
				array[k] = (buff[k] < buff[j]) ? buff[k] : buff[j++];
			while (k < back)
				array[k++] = buff[j++];
			printf("[Done]: ");
			print_array(array + front, back - front);
		}
	}
	free(buff);
}
