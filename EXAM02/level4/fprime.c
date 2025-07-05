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

int     main(int ac, char **av)
{
        int     i = 2;
        int     num;

        if (ac == 2)
        {
                num = atoi(av[1]);
                if (num == 1)
                {
                        printf("1\n");
                        return (0);
                }
                while (num > 1)
                {
                        if (num % i == 0)
                        {
                                printf("%d", i);
                                num /= i;
                                if (num > 1)
                                        printf("*");
                        }
                        else
                                i++;
                }
        }
        printf("\n");
        return (0);
}
