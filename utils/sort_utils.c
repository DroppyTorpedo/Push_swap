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

// Échange deux entiers
void swap_int(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Renvoie l’indice du médian des trois valeurs array[i], array[j], array[k]
int median_of_three(int *array, int i, int j, int k)
{
    int a = array[i], b = array[j], c = array[k];
    if ((a < b) ^ (a < c)) return i;
    else if ((b < a) ^ (b < c)) return j;
    else return k;
}

// QuickSort pivot médian, O(n log n) garanti
void quick_sort_median(int *array, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        int pivot_idx = median_of_three(array, low, mid, high);
        // on place le pivot médian en fin de sous-tableau
        swap_int(&array[pivot_idx], &array[high]);

        // partition classique
        int pi = partition(array, low, high);
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