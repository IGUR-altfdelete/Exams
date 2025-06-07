/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:11:13 by igur              #+#    #+#             */
/*   Updated: 2025/06/07 20:16:21 by igur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *s)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	return (res);
}

void	ft_putnbr(int nbr)
{
	char	c;
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
}

int	main(int ac, char **av)
{
	int	i;
	int	n;

	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 1;
	n = ft_atoi(av[1]);
	while (i <= 9)
	{
		ft_putnbr(i);
		ft_putstr(" x ");
		ft_putnbr(n);
		ft_putstr(" = ");
		ft_putnbr(i * n);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}	
