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
 * bubble_sort - sort the integer array.
 *
 * @array: An array.
 * @size: size of array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t m, leng = size;
	bool fizzies;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (fizzies = false; fizzies == false; leng--)
	{
		fizzies = true;
		for (m = 0; m < leng - 1; m++)
		{
			if (array[m] > array[m + 1])
			{
				int_swap(array + m, array + m + 1);
				print_array(array, size);
				fizzies = false;
			}
		}
	}
}
