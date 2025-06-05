/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:05:55 by igur              #+#    #+#             */
/*   Updated: 2025/06/05 16:17:49 by igur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rotone(char *str)
{
	while (*str)
	{
		if (*str == 'z')
			ft_putchar('a');
		else if (*str == 'Z')
			ft_putchar('A');
		else if ((*str >= 'a' && *str <= 'y') || (*str >= 'A' && *str <= 'Y'))
			ft_putchar(*str + 1);
		else
			ft_putchar(*str);
		str++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rotone(av[1]);
	write(1, "\n", 1);
	return (0);
}
