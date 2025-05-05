/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnorvene <rnorvene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:47:59 by rnorvene          #+#    #+#             */
/*   Updated: 2025/05/05 18:11:16 by rnorvene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	quick_sort(int *array, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(array, low, high);
		quick_sort(array, low, pi - 1);
		quick_sort(array, pi + 1, high);
	}
}

int	binary_search(int *arr, int size, int value)
{
	int	low;
	int	high;
	int	mid;

	low = 0;
	high = size - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (arr[mid] == value)
			return (mid);
		if (arr[mid] < value)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (low);
}

void	assign_indexes(t_stack *stack)
{
	int		*arr;
	int		i;
	t_stack	*tmp;

	if (stack == NULL)
		return ;
	arr = malloc(stack_size(stack) * sizeof * arr);
	if (arr == NULL)
		return ;
	tmp = stack;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
	quick_sort(arr, 0, stack_size(stack) - 1);
	tmp = stack;
	while (tmp)
	{
		tmp->index = binary_search(arr, stack_size(stack), tmp->value);
		tmp = tmp->next;
	}
	free(arr);
}
