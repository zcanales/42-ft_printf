/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:31:14 by zcanales          #+#    #+#             */
/*   Updated: 2021/09/13 10:46:35 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "Libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_len_putstr_fd(char *s, int fd);
int	ft_len_put_nbase_fd(uintptr_t nbr, char *base);
int	ft_len_putnbr_fd(long int nbr, int fd);

#endif
