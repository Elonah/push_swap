/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejacquel <ejacquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 02:57:56 by ejacquel          #+#    #+#             */
/*   Updated: 2022/11/14 11:16:16 by ejacquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// DESCRIPTION
//      The malloc(), calloc() functions allocate memory.  The allocated memory
//      is aligned such that it can be used for any data type, including
//      AltiVec- and SSE-related types.
//      The malloc() function allocates size bytes of memory and returns a
//      pointer to the allocated memory.
//      The calloc() function contiguously allocates enough space for count
//      objects that are size bytes of memory each and returns a pointer to the
//      allocated memory.  The allocated memory is filled with bytes of value
//      zero.

// RETURN VALUES
//      If successful, calloc(), malloc() functions return a pointer to
//      allocated memory.  If there is an error, they return a NULL pointer and
//      set errno to ENOMEM.

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size != 0 && count > __SIZE_MAX__ / size)
		return (NULL);
	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
