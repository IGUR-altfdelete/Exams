/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 19:06:57 by igur              #+#    #+#             */
/*   Updated: 2025/06/07 19:10:24 by igur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	candidate;

	if (a == 0) || (b == 0)
		return (0);
	candidate = (a > b) ? a : b;
	while (1)
	{
		if (candidate % a == 0 && candidate % b == 0)
			return (candidate);
	}
}
