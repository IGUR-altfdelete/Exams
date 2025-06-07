/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotstring.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 21:26:05 by igur              #+#    #+#             */
/*   Updated: 2025/06/07 21:38:57 by igur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void	write_word(char *str, int start, int end)
{
	while (start < end)
		write(1, &str[start++], 1);
}

int	main(int ac, char **av)
{
	int i;
	int start;
	int end;
	int first;
	int word_start;

	i = 0;
	start = 0;
	end = 0;
	first = 1;

	if (ac < 2 || !av[1][0])
	{
		write(1, "\n", 1);
		return (0);
	}

	while (ft_is_space(av[1][i]))
		i++;
	start = i;
	while (av[1][i] && !ft_is_space(av[1][i]))
		i++;
	end = i;

	while (av[1][i])
	{
		while (ft_is_space(av[1][i]))
			i++;
		if (av[1][i] && !ft_is_space(av[1][i]))
		{
			if (!first)
				write(1, " ", 1);
			first = 0;
			word_start = i;
			while (av[1][i] && !ft_is_space(av[1][i]))
				i++;
			write_word(av[1], word_start, i);
		}
	}

	if (!first)
		write(1, " ", 1);
	write_word(av[1], start, end);
	write(1, "\n", 1);
	return (0);
}

