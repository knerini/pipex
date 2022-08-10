/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:16:17 by knerini           #+#    #+#             */
/*   Updated: 2022/03/27 18:54:46 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*str2;
	unsigned char	c2;

	i = 0;
	str2 = (unsigned char *)str;
	c2 = (unsigned char)c;
	while (i < n)
	{
		str2[i] = c2;
		i++;
	}
	return (str);
}
