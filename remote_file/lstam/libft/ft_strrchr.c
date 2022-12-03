/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:58:27 by tsedigi           #+#    #+#             */
/*   Updated: 2014/11/18 08:34:00 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*new;
	size_t	i;
	char	*temp;

	new = NULL;
	i = 0;
	temp = (char *)s;
	while (temp[i])
	{
		if (temp[i] == c)
			new = &temp[i];
		i++;
	}
	if (temp[i] == c)
		new = &temp[i];
	return (new);
}
