/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejacquel <ejacquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 04:53:43 by ejacquel          #+#    #+#             */
/*   Updated: 2022/11/14 09:44:20 by ejacquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static size_t	calcul_taille_grande_chaine(char const *s1, char const *s2)
{
	int	s1_length;
	int	s2_length;

	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	return (s1_length + s2_length);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*grandestr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	grandestr = malloc(calcul_taille_grande_chaine(s1, s2) + 1);
	if (!grandestr)
		return (NULL);
	grandestr[0] = '\0';
	ft_strcat(grandestr, s1);
	ft_strcat(grandestr, s2);
	return (grandestr);
}
