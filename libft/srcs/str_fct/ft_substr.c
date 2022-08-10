/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:52:11 by knerini           #+#    #+#             */
/*   Updated: 2022/04/07 18:45:35 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*new_s;

	i = start;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
	{
		new_s = ft_strdup("");
		return (new_s);
	}
	if (len >= ft_strlen(s + start))
		len = ft_strlen(s + start);
	new_s = malloc((len + 1) * sizeof(char));
	if (!new_s)
		return (NULL);
	while (s[i] && j < len)
			new_s[j++] = s[i++];
	new_s[j] = '\0';
	return (new_s);
}
