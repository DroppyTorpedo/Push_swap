/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnorvene <rnorvene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 01:06:26 by rnorvene          #+#    #+#             */
/*   Updated: 2025/04/23 01:06:26 by rnorvene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	quick_sort_median(int *array, int low, int high)
{
	int	mid;
	int	pivot_idx;
	int	tmp;
	int	pi;

	if (low < high)
	{
		mid = low + (high - low) / 2;
		if ((array[low] <= array[mid] && array[mid] <= array[high])
		 || (array[high] <= array[mid] && array[mid] <= array[low]))
			pivot_idx = mid;
		else if ((array[mid] <= array[low] && array[low] <= array[high])
		      || (array[high] <= array[low] && array[low] <= array[mid]))
			pivot_idx = low;
		else pivot_idx = high;
		tmp = array[pivot_idx];
		array[pivot_idx] = array[high];
		array[high] = tmp;
		pi = partition(array, low, high);
		quick_sort(array, low, pi - 1);
		quick_sort(array, pi + 1, high);
	}
}

int	*get_sorted_indexes(t_stack *stack, int size)
{
	int		*arr;
	t_stack	*tmp;
	int		i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	tmp = stack;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->index;
		tmp = tmp->next;
	}
	quick_sort_median(arr, 0, size - 1);
	return (arr);
}

int	get_max_index(t_stack *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

int	error_and_free(t_stack **a, t_stack **b, int exit_code)
{
	write(2, "Error\n", 6);
	free_stack(a);
	free_stack(b);
	return (exit_code);
}