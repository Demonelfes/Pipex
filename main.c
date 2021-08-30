/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allopez <allopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:19:25 by aisraely          #+#    #+#             */
/*   Updated: 2021/08/30 11:53:15 by allopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	main(int argc, char **argv)
{
	if (argc < 5)
		ft_error("Pipex usage : ./pipex file1 cmd1 cmd2 file2");
	ft_pipex(argc, argv);
}
