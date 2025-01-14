#include "pipex.h"

void	execute(char *cmd, char **env)
{
	char	**split_cmd;
	char	*path;

	split_cmd = ft_split(cmd, ' ');
	path = getpath(split_cmd[0], env);
	if (execve(path, split_cmd, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(split_cmd[0], 2);
		freeall(split_cmd);
		exit(0);
	}
}

void	child(char **argv, int *p_fd, char **env)
{
	int fd;
	int	copy_out;

	printf("child 1");
	fd = open_f(argv[1], 0);
	dup2(fd, STDIN_FILENO);
	dup2(p_fd[1], STDOUT_FILENO);
	close (p_fd[0]);
	execute(argv[2], env);
}

void	parent(char **argv, int *p_fd, char **env)
{
	int fd;

	fd = open_f(argv[4], 1);
	dup2(fd, STDOUT_FILENO);
	dup2(p_fd[0], STDIN_FILENO);
	close (p_fd[1]);
	execute(argv[3], env);
}

int main(int argc, char **argv, char **env)
{
	int	p_fd[2];
	pid_t	pid;
	int	i = 0;

	if (argc != 5)
		exitaux();
	if (pipe(p_fd) == -1)
		exit (-1);
	pid = fork();
	if (pid == -1)
		exit (-1);
	if (!pid)
		child(argv, p_fd, env);
	close (p_fd[1]);
	parent(argv, p_fd, env);
}
