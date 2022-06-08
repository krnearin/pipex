#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
		ft_exit ("example: ./pipex file1 cmd1 cmd2 file1");
	ft_pipex(argv, envp);
	return (0);
}
