/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:12:57 by knerini           #+#    #+#             */
/*   Updated: 2022/08/22 12:06:30 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_stdin(int index, t_pipex *pipex)
{
	int	in;

	if (index == 0)
	{
		in = pipex->fd_infile;
		if (in == 0)
			exit(EXIT_FAILURE);
	}
	else
		in = 0;
	return (in);
}

int	is_stdout(int index, t_pipex *pipex)
{
	int	out;

	if (index == (pipex->process - 1))
	{
		out = pipex->fd_outfile;
		if (out == -1)
			exit(EXIT_FAILURE);
	}
	else
		out = 0;
	return (out);
}

int	open_create_outfile_bonus(char *name, int cases)
{
	int	out;

	out = 0;
	if (cases == 0)
		out = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (cases == 1)
		out = open(name, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (out == -1)
	{
		ft_putstr_fd(name, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return (-1);
	}
	return (out);
}

int	open_infile(char *name)
{
	int	in;

	in = open(name, O_RDONLY);
	if (in == -1)
	{
		ft_putstr_fd(name, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return (0);
	}
	return (in);
}

void	closing_files(t_pipex *pipex, int **pipes, int *pids)
{
	if (close(pipex->fd_infile) == -1 || close(pipex->fd_outfile) == -1)
		parent_exit(pipex, pids, pipes);
	return ;
}
