/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:53:12 by knerini           #+#    #+#             */
/*   Updated: 2022/07/18 20:40:10 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_convert_x(va_list args, t_format *s, const char *str)
{
	unsigned int	nb;

	nb = va_arg(args, unsigned int);
	ft_putnbr_base(nb, 16, str);
	s->len += ft_nbrlen_base(nb, 16, str);
}
