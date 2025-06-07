/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:03:38 by igur              #+#    #+#             */
/*   Updated: 2025/06/07 20:09:09 by igur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_letter(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
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

void	str_cap(char *str)
{
	int		i;
	int		new_word;
	char	c;

	i = 0;
	new_word = 1;
	while (str[i])
	{
		if (is_letter(str[i]))
		{
			if (new_word)
				c = to_upper(str[i]);
			else
				c = to_lower(str[i]);
			new_word = 0;
		}
		else
		{
			c = str[i];
			if (str[i] == ' ' || str[i] == '\t')
				new_word = 1;
		}
		write(1, &c, 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 2)
		write(1, "\n", 1);
	else
	{
		while (i < ac)
		{
			str_cap(av[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
		
	
	
