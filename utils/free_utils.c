/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnorvene <rnorvene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 01:14:00 by rnorvene          #+#    #+#             */
/*   Updated: 2025/04/23 01:14:00 by rnorvene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_split(char **arr)
{
    char **tmp;

    if (!arr)
        return;
    tmp = arr;
    while (*tmp)
        free(*tmp++);
    free(arr);
}