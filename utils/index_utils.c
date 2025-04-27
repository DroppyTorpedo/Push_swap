/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: <votre_nom> <votre_mail@etu>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:47:59 by rnorvene          #+#    #+#             */
/*   Updated: 2025/04/26 12:00:00 by <votre_nom>      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void quick_sort(int *array, int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);
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
	t_stack	*tmp;
	int		size;
	int		i;

	if (!stack)
		return ;
	size = stack_size(stack);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return ;
	tmp = stack;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
	quick_sort(arr, 0, size - 1);
	tmp = stack;
	while (tmp)
	{
		tmp->index = binary_search(arr, size, tmp->value);
		tmp = tmp->next;
	}
	free(arr);
}

