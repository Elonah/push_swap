/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejacquel <ejacquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 01:12:31 by ejacquel          #+#    #+#             */
/*   Updated: 2022/11/09 09:22:27 by ejacquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// DESCRIPTION : The memcmp() function compares byte string s1 against byte
// string s2.  Both strings are assumed to be n bytes long.

// RETURN VALUES : The memcmp() function returns zero if the two strings are
// identical, otherwise returns the difference between the first two differing
// bytes (treated as unsigned char values, so that ‘\200’ is greater than ‘\0’,
// for example). Zero-length strings are always identical. This behavior is
// not required by C and portable code should only depend on the sign of the
// returned value.

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
	{
		if (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
			i++;
		else
			return ((((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]));
	}
	return (0);
}
