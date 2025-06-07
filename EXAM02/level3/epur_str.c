/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:16:39 by igur              #+#    #+#             */
/*   Updated: 2025/06/07 18:21:11 by igur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	int	i;
	int	space;

	i = 0;
	space = 0;
	if (ac == 2)
	{
		while (av[1][i] <= 32 && av[1][i])
			i++;
		while (av[1][i])
		{
			if (av[1][i] > 32)
			{
				if (space)
					ft_putchar(' ');
				ft_putchar(av[1][i]);
				space = 0;
			}
			else
				space = 1;
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
