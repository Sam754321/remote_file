/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:07:31 by tsedigi           #+#    #+#             */
/*   Updated: 2014/11/06 06:38:04 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s1, int c, size_t n)
{
	size_t		i;
	char		*temp;

	i = 0;
	temp = (char *)s1;
	while (i < n)
	{
		temp[i] = c;
		i++;
	}
	return (s1);
}
