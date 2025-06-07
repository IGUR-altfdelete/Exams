/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:55:41 by igur              #+#    #+#             */
/*   Updated: 2025/06/07 19:01:16 by igur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	len;
	int	*range;
	int	i;

	i = 0;
	if (start <= end)
		len = end - start + 1;
	else
		len = start - end + 1;
	range = malloc(len * sizeof(int));
	if (!range)
		return (NULL);
	while (i < len)
	{
		range[i] = end;
		if (end > start)
			end--;
		else
			end++;
		i++;
	}
	return (range);
}
/*
#include <stdio.h>

int main(void)
{
	int *arr;
	int len, i;

	// Example 1: (1, 3) → 3 2 1
	arr = ft_rrange(1, 3);
	len = 3;
	printf("ft_rrange(1, 3):      ");
	for (i = 0; i < len; i++)
		printf("%d%c", arr[i], i < len - 1 ? ' ' : '\n');
	free(arr);

	// Example 2: (-1, 2) → 2 1 0 -1
	arr = ft_rrange(-1, 2);
	len = 4;
	printf("ft_rrange(-1, 2):     ");
	for (i = 0; i < len; i++)
		printf("%d%c", arr[i], i < len - 1 ? ' ' : '\n');
	free(arr);

	// Example 3: (0, 0) → 0
	arr = ft_rrange(0, 0);
	len = 1;
	printf("ft_rrange(0, 0):      ");
	for (i = 0; i < len; i++)
		printf("%d\n", arr[i]);
	free(arr);

	// Example 4: (0, -3) → -3 -2 -1 0
	arr = ft_rrange(0, -3);
	len = 4;
	printf("ft_rrange(0, -3):     ");
	for (i = 0; i < len; i++)
		printf("%d%c", arr[i], i < len - 1 ? ' ' : '\n');
	free(arr);

	return 0;
}
*/
