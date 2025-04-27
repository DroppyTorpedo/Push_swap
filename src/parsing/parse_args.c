/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:15:56 by marvin            #+#    #+#             */
/*   Updated: 2025/04/08 18:15:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_stack	*parse_args(int argc, char **argv)
{
	t_stack	*stack = NULL;
	char	**args;
	int		i = 0;
	int		value;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args || !args[0] || args[0][0] == '\0')
		{
            if (args)
			    free_split(args);
			return (NULL);
		}
	}
	else
		args = &argv[1];

	while (args[i])
	{
		if (!is_valid_number(args[i]))
		{
			free_stack(&stack);
			if (argc == 2)
				free_split(args);
			return (NULL);
		}
		value = ft_atoi(args[i]);
		if (stack_contains(stack, value))
		{
			free_stack(&stack);
			if (argc == 2)
				free_split(args);
			return (NULL);
		}
		stack_add_back(&stack, stack_new(value));
		i++;
	}

	if (argc == 2)
		free_split(args);
	return (stack);
}