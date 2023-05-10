/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejacquel <ejacquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:12:58 by ejacquel          #+#    #+#             */
/*   Updated: 2022/11/14 08:10:05 by ejacquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dlen;
	size_t	slen;

	if ((!dst) && (size == 0))
		return (0);
	i = 0;
	j = 0;
	while (dst[j] && j < size)
		j++;
	dlen = j;
	slen = ft_strlen(src);
	if ((size == 0) || (size <= dlen))
		return (slen + size);
	while ((src[i]) && (i < size - dlen - 1))
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dlen + slen);
}
