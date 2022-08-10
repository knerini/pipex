/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:42:45 by knerini           #+#    #+#             */
/*   Updated: 2022/07/18 19:36:20 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list		args;
	t_format	s;

	va_start(args, str);
	s.len = 0;
	s.width = 0;
	while (*str)
	{
		if (*str == '%')
			str = ft_check_conversion(args, str + 1, &s);
		else
			str = ft_write_string(str, &s);
		if (!str)
		{
			write(1, "(null)", 6);
			va_end(args);
			return (s.len);
		}
	}
	va_end(args);
	return (s.len);
}
