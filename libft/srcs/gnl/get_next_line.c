/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:40:44 by knerini           #+#    #+#             */
/*   Updated: 2022/07/17 20:03:03 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl_read_and_join(int fd, char *stock)
{
	char	*temp;
	int		res_read;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	res_read = 1;
	while (!gnl_strchr(stock, '\n') && res_read != 0)
	{
		res_read = read(fd, temp, BUFFER_SIZE);
		if (res_read < 0)
		{
			free (temp);
			return (NULL);
		}
		temp[res_read] = '\0';
		stock = gnl_strjoin(stock, temp);
	}
	free(temp);
	return (stock);
}

char	*gnl_get_line(char *stock)
{
	int		i;
	size_t	len;
	char	*line;

	i = 0;
	if (!stock[i])
		return (NULL);
	if (!gnl_strchr(stock, '\n'))
		len = ft_strlen(stock) + 1;
	else
		len = ft_strlen(stock) - ft_strlen(gnl_strchr(stock, '\n')) + 1;
	line = malloc(sizeof(char) * len);
	if (!line)
		return (NULL);
	i = -1;
	while (stock[++i] && stock[i] != '\n')
		line[i] = stock[i];
	if (stock[i] == '\n')
	{
		line[i] = stock[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*gnl_save(char *stock)
{
	int		i;
	char	*save;

	if (!gnl_strchr(stock, '\n'))
	{
		free(stock);
		return (NULL);
	}
	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (!stock[i])
	{
		free(stock);
		return (NULL);
	}
	save = gnl_strdup(gnl_strchr(stock, '\n'));
	free(stock);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stock;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock = gnl_read_and_join(fd, stock);
	if (!stock)
		return (NULL);
	line = gnl_get_line(stock);
	stock = gnl_save(stock);
	return (line);
}
