#include "sort.h"
/**
 * heap_max - The max heap
 * @array: The array
 * @size: The size
 * @basis: The basic of the heap_sort
 * @r: The root
 *
 * Return: 0
 */
void heap_max(int *array, size_t size, size_t basis, size_t r)
{
	int tmp;
	size_t l, m, i;

	l = 2 * r + 1;
	m = 2 * r + 2;
	i = r;
	if (l < basis && array[l] > array[i])
		i = l;
	if (m < basis && array[m] > array[i])
		i = m;
	if (i != r)
	{
		tmp = array[r];
		array[r] = array[i];
		array[i] = tmp;
		print_array(array, size);
		heap_max(array, size, basis, i);
	}
}
/**
 * heap_sort - Sort an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: The array
 * @size: The size
 *
 * Return: 0
 */
void heap_sort(int *array, size_t size)
{
	int j, tmp;

	if (array == NULL || size < 2)
		return;
	for (j = (size / 2) - 1; j >= 0; j--)
		heap_max(array, size, size, j);
	for (j = size - 1; j > 0; j--)
	{
		tmp = array[0];
		array[0] = array[j];
		array[j] = tmp;
		print_array(array, size);
		heap_max(array, size, j, 0);
	}
}
