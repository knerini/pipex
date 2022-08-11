/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:04:02 by knerini           #+#    #+#             */
/*   Updated: 2022/08/11 13:57:31 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parsing(int ac, char **av, char **envp)
{
	if (ac < 5)
	{
		ft_printf("Error : too few arguments\n");
		exit(EXIT_FAILURE);
	}
	if (envp == NULL)
	{
		ft_printf("Error : missing environment\n");
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(av[1], "here_doc", 9) == 0 && ac < 6)
	{
		ft_printf("Error : too few arguments to handle the here_doc\n");
		exit(EXIT_FAILURE);
	}
	return ;
}
