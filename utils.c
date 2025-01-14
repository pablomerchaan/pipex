#include "pipex.h"

void exitaux()
{
	ft_putstr("./pipex infile cmd cmd outfile\n");
	exit(0);
}

int open_f(char *file, int sw)
{
	int r;

	if (sw == 0)
		r = open(file, O_RDONLY, 0777);
	if (sw == 1)
		r = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	return (r);
}

void	freeall(char **m)
{
	int c;

	c = 0;
	while (m[c])
	{
		free (m[c]);
		c++;
	}
	free (m);
}

char	*getpathaux(char *path, char **env)
{
	int	i;
	int	j;
	char	*key;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] != '=')
			j++;
		key = ft_substr(env[i], 0, j);
		if (ft_strcmp(key, path) == 0)
		{
			free (key);
			return (env[i] + j + 1);
		}
		free (key);
		i++;
	}
	return (NULL);
}

char	*getpath(char *cmd, char **env)
{
	int	i;
	char	**paths;
	char	*eachpath;
	char	*fullpath;

	paths = ft_split(getpathaux("PATH", env), ':');
	i = 0;
	while (paths[i])
	{
		eachpath = ft_strjoin(paths[i], "/");
		fullpath = ft_strjoin(eachpath, cmd);
		printf("%s", fullpath);
		free (eachpath);
		if (access(fullpath, F_OK | X_OK) == 0)
		{
			freeall(paths);
			return (fullpath);
		}
		free(fullpath);
		i++;
	}
	freeall(paths);
	return (cmd);
}
