/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:36:10 by tsedigi           #+#    #+#             */
/*   Updated: 2015/03/23 06:24:53 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	if (!s1 && s2)
		return (-b[0]);
	if (!s2 && s1)
		return (b[0]);
	if (!s1 && !s2)
		return (0);
	while (*a && *b && *a == *b)
	{
		a++;
		b++;
	}
	return (*a - *b);
}
