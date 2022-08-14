/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:41:21 by knerini           #+#    #+#             */
/*   Updated: 2022/08/14 18:23:22 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen_base(long long int nb, size_t base, const char *str)
{
	int					i;
	unsigned long long	n;

	i = 0;
	if (nb < 0 && *str != 'p')
	{
		i++;
		n = nb * -1;
	}
	else
		n = nb;
	if (n == 0)
	{
		i++;
		return (i);
	}
	while (n)
	{
		n /= base;
		i++;
	}
	return (i);
}
