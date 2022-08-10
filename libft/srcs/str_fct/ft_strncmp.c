/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:16:42 by knerini           #+#    #+#             */
/*   Updated: 2022/03/27 10:20:40 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char const *s1, char const *s2, size_t n)
{
	size_t				i;
	unsigned char const	*str1;
	unsigned char const	*str2;

	str1 = (unsigned char const *)s1;
	str2 = (unsigned char const *)s2;
	i = 0;
	while (str1[i] && str2 [i] && i < n)
	{
		if (str1[i] != str2[i])
			return (str1 [i] - str2[i]);
		i++;
	}
	if (i < n)
		return (str1[i] - str2[i]);
	return (0);
}
