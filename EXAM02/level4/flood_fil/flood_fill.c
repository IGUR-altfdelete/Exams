/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:18:49 by igur              #+#    #+#             */
/*   Updated: 2025/06/07 20:26:00 by igur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

void	fill(char **tab, t_point size, char target, int y, int x)
{
	if (x < 0 || y < 0 || x >= size.x || y >= size.y)
		return ;
	if (tab[y][x] != target || tab[y][x] == 'F')
		return ;
	tab[y][x] = 'F';
	fill(tab, size, target, y - 1, x);
	fill(tab, size, target, y + 1, x);
	fill(tab, size, target, y, x - 1);
	fill(tab, size, target, y, x + 1);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	target = tab[begin.y][begin.x];
	
	if (target == 'F')
		return ;
	fill(tab, size, target, begin.y, begin.x);
}
