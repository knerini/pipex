/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:28:06 by knerini           #+#    #+#             */
/*   Updated: 2022/08/11 15:45:54 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	waiting_management(t_pipex *pipex, int *pids)
{
	int	i;
	int	wait_status;

	i = -1;
	while (++i < pipex->process)
	{
		wait_status = waitpid(pids[i], NULL, 0);
		if (wait_status == -1)
		{
			ft_printf("Waitpid() : %s\n", strerror(errno));
			exit(EXIT_FAILURE);
		}
	}
	free(pids);
	return ;
}

void	closing_management(t_pipex *pipex, int **process)
{
	int	i;

	i = -1;
	while (++i < pipex->process)
	{
		if (close(process[i][0]) == -1 || close(process[i][1]) == -1)
		{
			ft_printf("Close() call failed : %s\n", strerror(errno));
			exit(EXIT_FAILURE);
		}
	}
	return ;
}

void	child_process(t_pipex *pipex, int index, int **pipes)
{
	int		in;
	int		out;
	char	*valid_path;
	t_child	c_path;

	c_path = init_struct_child(pipex, index);
	valid_path = checked_path(&c_path);
	in = is_stdin(index, pipex);
	out = is_stdout(index, pipex);
	dup_stdin(index, pipes, in);
	dup_stdout(index, pipes, out);
	closing_management(pipex, pipes);
	if (pipex->cases == 1)
		unlink("temporary");
	execve(valid_path, c_path.options, pipex->env);
	ft_printf("Execve() call failed : %s\n", strerror(errno));
	exit(EXIT_FAILURE);
}

void	parent_process(t_pipex *pipex)
{
	pid_t	*pids;
	int		**pipes;
	int		i;

	pids = pid_array(pipex->process);
	pipes = pipe_array(pipex->process);
	i = -1;
	while (++i < pipex->process)
	{
		pids[i] = fork();
		if (pids[i] == -1)
		{
			ft_printf("Fork() call failed : %s", strerror(errno));
			exit(EXIT_FAILURE);
		}
		else if (pids[i] == 0)
			child_process(pipex, i, pipes);
	}
	closing_management(pipex, pipes);
	if (close(pipex->fd_infile) == -1)
	{
		ft_printf("Close() call infile parent's process failed : %s", strerror(errno));
		exit(EXIT_FAILURE);
	}
	waiting_management(pipex, pids);
	free_int_array(pipes, pipex->process);
	return ;
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	parsing(ac, av, envp);
	pipex = init_struct(av, envp, ac);
	parent_process(&pipex);
	// system ("leaks pipex");
	return (0);
}
