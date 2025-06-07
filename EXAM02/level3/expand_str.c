/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:23:18 by igur              #+#    #+#             */
/*   Updated: 2025/06/07 18:26:56 by igur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	main(int ac, char **av)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	if (ac == 2)
	{
		while (is_space(av[1][i]))
			i++;
		while (av[1][i])
		{
			if (!is_space(av[1][i]))
			{
				if (word)
					write(1, "   ", 3);
				while (av[1][i] && !is_space(av[1][i]))
					ft_putchar(av[1][i++]);
				word = 1;
			}
			while (is_space(av[1][i]))
				i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
