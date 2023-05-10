/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejacquel <ejacquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 02:15:58 by ejacquel          #+#    #+#             */
/*   Updated: 2023/04/26 02:17:11 by ejacquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_strlen2(char const *src, char c)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != c)
		i++;
	return (i);
}

static int	nb_mots(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (count);
}

static char	*ft_strdup2(char const *src, char c)
{
	char	*dest;
	int		i;

	if (!src)
		return (NULL);
	dest = malloc((ft_strlen2(src, c) * sizeof(char)) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_free_split(char **tab, int j)
{
	while (j >= 0)
	{
		free(tab[j]);
		j--;
	}
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	tab = malloc((nb_mots(s, c) + 1) * sizeof(*tab));
	if (!tab)
		return (tab);
	j = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			tab[j] = ft_strdup2(s + i, c);
			if (!tab[j])
				return (ft_free_split(tab, j), NULL);
			j++;
		}
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	tab[j] = NULL;
	return (tab);
}
