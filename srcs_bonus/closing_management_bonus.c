/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing_management_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:07:24 by knerini           #+#    #+#             */
/*   Updated: 2022/08/22 11:07:33 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_closing(t_pipex *pipex, int *pids, int **pipes)
{
	int	i;

	i = -1;
	while (++i < pipex->process)
	{
		if (close(pipes[i][0]) == -1 || close(pipes[i][1]) == -1)
			parent_exit(pipex, pids, pipes);
	}
	return ;
}

void	child_closing(t_pipex *pipex, int **pipes)
{
	int	i;

	i = -1;
	while (++i < pipex->process)
	{
		if (close(pipes[i][0]) == -1 || close(pipes[i][1]) == -1)
			exit(1);
	}
	return ;
}
