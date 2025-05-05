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

int	validate_and_push(t_stack **a, char *token)
{
	t_stack	*new;

	if (!ft_isdigit_str(token) || !is_valid_number(token))
		return (0);
	new = stack_new((int)ft_atol(token));
	if (!new)
		return (0);
	stack_add_back(a, new);
	return (1);
}

int	process_arg(t_stack **a, char *arg)
{
	char	**tokens;
	int		j;

	tokens = ft_split(arg, ' ');
	if (!tokens)
		return (0);
	j = 0;
	while (tokens[j])
	{
		if (!validate_and_push(a, tokens[j]))
		{
			free_split(tokens);
			return (0);
		}
		j++;
	}
	free_split(tokens);
	return (1);
}

t_stack	*parse_args(int argc, char **argv)
{
	t_stack	*a;
	int		i;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		if (!process_arg(&a, argv[i]))
		{
			free_stack(&a);
			return (NULL);
		}
		i++;
	}
	if (has_duplicate(a))
	{
		free_stack(&a);
		return (NULL);
	}
	assign_indexes(a);
	return (a);
}
