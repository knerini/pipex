/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:17:14 by knerini           #+#    #+#             */
/*   Updated: 2022/07/17 20:02:09 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_write_string(const char *str, t_format *s)
{
	char	*next;

	next = ft_strchr(str, '%');
	if (next)
		s->width = next - str;
	else
		s->width = ft_strlen(str);
	write(1, str, s->width);
	s->len += s->width;
	while (*str && *str != '%')
		++str;
	return (str);
}
