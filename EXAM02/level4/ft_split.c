/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:31:43 by igur              #+#    #+#             */
/*   Updated: 2025/06/07 20:50:05 by igur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	count_words(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			i++;
	}
	return (count);
}

void	copy_word(char *dest, char *src, int start, int end)
{
	int	i;

	i = 0;
	while (start < end)
		dest[i++] = src[start++];
	dest[i] = '\0';
}

int	find_next_word(char *str, int *start, int *end)
{
	int	i;

	i = *end;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	*start = i;
	while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		i++;
	*end = i;
	return (*start < *end);
}

int	fill_words(char **tab, char *str)
{
	int	start;
	int end;
	int	w;

	start = 0;
	end = 0;
	w = 0;
	while (find_next_word(str, &start, &end))
	{
		tab[w] = malloc(end - start + 1);
		if (!tab[w])
		{
			while (w > 0)
				free(tab[--w]);
			return (0);
		}
		copy_word(tab[w], str, start, end);
		w++;
	}
	tab[w] = NULL;
	return (1);
}

char	**ft_split(char *str)
{
	int		word_count;
	char	**tab;

	if (!str)
		return (NULL);
	word_count = count_words(str);
	tab = malloc((word_count + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	if (!fill_words(tab, str))
	{
		free(tab);
		return (NULL);
	}
	return (tab);
}
/*
#include <stdio.h>

int main(void)
{
    char *input = "  Hello\t42  School\nIntra";
    char **words = ft_split(input);

    if (!words)
        return (1);

    for (int i = 0; words[i]; i++)
    {
        printf("Word[%d]: %s\n", i, words[i]);
        free(words[i]);
    }
    free(words);
    return (0);
}
*/
