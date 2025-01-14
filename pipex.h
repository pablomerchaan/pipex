#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include<sys/types.h>
# include<sys/stat.h>
# include <fcntl.h>  
# include <stdlib.h>

void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int	ft_putstr(char *str);
char	**ft_split(char const *s, char c);
void exitaux();
void	freeall(char **m);
int open_f(char *file, int sw);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_strcmp(char *s1, char *s2);
char	*getpathaux(char *path, char **env);
char	*getpath(char *cmd, char **env);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

#endif
