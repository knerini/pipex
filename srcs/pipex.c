/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:28:06 by knerini           #+#    #+#             */
/*   Updated: 2022/08/16 17:54:02 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	waiting_management(t_pipex *pipex, int *pids)
{
	int	i;
	int	wait_status;
	int	error;

	error = 0;
	i = -1;
	while (++i < pipex->process)
	{
		wait_status = waitpid(pids[i], &error, 0);
		if (wait_status == -1)
			exit(EXIT_FAILURE);
	}
	free(pids);
	return (WEXITSTATUS(error));
}

void	closing_management(t_pipex *pipex, int **process)
{
	int	i;

	i = -1;
	while (++i < pipex->process)
	{
		if (close(process[i][0]) == -1 || close(process[i][1]) == -1)
			exit(EXIT_FAILURE);
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
	if (strchr(c_path.options[0], '/'))
		valid_path = c_path.options[0];
	else
		valid_path = checked_path(&c_path);
	in = is_stdin(index, pipex);
	out = is_stdout(index, pipex);
	dup_stdin(index, pipes, in);
	dup_stdout(index, pipes, out);
	closing_management(pipex, pipes);
	if (in == -1)
		exit(EXIT_FAILURE);
	execve(valid_path, c_path.options, pipex->env);
	exit(EXIT_FAILURE);
}

int	parent_process(t_pipex *pipex)
{
	pid_t	*pids;
	int		**pipes;
	int		exit_code;
	int		i;

	pids = pid_array(pipex->process);
	pipes = pipe_array(pipex->process);
	i = -1;
	while (++i < pipex->process)
	{
		pids[i] = fork();
		if (pids[i] == -1)
			exit(EXIT_FAILURE);
		else if (pids[i] == 0)
			child_process(pipex, i, pipes);
	}
	closing_management(pipex, pipes);
	closing_files(pipex->fd_infile, pipex->fd_outfile);
	exit_code = waiting_management(pipex, pids);
	free_int_array(pipes, pipex->process);
	return (exit_code);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;
	int		exit_code;

	if (ac < 5)
	{
		ft_printf("Error : too few arguments\n");
		return (0);
	}
	if (ac > 5)
	{
		ft_printf("Error : too many arguments\n");
		return (0);
	}
	pipex = init_struct(av, envp, ac);
	exit_code = parent_process(&pipex);
	return (exit_code);
}
