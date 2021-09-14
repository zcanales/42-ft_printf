/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:27:38 by zcanales          #+#    #+#             */
/*   Updated: 2021/09/13 11:08:38 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

static int	sort_type(va_list ap, char c)
{
	int	len;

	len = 1;
	if (c == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	if (c == 's')
		len = ft_len_putstr_fd(va_arg(ap, char *), 1);
	if (c == 'p')
	{
		write(1, "0x", 2);
		len = ft_len_put_nbase_fd(va_arg(ap, uintptr_t), "0123456789abcdef");
		len += 2;
	}
	if (c == 'd' || c == 'i')
		len = ft_len_putnbr_fd(va_arg(ap, int), 1);
	if (c == 'u')
		len = ft_len_put_nbase_fd(va_arg(ap, unsigned int), "0123456789");
	if (c == 'x')
		len = ft_len_put_nbase_fd(va_arg(ap, unsigned int), "0123456789abcdef");
	if (c == 'X')
		len = ft_len_put_nbase_fd(va_arg(ap, unsigned int), "0123456789ABCDEF");
	if (c == '%')
		write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	ap;

	i = -1;
	len = 0;
	va_start(ap, str);
	while (str[++i])
	{
		if (str[i] == '%')
			len += sort_type(ap, str[++i]);
		else
			len += write(1, &str[i], 1);
	}	
	va_end(ap);
	return (len);
}
