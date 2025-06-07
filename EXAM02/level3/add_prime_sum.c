/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:13:56 by igur              #+#    #+#             */
/*   Updated: 2025/06/07 18:14:04 by igur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

int	ft_atoi(char *str)
{
	int i = 0;
	int res = 0;

	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	return (res);
}

int	is_prime(int n)
{
	int i = 2;

	if (n < 2)
		return (0);
	while (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int n, sum = 0;

	if (ac != 2 || (n = ft_atoi(av[1])) <= 0)
	{
		write(1, "0\n", 2);
		return (0);
	}
	while (n > 1)
	{
		if (is_prime(n))
			sum += n;
		n--;
	}
	ft_putnbr(sum);
	ft_putchar('\n');
	return (0);
}
