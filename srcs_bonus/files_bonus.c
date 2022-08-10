/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:12:57 by knerini           #+#    #+#             */
/*   Updated: 2022/08/09 16:59:21 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_stdin(int index, t_pipex *pipex)
{
	int	in;

	if (index == 0)
		in = pipex->fd_infile;
	else
		in = 0;
	return (in);
}

int	is_stdout(int index, t_pipex *pipex)
{
	int	out;

	if (index == (pipex->process - 1))
		out = open_create_outfile(pipex->cmd[pipex->ac]);
	else
		out = 0;
	return (out);
}

int	open_create_outfile(char *str)
{
	int	out;

	out = open(str, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (out == -1)
	{
		ft_printf("Open() call outfile failed : %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	return (out);
}

int	open_infile(char *str)
{
	int	in;

	in = open(str, O_RDONLY);
	if (in == -1)
	{
		ft_printf("Open() call infile failed : %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	return (in);
}

int	here_doc_file(char *limiter)
{
	int	in;
	char	*temp;

	temp = NULL;
	if (open("temporary", O_CREAT | O_WRONLY | O_TRUNC, 0644) == -1)
	{
		ft_printf("Open() call temporary file for here_doc failed : %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	while (ft_strncmp(temp, limiter, ft_strlen(limiter)) != 0)
	{
		temp = get_next_line(0);
		ft_putstr_fd(temp, "temporary");
		if (temp)
			free (temp);
	}
	close("temporary"); //error management to do
	return (open_infile("temporary", O_RDONLY));
}
