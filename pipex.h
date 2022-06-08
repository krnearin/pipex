/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*     main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krnearin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 19:05:27 by krnearin          #+#    #+#             */
/*   Updated: 2021/08/12 19:05:27 by krnearin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <string.h>

void	ft_pipex(char **argv, char **envp);
void	ft_child_one(int pipefds[2], char **argv, char **envp);
void	ft_child_two(int pipefds[2], char **argv, char **envp);
void	ft_exit(char *error);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_env(char *cmdd, char **envp);
char	**ft_free_p(char **mas);
char	**ft_path(char **envp);

#endif
