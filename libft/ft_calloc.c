/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnorvene <rnorvene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:37:55 by rnorvene          #+#    #+#             */
/*   Updated: 2024/10/28 14:23:55 by rnorvene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	unsigned char	*ptr;
	size_t			total_size;
	size_t			i;

	if (num && size > SIZE_MAX / num)
	{
		return (NULL);
	}
	total_size = num * size;
	ptr = malloc(total_size);
	if (!ptr)
	{
		return (NULL);
	}
	i = 0;
	while (i < total_size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
