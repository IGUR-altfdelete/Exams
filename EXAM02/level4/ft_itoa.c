/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:51:26 by igur              #+#    #+#             */
/*   Updated: 2025/06/07 20:56:12 by igur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_count_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	int		len;
	long	num;
	char	*str;

	len = ft_count_len(nbr);
	num = nbr;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	if (num == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	while (num > 0)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
/*
#include <stdio.h>

int main(void)
{
	int tests[] = {0, 42, -42, 123456, -123456, -2147483648};
	for (int i = 0; i < 6; i++)
	{
		char *s = ft_itoa(tests[i]);
		printf("ft_itoa(%d) = %s\n", tests[i], s);
		free(s);
	}
	return 0;
}
*/
