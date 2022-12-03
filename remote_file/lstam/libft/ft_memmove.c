/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:31:52 by tsedigi           #+#    #+#             */
/*   Updated: 2014/11/18 08:08:28 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*temp;
	char	*temp2;
	size_t	i;

	temp = (char *)src;
	temp2 = (char *)dest;
	i = 0;
	if (n == 0 || dest == src)
		return (dest);
	if (dest < src)
	{
		while (n--)
		{
			temp2[i] = temp[i];
			i++;
		}
		return (dest);
	}
	else if (src < dest)
	{
		while (n--)
			temp2[n] = temp[n];
	}
	return (dest);
}
