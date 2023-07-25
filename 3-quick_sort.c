#include "sort.h"
/**
 * int_swap - two integers in array swap.
 *
 * @x: first integer.
 * @y: second integer.
*/
void int_swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * lomuto_partition - Order x subset of an array of integers.
 *
 * @array: an array.
 * @size: array's size.
 * @lt: starting index.
 * @rgt: ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int lt, int rgt)
{
	int *revolve, above, below;

	revolve = array + rgt;
	for (above = below = lt; below < rgt; below++)
	{
		if (array[below] < *revolve)
		{
			if (above < below)
			{
				int_swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *revolve)
	{
		int_swap(array + above, revolve);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Implement the quicksort.
 *
 * @array: An array.
 * @size: array's size.
 * @lt: starting index.
 * @rgt:ending index.
 */
void lomuto_sort(int *array, size_t size, int lt, int rgt)
{
	int partition;

	if (rgt - lt > 0)
	{
		partition = lomuto_partition(array, size, lt, rgt);
		lomuto_sort(array, size, lt, partition - 1);
		lomuto_sort(array, size, partition + 1, rgt);
	}
}

/**
 * quick_sort - Sort an array.
 *
 * @array: An array.
 * @size: array's size.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	lomuto_sort(array, size, 0, size - 1);
}
