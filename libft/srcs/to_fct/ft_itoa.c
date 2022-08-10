/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:05:43 by knerini           #+#    #+#             */
/*   Updated: 2022/04/07 18:40:57 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long int	nb;
	int			len;
	char		*nbr;

	len = ft_nbrlen(n);
	nbr = malloc((len + 1) * sizeof(char));
	if (!nbr)
		return (NULL);
	nb = n;
	if (nb == 0)
		nbr[0] = '0';
	if (nb < 0)
	{
		nbr[0] = '-';
		nb *= -1;
	}
	nbr[len--] = '\0';
	while (nb)
	{
		nbr[len] = (nb % 10) + '0';
		len --;
		nb /= 10;
	}
	return (nbr);
}
