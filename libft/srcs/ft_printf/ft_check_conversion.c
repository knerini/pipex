/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:46:38 by knerini           #+#    #+#             */
/*   Updated: 2022/07/17 20:00:49 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_check_conversion(va_list args, const char *str, t_format *s)
{
	if (*str == 'c')
		ft_convert_c(args, s);
	else if (*str == 's')
		ft_convert_s(args, s);
	else if (*str == 'd' || *str == 'i')
		ft_convert_di(args, s, str);
	else if (*str == 'x' || *str == 'X')
		ft_convert_x(args, s, str);
	else if (*str == 'p')
		ft_convert_p(args, s, str);
	else if (*str == 'u')
		ft_convert_u(args, s, str);
	else if (*str == '%')
	{
		write(1, "%", 1);
		s->len += 1;
	}
	else
		return (NULL);
	str++;
	return (str);
}
