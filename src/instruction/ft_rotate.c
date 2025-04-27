/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:55:07 by marvin            #+#    #+#             */
/*   Updated: 2025/04/01 15:55:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ft_rotate(t_stack **stack)
{
    t_stack	*tmp;
    t_stack	*last;

    if (*stack && (*stack)->next)
    {
        tmp = *stack;
        *stack = (*stack)->next;
        tmp->next = NULL;
        last = *stack;
        while (last->next)
            last = last->next;
        last->next = tmp;
    }
}

void	ra(t_stack **stack_a)
{
    if (*stack_a && (*stack_a)->next)
    {
        ft_rotate(stack_a);
        write(1, "ra\n", 3);
    }
}

void	rb(t_stack **stack_b)
{
    if (*stack_b && (*stack_b)->next)
    {
        ft_rotate(stack_b);
        write(1, "rb\n", 3);
    }
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
    int	rotated;

    rotated = 0;
    if (*stack_a && (*stack_a)->next)
    {
        ft_rotate(stack_a);
        rotated = 1;
    }
    if (*stack_b && (*stack_b)->next)
    {
        ft_rotate(stack_b);
        rotated = 1;
    }
    if (rotated)
        write(1, "rr\n", 3);
}