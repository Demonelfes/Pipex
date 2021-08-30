/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allopez <allopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 13:24:14 by allopez           #+#    #+#             */
/*   Updated: 2021/08/30 13:24:19 by allopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_setlens(char *s1, char *s2, int *len1, int *len2)
{
	*len1 = ft_strlen((char *)s1);
	*len2 = ft_strlen((char *)s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*result;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	ft_setlens((char *) s1, (char *) s2, &len1, &len2);
	result = (char *) malloc((len1 + len2) * sizeof(char));
	if (!(result))
		return (NULL);
	i = 0;
	while (i < len1)
	{
		*(result + i) = *(s1 + i);
		i++;
	}
	i = 0;
	while (i < len2)
	{
		*(result + len1 + i) = *(s2 + i);
		i++;
	}
	*(result + len1 + i) = '\0';
	return (result);
}
