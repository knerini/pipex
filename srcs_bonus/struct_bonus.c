/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:53:47 by knerini           #+#    #+#             */
/*   Updated: 2022/08/09 16:04:27 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipex	init_struct(char **av, char **envp, int ac, int case)
{
	t_pipex	pipex;

	pipex.cmd = av;
	pipex.env = envp;
	pipex.env_path = parsing_env(envp);
	pipex.ac = ac - 1;
	if (case == 0)
		pipex.fd_infile = open_infile(av[1]);
	else if (case == 1)
		pipex.fd_infile = //create function for here_doc
	pipex.process = ac - 3;
	return (pipex);
}

t_child	init_struct_child(t_pipex *pipex, int index)
{
	t_child	c_path;

	c_path.options = ft_split(pipex->cmd[index + 2], ' ');
	c_path.shell_cmd = c_path.options[0];
	c_path.paths_array = construct_path(pipex->env_path, c_path.shell_cmd);
	c_path.check = 1;
	return (c_path);
}
