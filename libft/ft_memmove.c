/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejacquel <ejacquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 05:07:31 by ejacquel          #+#    #+#             */
/*   Updated: 2022/11/09 09:56:15 by ejacquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// DESCRIPTION : La fonction memmove() copie len octets depuis la zone mémoire
// src vers la zone mémoire dest. Les deux zones peuvent se chevaucher : la
// copie est toujours faite de façon "non-destructive".

// VALEUR RENVOYEE : La fonction memmove() renvoie la VALEUR ORIGINALE du
// pointeur dst.

// (En fait, elle fait la même chose que memcpy mais en prenant en compte le
// fait que les deux zones (dest et src) peuvent se chevaucher. Du coup on est
// obligé de considérer deux cas : celui où la dest est un peu avant la source
// et donc pour être sûr de ne pas perdre de données on va devoir “transporter”
// chaque octet dans l’ordre et inversement celui où la dest est un peu après la
// source et donc pour ne rien perdre on va devoir le faire dans l’autre sens
// (un peu comme un revprint niveau mémoire dans l’idée).)

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = (char *)dst;
	s = (const char *)src;
	if (d > s)
	{
		while (len--)
			d[len] = s[len];
	}
	else if (d < s)
		ft_memcpy(dst, src, len);
	return (dst);
}
