/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejacquel <ejacquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 06:32:10 by ejacquel          #+#    #+#             */
/*   Updated: 2023/04/29 06:05:03 by ejacquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, char c)
{
	while (*s != c)
		if (!*s++)
			return (0);
	return (s);
}

char	*ft_strcat(char *dest, char *src)
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

size_t	calcul_taille_grande_chaine(char *big_str, char *buffer)
{
	size_t	big_str_length;
	size_t	buffer_length;

	big_str_length = ft_strlen(big_str);
	buffer_length = ft_strlen(buffer);
	return (big_str_length + buffer_length);
}

char	*ft_strjoin(char *big_str, char *buffer)
{
	char	*str_concatenee;

	if (big_str == NULL || buffer == NULL)
		return (NULL);
	str_concatenee = malloc(calcul_taille_grande_chaine(big_str, buffer) + 1);
	if (!str_concatenee)
	{
		free(big_str);
		free(buffer);
		return (NULL);
	}
	str_concatenee[0] = '\0';
	ft_strcat(str_concatenee, big_str);
	ft_strcat(str_concatenee, buffer);
	free(big_str);
	return (str_concatenee);
}
