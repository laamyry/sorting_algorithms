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
 * selection_sort - Use selection sort to arrange integers in ascending order
 *
 * @array: An array.
 * @size: array's size.
 */
void selection_sort(int *array, size_t size)
{
	int *minim;
	size_t m = 0, n;

	if (array == NULL || size < 2)
	{
		return;
	}
	while (m < size - 1)
	{
		minim = array + m;
		for (n = m + 1; n < size; n++)
			minim = (array[n] < *minim) ? (array + n) : minim;

		if ((array + m) != minim)
		{
			int_swap(array + m, minim);
			print_array(array, size);
		}
		m++;
	}
}
