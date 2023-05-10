/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejacquel <ejacquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 00:24:16 by ejacquel          #+#    #+#             */
/*   Updated: 2022/11/09 09:21:27 by ejacquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// DESCRIPTION : La fonction strrchr() est identique à la fonction strchr() mise
// à part qu'elle localise la dernière occurence de c.

// VALEUR RENVOYEE : Elle retourne un pointeur sur le caractère localisé ou NULL
// si le caractère n'apparait pas dans la chaîne.

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while (i != 0 && s[i] != (char)c)
		i--;
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (0);
}
