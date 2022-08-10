/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:40:22 by knerini           #+#    #+#             */
/*   Updated: 2022/07/18 20:36:55 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl_strjoin(char *stock, char *temp)
{
	char	*new_str;
	int		i;
	int		j;

	if (!stock)
	{
		stock = malloc(sizeof(char) * 1);
		stock[0] = '\0';
	}
	if (!stock || !temp)
		return (NULL);
	new_str = malloc(sizeof(char) * (ft_strlen(stock) + ft_strlen(temp) + 1));
	if (!new_str)
		return (NULL);
	i = -1;
	j = -1;
	if (stock)
		while (stock[++i])
			new_str[i] = stock[i];
	while (temp[++j])
		new_str[i++] = temp[j];
	new_str[ft_strlen(stock) + ft_strlen(temp)] = '\0';
	free(stock);
	return (new_str);
}

char	*gnl_strchr(char *str, int c)
{
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str && str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i + 1]);
		i++;
	}
	return (NULL);
}

char	*gnl_strdup(char *str)
{
	char	*new;
	size_t	len;
	int		i;
	int		j;

	len = ft_strlen(str);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	j = -1;
	i = -1;
	while (str[++i])
		new[++j] = str[i];
	new[++j] = '\0';
	return (new);
}
