/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:31:59 by marvin            #+#    #+#             */
/*   Updated: 2025/04/08 15:31:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
t_stack *stack_new(int value)
{
    t_stack *new;

    new = malloc(sizeof(t_stack));
    if (!new)
        return (NULL);
    new->value = value;
    new->index = 0;
    new->next = NULL;
    return (new);
}

void stack_add_back(t_stack **stack, t_stack *new_node)
{
    t_stack *last;

    if (!stack || !new_node)
        return;
    if (!*stack)
        *stack = new_node;
    else
    {
        last = *stack;
        while (last->next)
            last = last->next;
        last->next = new_node;
    }
}

void free_stack(t_stack **stack)
{
    t_stack *tmp;

    if (!stack)
        return;
    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
}

int stack_size(t_stack *stack)
{
    int size = 0;

    while (stack)
    {
        size++;
        stack = stack->next;
    }
    return (size);
}

int stack_contains(t_stack *stack, int value)
{
    while (stack)
    {
        if (stack->value == value)
            return (1);
        stack = stack->next;
    }
    return (0);
}