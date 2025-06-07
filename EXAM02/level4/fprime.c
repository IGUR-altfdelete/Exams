/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:28:01 by igur              #+#    #+#             */
/*   Updated: 2025/06/07 20:30:18 by igur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	n;
	int	i;

	i = 2;
	if (ac == 2)
	{
		n = atoi(av[1]);

		if (n == 1)
		{
			printf("1\n");
			return (0);
		}
		while (i <= n)
		{
			if (n % i == 0)
			{
				printf("%d", i);
				n = n / i;
				if (n > 1)
					printf("*");
			}
			else
				i++;
		}
	}
	printf("\n");
	return (0);
}
