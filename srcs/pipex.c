/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:28:06 by knerini           #+#    #+#             */
/*   Updated: 2022/08/22 14:53:44 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	waiting_management(t_pipex *pipex, int *pids, int **pipes)
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
			parent_exit(pipex, pids, pipes);
	}
	free(pids);
	return (WEXITSTATUS(error));
}

void	child_process(t_pipex *pipex, int index, int **pipes)
{
	int		in;
	int		out;
	char	*valid_path;
	t_child	c_path;

	in = is_stdin(index, pipex);
	out = is_stdout(index, pipex);
	c_path = init_struct_child(pipex, index);
	if (strchr(c_path.options[0], '/'))
		valid_path = tested_path(c_path.options[0]);
	else
		valid_path = checked_path(&c_path);
	dup_stdin(index, pipes, in);
	dup_stdout(index, pipes, out);
	child_closing(pipex, pipes);
	if (execve(valid_path, c_path.options, pipex->env) == -1)
	{
		if (valid_path)
			free(valid_path);
		free_char_array(c_path.options);
		exit(EXIT_FAILURE);
	}
}

void	parent_exit(t_pipex *pipex, int *pids, int **pipes)
{
	if (pipex->env_path)
		free(pipex->env_path);
	if (pids)
		free(pids);
	free_int_array(pipes, pipex->process);
	exit(1);
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
			parent_exit(pipex, pids, pipes);
		else if (pids[i] == 0)
			child_process(pipex, i, pipes);
	}
	parent_closing(pipex, pids, pipes);
	closing_files(pipex, pipes, pids);
	exit_code = waiting_management(pipex, pids, pipes);
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
	if (pipex.env_path)
		free(pipex.env_path);
	return (exit_code);
}
