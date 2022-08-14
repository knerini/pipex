/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:15:11 by knerini           #+#    #+#             */
/*   Updated: 2022/08/14 18:58:02 by knerini          ###   ########.fr       */
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
	if (valid_path == NULL)
	{
		ft_printf("Command not found : acces() failed or no valid path\n");
		exit(EXIT_FAILURE);
	}
	return (valid_path);
}
