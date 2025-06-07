/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:37:34 by igur              #+#    #+#             */
/*   Updated: 2025/06/07 16:48:02 by igur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int		i;
	char	c;

	i = 8;
	while (i--)
	{
		c = ((octet >> i) & 1) + '0';
		write(1, &c, 1);
	}
}

/*
int main(void)
{
	write(1, "Testing 5: ", 11);
	print_bits(5);      // 00000101
	write(1, "\n", 1);

	write(1, "Testing 255: ", 13);
	print_bits(255);    // 11111111
	write(1, "\n", 1);

	write(1, "Testing 0: ", 11);
	print_bits(0);      // 00000000
	write(1, "\n", 1);

	return (0);
}

*/
