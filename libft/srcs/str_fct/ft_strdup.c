/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:16:24 by knerini           #+#    #+#             */
/*   Updated: 2022/04/07 18:44:17 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s1)
{
	char	*str1;
	char	*s2;
	int		i;
	size_t	len;

	str1 = (char *)s1;
	len = ft_strlen(s1);
	s2 = malloc((len + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	i = 0;
	while (str1[i])
	{
		s2[i] = str1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
