/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:46:13 by knerini           #+#    #+#             */
/*   Updated: 2022/08/22 10:56:36 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include "libft.h"

//------STRUCT-----
typedef struct s_pipex
{
	char	**cmd;
	char	**env;
	char	*env_path;
	int		cases;
	int		ac;
	int		fd_infile;
	int		fd_outfile;
	int		process;
}			t_pipex;

typedef struct s_child
{
	char	**options;
	char	**paths_array;
	char	*shell_cmd;
	int		check;
}	t_child;

//-----STRUCT-------
t_pipex	init_struct(char **av, char **envp, int ac);
t_child	init_struct_child(t_pipex *pipex, int index);

//-------PATH-------
char	*checked_path(t_child *c_path);
char	*tested_path(char *abs_path);
char	*parsing_env(char **envp);
char	**construct_path(char *env_path, char *shell_cmd);
char	**fill_array(char **split_tab, char *cmd);

//-----PIPEX----
int		parent_process(t_pipex *pipex);
int		waiting_management(t_pipex *pipex, int *pids, int **pipes);
void	child_process(t_pipex *pipex, int index, int **pipes);
void	parent_exit(t_pipex *pipex, int *pids, int **pipes);

//-----ARRAYS----
int		**pipe_array(int nb_pipes);
pid_t	*pid_array(int nb_processes);
void	free_int_array(int **array, int nb_pipes);
void	free_char_array(char **array);

//----FILES-----
int		is_stdin(int index, t_pipex *pipex);
int		is_stdout(int index, t_pipex *pipex);
int		open_create_outfile(char *name);
int		open_create_outfile_bonus(char *name, int cases);
int		open_infile(char *name);
void	closing_files(t_pipex *pipex, int **pipes, int *pids);

//-----DUP_STD-----
void	dup_stdin(int index, int **pipes, int in);
void	dup_stdout(int index, int **pipes, int out);

//------PARSING----
int		here_doc_file(char *limiter);
void	parsing(int ac, char **av, char **envp);

//-----CLOSING_MANAGEMENT-----
void	child_closing(t_pipex *pipex, int **pipes);
void	parent_closing(t_pipex *pipex, int *pids, int **pipes);

#endif
