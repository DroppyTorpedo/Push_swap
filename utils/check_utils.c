/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_error_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnorvene <rnorvene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 01:03:24 by rnorvene          #+#    #+#             */
/*   Updated: 2025/04/23 01:03:24 by rnorvene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_stack *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}

int	stack_has_chunk(t_stack *a, int chunk_start, int chunk_end)
{
	while (a)
	{
		if (a->index >= chunk_start && a->index <= chunk_end)
			return (1);
		a = a->next;
	}
	return (0);
}

int	get_index_position(t_stack *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

int	find_closest_direction(t_stack *a, int chunk_start, int chunk_end)
{
    int	pos;
    int	size;

    pos = 0;
    size = stack_size(a);
    while (a)
    {
        if (a->index >= chunk_start && a->index <= chunk_end)
            break;
        a = a->next;
        pos++;
    }
    return (pos <= size / 2 ? 1 : -1); // 1 pour ra, -1 pour rra
}