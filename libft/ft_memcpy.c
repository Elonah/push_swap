/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejacquel <ejacquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:39:11 by ejacquel          #+#    #+#             */
/*   Updated: 2022/11/17 23:39:37 by ejacquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// DESCRIPTION : La fonction memcpy() copie n octets depuis la zone mémoire
// src vers la zone mémoire dst. Si dest et src se chevauchent, le comportement
// est indéfini.
// Dans le cas où dest et src peuvent se chevaucher, utiliser plutôt memmove(3).

// VALEUR RENVOYEE : La fonction memcpy() renvoie la VALEUR ORIGINALE de dest.

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*str;

	if (dst == NULL && src == NULL)
		return (NULL);
	str = (char *)dst;
	i = 0;
	while (i < n)
	{
		*str++ = *(char *)src++;
		i++;
	}
	return (dst);
}
