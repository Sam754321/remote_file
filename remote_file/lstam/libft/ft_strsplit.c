/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 05:29:53 by tsedigi           #+#    #+#             */
/*   Updated: 2014/11/07 06:44:56 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_count_str(const char *str, const char c)
{
	size_t	i;
	size_t	cpt;
	int		on;

	i = 0;
	cpt = 0;
	on = 0;
	while (str[i])
	{
		if (on == 0 && str[i] != c)
		{
			cpt++;
			on = 1;
		}
		else if (on == 1 && str[i] == c)
			on = 0;
		i++;
	}
	return (cpt);
}

static void	ft_add_split(const char *str, const char c, char **tab)
{
	size_t i;
	size_t cpt;
	size_t nb;

	i = 0;
	cpt = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			while (str[i] != c && str[i] != '\0')
			{
				cpt++;
				i++;
			}
			tab[nb] = ft_strsub(str, (i - cpt), cpt);
			cpt = 0;
			nb++;
		}
		else
			i++;
	}
}

char		**ft_strsplit(const char *str, const char c)
{
	size_t	cpt;
	char	**new;

	if (!str)
		return (NULL);
	cpt = ft_count_str(str, c);
	new = NULL;
	if ((new = (char**)malloc(sizeof(char*) * (cpt + 1))))
	{
		ft_add_split(str, c, new);
		new[cpt] = 0;
	}
	return (new);
}
