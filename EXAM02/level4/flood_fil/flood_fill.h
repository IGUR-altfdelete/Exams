/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:18:05 by igur              #+#    #+#             */
/*   Updated: 2025/06/07 20:20:47 by igur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOD_FILL_H
# define FLOOD_FILL_H

typedef struct	s_point
{
	int	x;
	int	y;
}		t_point;

void	flood_fill(char **tab, t_point size, t_point begin);

#endif
