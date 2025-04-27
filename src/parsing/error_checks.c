/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:16:33 by marvin            #+#    #+#             */
/*   Updated: 2025/04/08 18:16:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
    long	result;
    int		sign;

    result = 0;
    sign = 1;
    while (*str == ' ' || (*str >= 9 && *str <= 13)) // Ignore les espaces blancs
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

int ft_isdigit_str(const char *str)
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
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

int	has_duplicate(t_stack *a)
{
    int		*values;
    int		size;
    int		i;

    size = stack_size(a);
    values = malloc(sizeof(int) * size);
    if (!values)
        return (1); // Retourne une erreur si l'allocation échoue
    i = 0;
    while (a)
    {
        values[i++] = a->value;
        a = a->next;
    }
    binary_search(values, 0, size - 1); // Implémentez un tri rapide
    i = 0;
    while (i < size - 1)
    {
        if (values[i] == values[i + 1])
        {
            free(values);
            return (1); // Doublon trouvé
        }
        i++;
    }
    free(values);
    return (0); // Aucun doublon trouvé
}