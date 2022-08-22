/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:23:19 by knerini           #+#    #+#             */
/*   Updated: 2022/08/22 16:52:30 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	**pipe_array(int nb_pipes)
{
	int	**pipes_array;
	int	i;

	i = -1;
	pipes_array = malloc(sizeof(int *) * nb_pipes);
	if (!pipes_array)
		exit(EXIT_FAILURE);
	while (++i < nb_pipes)
	{
		pipes_array[i] = malloc(sizeof(int) * 2);
		if (!pipes_array[i])
		{
			free_int_array(pipes_array, i);
			exit(EXIT_FAILURE);
		}
		if (pipe(pipes_array[i]) == -1)
		{
			free_int_array(pipes_array, i);
			exit(EXIT_FAILURE);
		}
	}
	return (pipes_array);
}

pid_t	*pid_array(int nb_processes)
{
	pid_t	*pid_array;

	pid_array = malloc(sizeof(pid_t) * nb_processes);
	if (!pid_array)
		exit(EXIT_FAILURE);
	return (pid_array);
}

void	free_int_array(int **array, int nb_pipes)
{
	int	i;

	i = 0;
	while (i < nb_pipes)
	{
		if (array[i])
			free(array[i]);
		i++;
	}
	free(array);
	return ;
}

void	free_char_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (array[i])
			free(array[i]);
		i++;
	}
	free(array);
	return ;
}
