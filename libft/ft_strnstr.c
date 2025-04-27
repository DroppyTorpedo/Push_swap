/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnorvene <rnorvene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:05:39 by rnorvene          #+#    #+#             */
/*   Updated: 2024/10/28 16:55:53 by rnorvene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	if (*to_find == '\0')
	{
		return ((char *)str);
	}
	i = 0;
	while (str[i] && i < n)
	{
		j = 0;
		while (i + j < n && str[i + j] == to_find[j])
		{
			j++;
			if (to_find[j] == '\0')
			{
				return ((char *)&str[i]);
			}
		}
		i++;
	}
	return (0);
}
