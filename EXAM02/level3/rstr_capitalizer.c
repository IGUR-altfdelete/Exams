/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 19:28:07 by igur              #+#    #+#             */
/*   Updated: 2025/06/07 19:36:04 by igur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_letter(char c)
{
	return ((c >= 'a' && 'c' <= 'z') || (c >= 'A' && c <= 'Z'));
}

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

char	to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

void	rstr_cap(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		if (is_letter(str[i]))
		{
			if (!is_letter(str[i + 1]))
				c = to_upper(str[i]);
			else
				c = to_lower(str[i]);
		}
		else
			c = str[i];
		write(1, &c, 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac > 2)
		write(1, "\n", 1);
	else
	{
		while (i < ac)
		{
			rstr_cap(av[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
