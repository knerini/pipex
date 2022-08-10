/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:38:33 by knerini           #+#    #+#             */
/*   Updated: 2022/07/18 19:39:03 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(long long int nb, size_t base, const char *str)
{
	char				*str_base;
	unsigned long long	n;

	if (*str == 'X')
		str_base = "0123456789ABCDEF";
	else
		str_base = "0123456789abcdef";
	if (nb < 0 && *str != 'p')
	{
		ft_putchar_fd('-', 1);
		n = -nb;
	}
	else
		n = nb;
	if (n >= base)
	{
		ft_putnbr_base(n / base, base, str);
		ft_putnbr_base(n % base, base, str);
	}
	else
		ft_putchar_fd(str_base[n], 1);
}