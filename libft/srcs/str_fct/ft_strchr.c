/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:16:20 by knerini           #+#    #+#             */
/*   Updated: 2022/03/31 18:08:23 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char const *str, int c)
{
	char	letter;
	int		i;
	char	*s;

	letter = (char)c;
	s = (char *)str;
	i = 0;
	while (s[i])
	{
		if (s[i] == letter)
			return (&s[i]);
		i++;
	}
	if (letter == 0)
		return (&s[i]);
	return (NULL);
}
