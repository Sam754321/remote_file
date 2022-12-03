/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 06:10:48 by tsedigi           #+#    #+#             */
/*   Updated: 2015/03/18 06:10:49 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_str_rev(char *str)
{
	int		i;
	int		x;
	char	c;

	i = 0;
	x = ft_strlen(str) - 1;
	while (str[i] && i < x)
	{
		c = str[i];
		str[i] = str[x];
		str[x] = c;
		i++;
		x--;
	}
}
