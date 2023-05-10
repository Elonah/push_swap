/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejacquel <ejacquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:50:38 by ejacquel          #+#    #+#             */
/*   Updated: 2022/11/18 18:44:33 by ejacquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// DESCRIPTION : La fonction memset() remplit les len premiers octets de la zone
// mémoire pointée par b avec l'octet c (converti en unsigned char).

// VALEUR RENVOYEE : La fonction memset() renvoie un pointeur sur la zone
// mémoire b.

//void	*ft_memset(void *b, int c, size_t len)
//{
//	char	*str;

//	str = b;
//	while (len)
//	{
//		*str = (unsigned char)c;
//		str++;
//		len--;
//	}
//	return (b);
//}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	valeur;
	size_t			i;

	i = 0;
	str = (unsigned char *)b;
	valeur = (unsigned char)c;
	while (i < len)
	{
		str[i] = valeur;
		i++;
	}
	return (b);
}
