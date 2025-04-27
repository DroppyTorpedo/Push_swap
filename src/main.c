/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:00:39 by marvin            #+#    #+#             */
/*   Updated: 2025/04/08 18:00:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void push_swap(t_stack **a, t_stack **b)
{
    int size;

    if (is_sorted(*a))
    {
        free_stack(a);
        return ;
    }
    size = stack_size(*a);
    if (size == 2)
        sa(a);
    else if (size == 3)
        sort_three(a);
    else if (size == 4)
        turk_sort(a, b);
    else if (size == 5)
        sort_five(a, b);
    else
        turk_sort(a, b);
}

int	main(int argc, char **argv)
{
    t_stack	*a = NULL;
    t_stack	*b = NULL;

    if (argc < 2)
        return (0);
    if (argc == 2 && (argv[1][0] == '\0' || argv[1][0] == ' '))
        return (0);

    a = parse_args(argc, argv);
    if (!a)
        return (error_and_free(&a, &b, 1));
    
    if (is_sorted(a))
    {
        free_stack(&a);
        return (0);
    }
    assign_indexes(a);
    push_swap(&a, &b);

    free_stack(&a);
    return (0);
}