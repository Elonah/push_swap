/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejacquel <ejacquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:03:15 by ejacquel          #+#    #+#             */
/*   Updated: 2023/04/03 00:43:25 by ejacquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (*str)
	{
		write(1, str, 1);
		str++;
		i++;
	}
	return (i);
}

int	get_format(char c, va_list ap)
{
	int				len;
	long long int	temp;

	len = 0;
	if (c == 'c')
		len += print_c(va_arg(ap, int));
	else if (c == 's')
		len += ft_putstr(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		print_decimal_nb(va_arg(ap, long int), &len);
	else if (c == 'u')
		print_unsigned_decimal(va_arg(ap, unsigned int), &len);
	else if (c == '%')
		len += write(1, "%%", 1);
	else if (c == 'p')
	{
		temp = va_arg(ap, unsigned long int);
		if (!temp)
			return (len = ft_putstr("(nil)"));
		len += write(1, "0x", 2);
		print_pointeur(temp, &len);
	}
	else if (c == 'x' || c == 'X')
		print_hexadecimal(va_arg(ap, unsigned int), &len, c == 'X');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		i;
	va_list	ap;

	i = -1;
	len = 0;
	va_start(ap, format);
	while (format && format[++i])
	{
		if (format[i] == '%')
			len += get_format(format[++i], ap);
		else
			len += write(1, &format[i], 1);
	}
	va_end(ap);
	return (len);
}

//int	main(void)
//{
//	int a, b;
//	a = 0;
//	b = 0;
//	a += ft_printf(" %p %p \n", LONG_MIN, LONG_MAX);
//	a += ft_printf(" %p %p \n", INT_MIN, INT_MAX);
//	a += ft_printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
//	b += printf(" %r avion  %g
//bateau %0  %y %b %m %0 %p \n", LONG_MIN, LONG_MAX);
//	b += printf(" %p %p \n", INT_MIN, INT_MAX);
//	b += printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
//	printf("ft=%i vr=%i\n", a, b);
//}
