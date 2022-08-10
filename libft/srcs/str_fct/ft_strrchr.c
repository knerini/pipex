/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:16:49 by knerini           #+#    #+#             */
/*   Updated: 2022/03/31 18:17:18 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *str, int c)
{
	char	letter;
	char	*s;
	size_t	i;

	i = ft_strlen(str);
	letter = (char)c;
	s = (char *)str;
	if (letter == 0)
		return (&s[i]);
	while (i > 0)
	{
		i--;
		if (s[i] == letter)
			return (&s[i]);
	}
	return (NULL);
}
