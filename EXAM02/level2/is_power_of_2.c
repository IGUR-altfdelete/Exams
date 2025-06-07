/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:23:13 by igur              #+#    #+#             */
/*   Updated: 2025/06/07 16:29:49 by igur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_power_of_2(unsigned int n)
{
	return (n != 0 && (n & (n - 1)) == 0);
}

#include <stdio.h>

int main(void)
{
	unsigned int i;
	unsigned int pow2 = 1;

	printf("✅ Testing all powers of 2 in unsigned int:\n");

	// Loop through 32 powers of 2
	for (i = 0; i < 32; i++)
	{
		if (!is_power_of_2(pow2))
			printf("❌ Failed: %u should be power of 2\n", pow2);
		else
			printf("✅ Passed: %u is power of 2\n", pow2);

		pow2 <<= 1; // Multiply by 2 using left shift
	}

	printf("\n🚫 Testing non-powers of 2:\n");

	// Now check a few non-powers for contrast
	unsigned int test_vals[] = {0, 3, 5, 6, 7, 9, 10, 15, 20, 100, 123456789};
	int size = sizeof(test_vals) / sizeof(test_vals[0]);

	for (i = 0; i < size; i++)
	{
		if (is_power_of_2(test_vals[i]))
			printf("❌ Failed: %u is NOT a power of 2\n", test_vals[i]);
		else
			printf("✅ Passed: %u is not a power of 2\n", test_vals[i]);
	}

	return 0;
}

