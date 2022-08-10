/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:08:23 by knerini           #+#    #+#             */
/*   Updated: 2022/07/17 20:01:38 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_convert_s(va_list args, t_format *s)
{
	char	*s1;

	s1 = va_arg(args, char *);
	if (!s1)
	{
		write(1, "(null)", 6);
		s->len += 6;
	}
	else
	{
		ft_putstr_fd(s1, 1);
		s->len += ft_strlen(s1);
	}
}
