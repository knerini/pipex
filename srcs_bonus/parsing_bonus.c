/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:04:02 by knerini           #+#    #+#             */
/*   Updated: 2023/01/20 15:54:26 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parsing(int ac, char **av, char **envp)
{
	if (ac < 5)
	{
		ft_printf("Error : too few arguments\n");
		exit(EXIT_FAILURE);
	}
	if (envp == NULL)
	{
		ft_printf("Error : missing environment\n");
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(av[1], "here_doc", 9) == 0 && ac < 6)
	{
		ft_printf("Error : too few arguments to handle the here_doc\n");
		exit(EXIT_FAILURE);
	}
	return ;
}

int	here_doc_file(char *limiter)
{
	char	*temp;
	int		tmp;

	tmp = open(".temporary", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (tmp == -1)
		exit(EXIT_FAILURE);
	write(1, "here_doc: ", 10);
	temp = get_next_line(0);
	while (temp && ft_strncmp(temp, limiter, (ft_strlen(temp) - 1)) != 0)
	{
		write(1, "here_doc: ", 10);
		ft_putstr_fd(temp, tmp);
		if (temp)
			free (temp);
		temp = get_next_line(0);
	}
	if (close(tmp) == -1)
		exit(EXIT_FAILURE);
	return (open_infile(".temporary"));
}
