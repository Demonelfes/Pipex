/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allopez <allopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 11:51:39 by allopez           #+#    #+#             */
/*   Updated: 2021/08/30 11:52:53 by allopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int     ft_chartablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void    ft_freetab(char **tab)
{
	int	i;

	i = ft_chartablen(tab) - 1;
	while (i >= 0)
		free(tab[i--]);
}
