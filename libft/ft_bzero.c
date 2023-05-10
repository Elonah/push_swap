/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejacquel <ejacquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:07:27 by ejacquel          #+#    #+#             */
/*   Updated: 2022/11/09 08:58:46 by ejacquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// DESCRIPTION : The bzero() function writes n zeroed bytes to the string s.  If
// n is zero, bzero() does nothing.

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
