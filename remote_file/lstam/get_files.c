/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 02:01:55 by tsedigi           #+#    #+#             */
/*   Updated: 2015/02/02 02:01:56 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		*ft_returni(char **argv, int i, int b)
{
	int	*tab;

	if ((tab = (int*)malloc(sizeof(int) * 2)) == NULL)
		print_err(1, 'c');
	while (argv[i] && b)
	{
		if (argv[i][0] == '-')
		{
			if (argv[i][1] == '-')
				b = 0;
			else if (argv[i][1] == '\0')
			{
				b = 0;
				break ;
			}
			i++;
		}
		else
			b = 0;
	}
	tab[0] = b;
	tab[1] = i;
	return (tab);
}

char	**get_files(int argc, char **argv, char *opt_d)
{
	char	**tab;
	int		j;
	int		*intab;

	j = 0;
	tab = (char**)malloc(sizeof(char*) * (argc + 1));
	if (argv == NULL && opt_d != NULL)
	{
		tab[0] = ft_strdup(opt_d);
		tab[1] = 0;
		return (tab);
	}
	intab = ft_returni(argv, 1, 1);
	while (argv[intab[1]])
	{
		if (ft_strlen(argv[intab[1]]) == 0)
			print_err(2, 'c');
		tab[j++] = ft_strdup(argv[intab[1]++]);
	}
	tab[j] = 0;
	if (intab[0] == 1)
		return (NULL);
	return (tab);
}
