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

#include "pipex.h"

void	ft_exit(char *error)
{
	write(1, error, ft_strlen(error));
	write(1, "\n", 1);
	exit(0);
}

char	**ft_free_p(char **mas)
{
	int	i;

	i = 0;
	while (mas && mas[i])
	{
		free(mas[i]);
		i++;
	}
	free(mas);
	return (NULL);
}
