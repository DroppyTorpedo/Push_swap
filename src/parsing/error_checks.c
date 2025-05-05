/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnorvene <rnorvene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:16:33 by marvin            #+#    #+#             */
/*   Updated: 2025/05/02 15:11:04 by rnorvene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

int	ft_isdigit_str(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!*str || str[0] == '\0')
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	is_valid_number(const char *str)
{
	long	num;

	if (!ft_isdigit_str(str))
		return (0);
	num = ft_atol(str);
	if (num < -2147483648 || num > 2147483647)
		return (0);
	return (1);
}

int	has_duplicate(t_stack *a)
{
	t_stack	*p;
	t_stack	*q;

	p = a;
	while (p)
	{
		q = p->next;
		while (q)
		{
			if (q->value == p->value)
				return (1);
			q = q->next;
		}
		p = p->next;
	}
	return (0);
}
