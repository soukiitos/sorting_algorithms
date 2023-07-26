#include "sort.h"
#define UP 1
#define DOWN 0
/**
 * bitonic_merge - Merge bitonic sort
 * @array: The array
 * @size: The size
 * @index: The index
 * @s: The size of bitonic sort
 * @dir: The direction
 */
void bitonic_merge(int *array, size_t size, size_t index, size_t s, char dir)
{
	size_t i, j = s / 2;

	if (s > 1)
	{
		for (i = index; i < index + j; i++)
		{
			if (
					(dir == UP && array[i] > array[i + j]) ||
					(dir == DOWN && array[i] < array[i + j])
					)
			{
				array[i] ^= array[i + j];
				array[i + j] ^= array[i];
				array[i] ^= array[i + j];
			}
		}
		bitonic_merge(array, size, index, j, dir);
		bitonic_merge(array, size, index + j, j, dir);
	}
}
/**
 * bitonic_s - A bitonic sequence
 * @array: The array
 * @size: The size
 * @index: The index
 * @s: The size of bitonic sort
 * @dir: The direction
 *
 * Return: 0
 */
void bitonic_s(int *array, size_t size, size_t index, size_t s, char dir)
{
	size_t c = s / 2;
	char *str = (dir == UP) ? "UP" : "DOWN";

	if (s > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", s, size, str);
		print_array(array + index, s);
		bitonic_s(array, size, index, c, UP);
		bitonic_s(array, size, index + c, c, DOWN);
		bitonic_merge(array, size, index, s, dir);
		printf("Result [%lu/%lu] (%s):\n", s, size, str);
		print_array(array + index, s);
	}
}
/**
 * bitonic_sort - Sort an array of integers in ascending order
 * using the Bitonic sort algorithm
 * @array: The array
 * @size: The size
 *
 * Return: 0
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bitonic_s(array, size, 0, size, UP);
}
