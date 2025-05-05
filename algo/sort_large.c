/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnorvene <rnorvene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:05:39 by marvin            #+#    #+#             */
/*   Updated: 2025/05/02 14:57:37 by rnorvene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(int size)
{
	int	n;

	if (size <= 100)
		n = size / 5;
	else if (size <= 500)
		n = size / 8;
	else
		n = size / 18;
	if (n < 1)
		n = 1;
	return (n);
}

void	push_chunk_to_b(t_stack **a, t_stack **b, int chunk_start,
		int chunk_end)
{
	int	pushed;
	int	target;
	int	direction;

	pushed = 0;
	target = chunk_end - chunk_start + 1;
	while (pushed < target)
	{
		direction = find_closest_direction(*a, chunk_start, chunk_end);
		if ((*a)->index >= chunk_start && (*a)->index <= chunk_end)
		{
			pb(a, b);
			pushed++;
			if (stack_size(*b) > 1 && (*b)->index < (chunk_start + chunk_end)
				/ 2)
				rb(b);
		}
		else
		{
			if (direction == 1)
				ra(a);
			else
				rra(a);
		}
	}
}

void	push_back_to_a(t_stack **a, t_stack **b)
{
	int	max_index;
	int	pos;
	int	size_b;
	int	rotations;

	while (*b)
	{
		max_index = get_max_index(*b);
		pos = get_index_position(*b, max_index);
		size_b = stack_size(*b);
		if (pos <= size_b / 2)
		{
			while (pos-- > 0)
				rb(b);
		}
		else
		{
			rotations = size_b - pos;
			while (rotations-- > 0)
				rrb(b);
		}
		pa(a, b);
	}
}

void	turk_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	*sorted;
	int	chunk_size;
	int	i;
	int	end;

	size = stack_size(*a);
	if (size <= 3)
		return ;
	sorted = get_sorted_indexes(*a, size);
	if (!sorted)
		return ;
	chunk_size = get_chunk_size(size);
	i = 0;
	while (i < size)
	{
		end = i + chunk_size - 1;
		if (end >= size)
			end = size - 1;
		push_chunk_to_b(a, b, sorted[i], sorted[end]);
		i += chunk_size;
	}
	free(sorted);
	push_back_to_a(a, b);
}
