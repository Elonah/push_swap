/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejacquel <ejacquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 06:02:12 by ejacquel          #+#    #+#             */
/*   Updated: 2022/11/09 09:06:39 by ejacquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// DESCRIPTION : La fonction memchr() examine les n premiers octets de la zone
// mémoire pointée par s à la recherche du caractère c. Le premier octet
// correspondant à c (interprété comme un unsigned char) arrête l'opération.

// VALEUR RENVOYEE : La fonction memchr() renvoit un pointeur sur l'octet
// correspondant, ou NULL si le caractère n'est pas présent dans les n premiers
// octets.

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	lettre;
	size_t			i;

	str = (unsigned char *)s;
	lettre = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == lettre)
			return (str + i);
		i++;
	}
	return (NULL);
}
