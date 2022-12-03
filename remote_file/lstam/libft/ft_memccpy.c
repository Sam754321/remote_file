/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 02:34:08 by tsedigi           #+#    #+#             */
/*   Updated: 2014/11/07 04:21:34 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*temp;
	char	*temp2;

	i = 0;
	temp = (char *)src;
	temp2 = (char *)dest;
	while (i < n)
	{
		temp2[i] = temp[i];
		if (temp[i] == c)
			return (&temp2[i + 1]);
		i++;
	}
	return (NULL);
}
