/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnorvene <rnorvene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:21:28 by rnorvene          #+#    #+#             */
/*   Updated: 2024/10/28 16:20:07 by rnorvene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_strdup(char *src)
{
	char	*dup;

	dup = malloc(ft_strlen(src) + 1);
	if (dup != NULL)
	{
		return (ft_strcpy(dup, src));
	}
	return (dup);
}
