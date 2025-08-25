/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:02:16 by igur              #+#    #+#             */
/*   Updated: 2025/06/07 17:06:19 by igur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	appeared_before(char *str, char c, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	union_print(char *s1, char *s2)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	while (s1[i])
	{
		if (!appeared_before(s1, s1[i], i))
			write(1, &s1[i], 1);
		i++;
	}
	j = 0;
	while (s2[j])
	{
		found = 0;
		i = 0;
		while (s1[i])
		{
			if (s2[j] == s1[i])
			{
				found = 1;
				break ;
			}
			i++;
		}
		if (!found && !appeared_before(s2, s2[j], j))
			write(1, &s2[j], 1);
		j++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		union_print(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
