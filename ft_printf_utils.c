/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:21:16 by zcanales          #+#    #+#             */
/*   Updated: 2021/09/13 11:08:40 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>
int	ft_len_putstr_fd(char *s, int fd)
{
	int	len;

	if (!s)
		len = write(fd, "(null)", 6);
	else
		len = write(fd, s, ft_strlen(s));
	return (len);
}

int	ft_len_put_nbase_fd(uintptr_t nbr, char *base)
{
	int			len;
	uintptr_t	base_len;

	base_len = ft_strlen(base);
	len = 0;
	if (nbr >= base_len)
		ft_len_put_nbase_fd(nbr / base_len, base);
	ft_putchar_fd(base[nbr % base_len], 1);
	if (nbr == 0)
		len++;
	while (nbr > 0)
	{
		nbr /= base_len;
		len++;
	}
	return (len);
}

int	ft_len_putnbr_fd(long int nbr, int fd)
{
	int		len;

	len = 0;
	ft_putnbr_fd(nbr, fd);
	if (nbr == 0)
		len++;
	if (nbr < 0)
	{
		nbr *= (-1);
		len++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}
