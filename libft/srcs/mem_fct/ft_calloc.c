/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:15:29 by knerini           #+#    #+#             */
/*   Updated: 2022/04/09 12:03:50 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nb, size_t mem)
{
	void	*ptr;

	ptr = malloc(nb * mem);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, (nb * mem));
	return (ptr);
}
