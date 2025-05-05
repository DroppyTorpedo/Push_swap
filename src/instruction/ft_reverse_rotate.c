/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnorvene <rnorvene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:04:10 by marvin            #+#    #+#             */
/*   Updated: 2025/05/02 15:08:09 by rnorvene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*second_last;

	if (*stack && (*stack)->next)
	{
		second_last = *stack;
		while (second_last->next && second_last->next->next)
			second_last = second_last->next;
		tmp = second_last->next;
		second_last->next = NULL;
		tmp->next = *stack;
		*stack = tmp;
	}
}

void	rra(t_stack **stack_a)
{
	if (*stack_a && (*stack_a)->next)
	{
		ft_reverse_rotate(stack_a);
		write(1, "rra\n", 4);
	}
}

void	rrb(t_stack **stack_b)
{
	if (*stack_b && (*stack_b)->next)
	{
		ft_reverse_rotate(stack_b);
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	int	rotated;

	rotated = 0;
	if (*stack_a && (*stack_a)->next)
	{
		ft_reverse_rotate(stack_a);
		rotated = 1;
	}
	if (*stack_b && (*stack_b)->next)
	{
		ft_reverse_rotate(stack_b);
		rotated = 1;
	}
	if (rotated)
		write(1, "rrr\n", 4);
}
