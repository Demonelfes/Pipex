/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 16:03:21 by allopez           #+#    #+#             */
/*   Updated: 2020/01/11 16:03:23 by allopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		itoa_is_neg(int *nb, int *neg)
{
	if (*nb < 0)
	{
		*nb *= -1;
		*neg = 1;
	}
}

static int		len_init(int nb)
{
	int len;

	len = 2;
	while (nb /= 10)
		len++;
	return (len);
}

char			*ft_itoa(int nb)
{
	int		i;
	int		len;
	int		neg;
	char	*dest;

	neg = 0;
	itoa_is_neg(&nb, &neg);
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	i = nb;
	len = len_init(nb);
	len += neg;
	if (!(dest = (char *)malloc(sizeof(char) * len)))
		return (0);
	if (neg)
		dest[0] = '-';
	dest[--len] = '\0';
	while (len--)
	{
		dest[len] = nb % 10 + '0';
		nb /= 10;
	}
	if (neg)
		dest[0] = '-';
	return (dest);
}
