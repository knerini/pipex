/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 19:22:17 by knerini           #+#    #+#             */
/*   Updated: 2022/07/18 20:39:49 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_convert_p(va_list args, t_format *s, const char *str)
{
	unsigned long long	nb;

	nb = va_arg(args, unsigned long long);
	s->len += write(1, "0x", 2);
	ft_putnbr_base(nb, 16, str);
	s->len += ft_nbrlen_base(nb, 16, str);
}
