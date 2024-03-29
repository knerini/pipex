/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:53:47 by knerini           #+#    #+#             */
/*   Updated: 2022/08/19 14:35:41 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipex	init_struct(char **av, char **envp, int ac)
{
	t_pipex	pipex;

	if (ft_strncmp(av[1], "here_doc", 9) != 0)
		pipex.cases = 0;
	else if (ft_strncmp(av[1], "here_doc", 9) == 0 && ac >= 6)
		pipex.cases = 1;
	if (pipex.cases == 0)
	{
		pipex.process = ac - 3;
		pipex.fd_infile = open_infile(av[1]);
	}
	else if (pipex.cases == 1)
	{
		pipex.process = ac - 4;
		pipex.fd_infile = here_doc_file(av[2]);
	}
	pipex.fd_outfile = open_create_outfile_bonus(av[ac - 1], pipex.cases);
	pipex.cmd = av;
	pipex.env = envp;
	pipex.env_path = parsing_env(envp);
	pipex.ac = ac - 1;
	return (pipex);
}

t_child	init_struct_child(t_pipex *pipex, int index)
{
	t_child	c_path;

	if (pipex->cases == 0)
		c_path.options = ft_split(pipex->cmd[index + 2], ' ');
	else if (pipex->cases == 1)
		c_path.options = ft_split(pipex->cmd[index + 3], ' ');
	c_path.shell_cmd = c_path.options[0];
	c_path.paths_array = construct_path(pipex->env_path, c_path.shell_cmd);
	c_path.check = 1;
	return (c_path);
}
