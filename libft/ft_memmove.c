/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnorvene <rnorvene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:20:43 by rnorvene          #+#    #+#             */
/*   Updated: 2024/10/29 12:58:41 by rnorvene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t s)
{
	size_t	i;

	if (!dst || !src)
	{
		return (NULL);
	}
	if (dst > src)
	{
		i = s;
		while (i > 0)
		{
			i--;
			*(char *)(dst + i) = *(char *)(src + i);
		}
	}
	else
	{
		i = 0;
		while (i < s)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dst);
}
