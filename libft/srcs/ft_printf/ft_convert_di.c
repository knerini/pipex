/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_di.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:15:45 by knerini           #+#    #+#             */
/*   Updated: 2022/07/18 20:39:43 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_convert_di(va_list args, t_format *s, const char *str)
{
	int	nb;

	nb = va_arg(args, int);
	ft_putnbr_base(nb, 10, str);
	s->len += ft_nbrlen_base(nb, 10, str);
}
