/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejacquel <ejacquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:04:54 by ejacquel          #+#    #+#             */
/*   Updated: 2022/11/15 12:34:30 by ejacquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*tmp;
	char	*lastchar;
	size_t	lenneedle;

	tmp = (char *)haystack;
	lastchar = (char *)haystack + (unsigned)len - 1;
	lenneedle = ft_strlen(needle);
	if (needle[0] == '\0')
		return (tmp);
	if (len > 0)
	{
		tmp = ft_strchr(tmp, *needle);
		while (tmp && tmp + lenneedle - 1 <= lastchar)
		{
			if (!ft_strncmp(tmp, needle, lenneedle))
				return (tmp);
			tmp++;
			tmp = ft_strchr(tmp, *needle);
		}
	}
	return (NULL);
}
