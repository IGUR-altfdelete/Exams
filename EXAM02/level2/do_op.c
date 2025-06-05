/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:59:36 by igur              #+#    #+#             */
/*   Updated: 2025/06/05 17:06:20 by igur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char *av[])
{
	if (ac == 4)
	{
		switch(av[2][0])
		{
			case '+':
				printf("%d", atoi(av[1]) + atoi(av[3]));
				break;
			case '-':
				printf("%d", atoi(av[1]) - atoi(av[3]));
				break;
			case '*':
				printf("%d", atoi(av[1]) * atoi(av[3]));
				break;
			case '/':
				printf("%d", atoi(av[1]) / atoi(av[3]));
				break;
			case '%':
				printf("%d", atoi(av[1]) % atoi(av[3]));
				break;
			}
		}
	}
	printf("\n");
}
