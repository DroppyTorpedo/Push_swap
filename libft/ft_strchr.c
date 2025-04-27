/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnorvene <rnorvene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:35:16 by rnorvene          #+#    #+#             */
/*   Updated: 2024/10/28 14:25:20 by rnorvene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if ((unsigned char)src[i] == (unsigned char)c)
		{
			return ((char *)&src[i]);
		}
		i++;
	}
	if (c == '\0')
		return ((char *)&src[i]);
	return (0);
}
