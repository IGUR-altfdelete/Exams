/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:37:10 by igur              #+#    #+#             */
/*   Updated: 2025/06/07 18:41:43 by igur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	sign;
	int result;
	int	val;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			val = str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			val = str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			val = str[i] - 'A' + 10;
		else 
			break;
		if (val >= str_base)
			break;
		result = result * str_base + val;
		i++;
	}
	return (result * sign);
}

#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base);

int main(void)
{
	printf("%d\n", ft_atoi_base("1a", 16));     // 26
	printf("%d\n", ft_atoi_base("101", 2));      // 5
	printf("%d\n", ft_atoi_base(" -7F", 16));    // -127
	printf("%d\n", ft_atoi_base("  77", 8));     // 63
	printf("%d\n", ft_atoi_base(" 42", 10));     // 42
}
