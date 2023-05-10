/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejacquel <ejacquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 04:44:47 by ejacquel          #+#    #+#             */
/*   Updated: 2023/04/01 02:59:49 by ejacquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_c(int c)
{
	return (write(1, &c, 1));
}

int	print_unsigned_decimal(unsigned int n, int *len)
{
	if (n > 9)
		print_unsigned_decimal(n / 10, len);
	print_c((n % 10) + '0');
	return ((*len) += 1);
}

int	print_decimal_nb(int n, int *len)
{
	long int	num;

	num = n;
	if (num == -2147483648)
		return (*len = 11, ft_putstr("-2147483648"));
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
		(*len)++;
	}
	if (num > 9)
		print_decimal_nb(num / 10, len);
	print_c((num % 10) + '0');
	return ((*len) += 1);
}

int	print_pointeur(unsigned long int var, int *len)
{
	if (var > 15)
		print_pointeur(var / 16, len);
	print_c(HEX[(var % 16)]);
	return (*len += 1);
}

//int	print_hexadecimal(unsigned int n, int *len, char c)
//{
//	if (n > 15)
//		print_hexadecimal(n / 16, len, c);
//	if (c == 'x')
//		print_c(HEX[(n % 16)]);
//	else
//		print_c("0123456789ABCDEF"[(n % 16)]);
//	return (*len++);
//}

int	print_hexadecimal(unsigned int n, int *len, int c)
{
	if (n > 15)
		print_hexadecimal(n / 16, len, c);
	print_c(HEX[n % 16 + 6 * (n % 16 >= 10) * (c == 'X')]);
	return (*len += 1);
}
