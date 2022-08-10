/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 22:23:52 by knerini           #+#    #+#             */
/*   Updated: 2022/07/18 20:40:01 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_convert_u(va_list args, t_format *s, const char *str)
{
	unsigned int	nb;

	nb = va_arg(args, unsigned int);
	ft_putnbr_base(nb, 10, str);
	s->len += ft_nbrlen_base(nb, 10, str);
}
