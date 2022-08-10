/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:16:00 by knerini           #+#    #+#             */
/*   Updated: 2022/03/31 17:55:50 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *str, int c, size_t n)
{
	unsigned char	*str2;
	size_t			i;
	unsigned char	letter;

	str2 = (unsigned char *)str;
	letter = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str2[i] == letter)
			return ((str2 + i));
		i++;
	}
	return (NULL);
}
