/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 04:04:42 by tsedigi           #+#    #+#             */
/*   Updated: 2015/03/02 04:04:43 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_free_opt(t_opt *option)
{
	if (!option)
		return ;
	if (option->opt_d)
		free(option->opt_d);
	free(option);
}

void	ft_free_files(char **files)
{
	int i;

	i = 0;
	if (!files || !(*files))
		return ;
	while (files[i])
	{
		free(files[i]);
		i++;
	}
	free(files);
}

int		ft_size_tab(char **tab)
{
	int i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

void	print_tab_c_cap(char **tab, int max, int x_max, int col)
{
	int x;
	int i;

	i = 0;
	x = 0;
	while (x < x_max)
	{
		while (i < col)
		{
			if (x + (i * x_max) < ft_size_tab(tab) && x_max > 1)
			{
				ft_putstr(tab[x + (i * x_max)]);
				ft_putspace(ft_strlen(tab[x + (i * x_max)]), max);
			}
			else if (x_max == 0 && i < ft_size_tab(tab))
			{
				ft_putstr(tab[i]);
				ft_putspace(ft_strlen(tab[i]), max);
			}
			i++;
		}
		ft_putchar('\n');
		x++;
		i = 0;
	}
}
