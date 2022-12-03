/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:58:03 by tsedigi           #+#    #+#             */
/*   Updated: 2014/11/06 08:06:04 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*temp;
	char	*temp1;

	i = 0;
	temp = (char *)src;
	temp1 = (char *)dest;
	while (i < n)
	{
		temp1[i] = temp[i];
		i++;
	}
	return (dest);
}
