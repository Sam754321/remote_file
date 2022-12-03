/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 04:57:09 by tsedigi           #+#    #+#             */
/*   Updated: 2014/11/18 08:46:57 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check(char c)
{
	int i;

	i = 0;
	if (c == ' ' || c == ',' || c == '\n' || c == '\t')
		i++;
	return (i);
}

static size_t	ft_start(char *str)
{
	size_t i;

	i = 0;
	while (ft_check(str[i]) == 1)
		i++;
	return (i);
}

static size_t	ft_len(char *str)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (ft_check(str[i]) == 0)
			j = 0;
		else
			j++;
		i++;
	}
	return (j);
}

char			*ft_strtrim(const char *str)
{
	char *cpy;
	char *tmp;

	tmp = (char*)str;
	cpy = NULL;
	if (!tmp)
		return (NULL);
	if (ft_start(tmp) == ft_strlen(tmp))
		cpy = ft_strdup("");
	else
		cpy = ft_strsub(tmp, ft_start(tmp), ft_strlen(tmp) -
		ft_start(tmp) - ft_len(tmp));
	return (cpy);
}
