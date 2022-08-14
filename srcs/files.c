/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:12:57 by knerini           #+#    #+#             */
/*   Updated: 2022/08/14 12:10:42 by knerini          ###   ########.fr       */
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
		out = pipex->fd_outfile;
	else
		out = 0;
	return (out);
}

int	open_create_outfile(char *name)
{
	int	out;

	out = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (out == -1)
	{
		ft_printf("Open() call outfile failed : %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	return (out);
}

int	open_infile(char *name)
{
	int	in;

	in = open(name, O_RDONLY);
	if (in == -1)
	{
		ft_printf("Open() call infile failed : %s\n", strerror(errno));
		return (0);
	}
	return (in);
}

void	closing_files(int in, int out)
{
	if (close(in) == -1 || close(out) == -1)
	{
		ft_printf("Close() call files in/out failed : %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	return ;
}
