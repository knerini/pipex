/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:16:46 by knerini           #+#    #+#             */
/*   Updated: 2022/04/01 18:49:57 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;
	char	*str2;

	i = 0;
	str2 = (char *)str;
	if (ft_strlen(to_find) == 0)
		return (str2);
	while (str[i] && i < n)
	{
		j = 0;
		while (str[i + j] && to_find[j] && str[i + j] == to_find[j]
			&& (i + j) < n)
			j++;
		if (j == ft_strlen(to_find))
			return (&str2[i]);
		i++;
	}
	return (NULL);
}
