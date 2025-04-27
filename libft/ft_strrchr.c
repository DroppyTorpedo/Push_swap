/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnorvene <rnorvene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:43:50 by rnorvene          #+#    #+#             */
/*   Updated: 2024/10/28 14:26:07 by rnorvene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	char	find;
	size_t	i;

	last = (char *)s;
	find = (char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (last[i] == find)
		{
			return (last + i);
		}
		i--;
	}
	if (last[i] == find)
	{
		return (last);
	}
	return (NULL);
}
