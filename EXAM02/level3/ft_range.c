/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:46:16 by igur              #+#    #+#             */
/*   Updated: 2025/06/07 18:54:56 by igur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	len;
	int	*range;
	int	i;

	i = 0;
	if (start <= end)
		len = end - start + 1;
	else
		len = start - end + 1;
	range = malloc(len * sizeof(int));
	if (!range)
		return (NULL);
	if (start <= end)
	{
		while (i < len)
		{
			range[i] = start + i;
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			range[i] = start - i;
			i++;
		}
	}
	return (range);
}
