/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:04:40 by marvin            #+#    #+#             */
/*   Updated: 2025/04/08 18:04:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
    int	temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int	partition(int *array, int low, int high)
{
    int	pivot;
    int	i;
    int	j;

    pivot = array[high];
    i = low - 1;
    j = low;
    while (j < high)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
        j++;
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void sort_three(t_stack **a)
{
    int first = (*a)->index;
    int second = (*a)->next->index;
    int third = (*a)->next->next->index;

    if (first > second && second < third && first < third)
        sa(a);
    else if (first > second && second > third)
    {
        sa(a);
        rra(a);
    }
    else if (first > second && second < third && first > third)
        ra(a);
    else if (first < second && second > third && first < third)
    {
        sa(a);
        ra(a);
    }
    else if (first < second && second > third && first > third)
        rra(a);
}

void sort_four(t_stack **a, t_stack **b)
{
    int pos = get_index_position(*a, 0);
    if (pos <= 2)
        while (pos-- > 0) ra(a);
    else
        while (pos++ < stack_size(*a)) rra(a);
    pb(a, b);
    sort_three(a);
    pa(a, b);
}

void sort_five(t_stack **a, t_stack **b)
{
    int i;
    int pos;

    /* extraction des indices 0 et 1 */
    for (i = 0; i < 2; i++)
    {
        pos = get_index_position(*a, i);
        if (pos <= stack_size(*a) / 2)
            while (pos-- > 0) ra(a);
        else
            while (pos++ < stack_size(*a)) rra(a);
        pb(a, b);
    }
    /* tri des 3 éléments restants */
    sort_three(a);
    /* on remet les deux plus petits dans le bon ordre */
    /* comme on a poussé d’abord 0 puis 1, B = [1,0] → pas besoin de sb */
    pa(a, b);
    pa(a, b);
}