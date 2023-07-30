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
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence.
 *
 * @array: An arra.
 * @size: array's size.
 */
void shell_sort(int *array, size_t size)
{
size_t inter, m, n;

if (array == NULL || size < 2)
	return;

inter = 1;
while (inter < (size / 3))
	inter = inter * 3 + 1;

while (inter >= 1)
{
	m = inter;
	while (m < size)
	{
		n = m;
		while (n >= inter && array[n - inter] > array[n])
		{
			int_swap(array + n, array + (n - inter));
			n -= inter;
		}
		m++;
	}
	print_array(array, size);
	inter /= 3;
}
}
