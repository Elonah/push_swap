/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejacquel <ejacquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:08:56 by ejacquel          #+#    #+#             */
/*   Updated: 2022/11/09 08:56:39 by ejacquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}

//#include "libft.h"

// DESCRIPTION : La fonction strchr() localise la première occurrence de c
// (converti en char) dans la chaîne pointée par s. Le caractère nul de fin de
// chaîne est considéré comme faisant parti de la chaîne, par conséquent si c
// est '\0', la fonction localise le '\0'.

// VALEUR RENVOYEE : Elle retourne un pointeur sur le caractère localisé ou
// NULL si le caractère n'apparait pas dans la chaîne.

//char	*ft_strchr(const char *s, int c)
//{
//	int i;

//	i = 0;
//	while (s[i] != '\0')
//	{
//		if (s[i] == c)
//			return ((char *)s + i);
//		++i;
//	}
//	if (c != '\0')
//		return (NULL);
//	return ((char *)s + i);
//}
