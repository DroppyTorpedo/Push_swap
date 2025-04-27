/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:20:23 by marvin            #+#    #+#             */
/*   Updated: 2025/04/01 15:20:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ft_swap(t_stack **stack)
{
    t_stack	*first;
    t_stack	*second;

    if (!stack || !*stack || !(*stack)->next)
        return;

    first = *stack;
    second = first->next;

    first->next = second->next;
    second->next = first;
    *stack = second;
}

void	sa(t_stack **stack_a)
{
    if (stack_a && *stack_a && (*stack_a)->next)
    {
        ft_swap(stack_a);
        write(1, "sa\n", 3);
    }
}

void	sb(t_stack **stack_b)
{
    if (stack_b && *stack_b && (*stack_b)->next)
    {
        ft_swap(stack_b);
        write(1, "sb\n", 3);
    }
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
    int	swapped;

    swapped = 0;
    if (stack_a && *stack_a && (*stack_a)->next)
    {
        ft_swap(stack_a);
        swapped = 1;
    }
    if (stack_b && *stack_b && (*stack_b)->next)
    {
        ft_swap(stack_b);
        swapped = 1;
    }
    if (swapped)
        write(1, "ss\n", 3);
}