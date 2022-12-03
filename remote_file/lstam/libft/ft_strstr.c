/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:02:36 by tsedigi           #+#    #+#             */
/*   Updated: 2014/11/18 08:40:11 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*temp;
	int		i;

	temp = (char *)s1;
	i = 0;
	if (!s2 || !*s2)
		return (temp);
	if (!s1)
		return (NULL);
	while (temp[i])
	{
		if (temp[i] == s2[0])
		{
			if ((ft_strncmp(&temp[i], s2, ft_strlen(s2))) == 0)
				return (&temp[i]);
		}
		i++;
	}
	return (NULL);
}
