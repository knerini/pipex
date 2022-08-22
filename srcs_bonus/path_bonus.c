/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:15:11 by knerini           #+#    #+#             */
/*   Updated: 2022/08/22 12:05:58 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*parsing_env(char **envp)
{
	char	*env_path;
	size_t	pathlen;

	env_path = NULL;
	pathlen = ft_strlen("PATH=");
	while (*envp)
	{
		if (ft_strnstr(*envp, "PATH=", pathlen))
		{
			env_path = ft_substr(*envp, pathlen, (ft_strlen(*envp) - pathlen));
			return (env_path);
		}
		envp++;
	}
	return (NULL);
}

char	**fill_array(char **split_env_path, char *cmd)
{
	char	**paths_array;
	int		i;

	i = 0;
	while (split_env_path[i])
		i++;
	paths_array = malloc(sizeof(char *) * (i + 1));
	if (!paths_array)
		return (NULL);
	i = -1;
	while (split_env_path[++i])
		paths_array[i] = ft_strjoin(split_env_path[i], cmd);
	paths_array[i] = NULL;
	return (paths_array);
}

char	**construct_path(char *env_path, char *shell_cmd)
{
	char	**split_env_paths;
	char	**paths_array;
	char	*final_cmd;

	final_cmd = ft_strjoin("/", shell_cmd);
	split_env_paths = ft_split(env_path, ':');
	if (env_path)
		free(env_path);
	paths_array = fill_array(split_env_paths, final_cmd);
	free_char_array(split_env_paths);
	if (final_cmd)
		free(final_cmd);
	return (paths_array);
}

char	*checked_path(t_child *c_path)
{
	char	*valid_path;
	int		i;

	i = 0;
	valid_path = NULL;
	while (c_path->paths_array[i])
	{
		c_path->check = access(c_path->paths_array[i], F_OK | X_OK);
		if (c_path->check == 0)
		{
			valid_path = ft_strdup(c_path->paths_array[i]);
			return (valid_path);
		}
		else
			i++;
	}
	free_char_array(c_path->paths_array);
	if (valid_path == NULL)
	{
		ft_putstr_fd(c_path->shell_cmd, 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(127);
	}
	return (valid_path);
}

char	*tested_path(char *abs_path)
{
	char	*valid_path;

	valid_path = NULL;
	if (access(abs_path, F_OK | X_OK) == -1)
	{
		ft_putstr_fd(abs_path, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		exit(127);
	}
	valid_path = abs_path;
	return (valid_path);
}
