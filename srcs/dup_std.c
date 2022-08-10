/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_std.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:56:34 by knerini           #+#    #+#             */
/*   Updated: 2022/08/02 18:57:08 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	dup_stdin(int index, int **pipes, int in)
{
	if (in != 0)
	{
		if (dup2(in, STDIN_FILENO) == -1)
		{
			ft_printf("Dup() call failed : %s", strerror(errno));
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (dup2(pipes[index][0], STDIN_FILENO) == -1)
		{
			ft_printf("Dup() call failed : %s", strerror(errno));
			exit(EXIT_FAILURE);
		}
	}
	return ;
}

void	dup_stdout(int index, int **pipes, int out)
{
	if (out != 0)
	{
		if (dup2(out, STDOUT_FILENO) == -1)
		{
			ft_printf("Dup() call failed : %s", strerror(errno));
			exit(EXIT_FAILURE);
		}
		if (close(out) == -1)
		{
			ft_printf("Close() call outfile failed : %s", strerror(errno));
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (dup2(pipes[index + 1][1], STDOUT_FILENO) == -1)
		{
			ft_printf("Dup() call failed : %s", strerror(errno));
			exit(EXIT_FAILURE);
		}
	}
	return ;
}
