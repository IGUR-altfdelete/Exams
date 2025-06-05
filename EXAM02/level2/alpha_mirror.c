/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:44:58 by igur              #+#    #+#             */
/*   Updated: 2025/06/05 16:50:50 by igur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	alpha_mirror(char *str)
{
	char	c;

	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
		{
			c = 'Z' - (*str - 'A');
			write(1, &c, 1);
		}
		else if (*str >= 'a' && *str <= 'z')
		{
			c = 'z' - (*str - 'a');
			write(1, &c, 1);
		}
		else
		{
			c = *str;
			write(1 , &c, 1);
		}
		str++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		alpha_mirror(av[1]);
	write(1, "\n", 1);
	return (0);
}
