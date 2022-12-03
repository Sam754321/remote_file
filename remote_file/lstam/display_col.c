/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_col.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 23:17:26 by tsedigi           #+#    #+#             */
/*   Updated: 2015/04/04 17:08:34 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			get_size_len(char **tab)
{
	size_t	x;
	int		i;

	x = 0;
	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
	{
		if (x < ft_strlen(tab[i]))
			x = ft_strlen(tab[i]);
		i++;
	}
	x += 6;
	return (x);
}

int			display_tab_col(char **tab, struct winsize *test, int size)
{
	int	max;
	int	col;
	int	x;
	int	i;
	int	x_max;

	x = 0;
	x_max = 0;
	i = 0;
	if (!tab || size == 0)
		return (0);
	max = get_size_len(tab);
	col = (test->ws_col / max);
	x_max = size / col;
	x_max++;
	print_tab_c_cap(tab, max, x_max, col);
	return (1);
}

char		**ft_list_to_tab(t_infos *llist, t_opt *option, int fold, int max)
{
	char	**ret;
	int		x;
	t_infos	*tmp;

	x = 0;
	if (max == 0)
		return (NULL);
	if ((ret = (char **)malloc(sizeof(char *) * max + 1)) == NULL)
		ft_putstr_fd("malloc failed () exit.\n", 2);
	tmp = llist;
	while (tmp)
	{
		if ((tmp->name[0] != '.' || option->flag & FLAG_A) ||\
			((ft_checkpoints(tmp->name) == 1) && option->flag & FLAG_CAP_A) ||\
			option->flag & FLAG_F)
		{
			if ((fold == 1) && (tmp->type == 3))
				ft_putstr("");
			else
				ret[x] = ft_strdup(tmp->name), x++;
		}
		tmp = tmp->nxt;
	}
	ret[x] = 0;
	return (ret);
}

int			ft_size_list(t_infos *llist, t_opt *option, int fold)
{
	t_infos	*tmp;
	int		max;

	tmp = llist;
	max = 0;
	while (tmp)
	{
		if ((tmp->name[0] != '.' || option->flag & FLAG_A) ||\
			((ft_checkpoints(tmp->name) == 1) && option->flag & FLAG_CAP_A) ||\
			option->flag & FLAG_F)
		{
			if ((fold == 1) && (tmp->type == 3))
				ft_putstr("");
			else
				max++;
		}
		tmp = tmp->nxt;
	}
	return (max);
}

int			display_col(t_infos *llist, t_opt *option, int fold)
{
	struct winsize	test;
	char			**tab;
	int				size;

	if (ioctl(STDIN_FILENO, TIOCGWINSZ, (char*)&test) < 0)
		ft_putstr_fd("error ioctl failed exit,\n", 2);
	size = ft_size_list(llist, option, fold);
	tab = ft_list_to_tab(llist, option, fold, size);
	return (display_tab_col(tab, &test, size));
}
