/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 02:00:18 by tsedigi           #+#    #+#             */
/*   Updated: 2015/02/02 02:00:19 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		main_display2(t_infos *infos, t_err *error, t_opt *option)
{
	if (option->flag & FLAG_CAP_R)
	{
		if (option->j == 1 && !infos->nxt)
			display_recursive(infos, option, 2, option->j);
		else
			display_recursive(infos, option, option->n, option->j);
	}
	else if (option->j == 1 && infos != NULL)
	{
		if (!infos->nxt && !error)
			displaydirs(infos, option, 2);
		else if (error && !infos->nxt)
			displaydirs(infos, option, 0);
		else
			displaydirs(infos, option, option->n);
	}
	if (option)
		ft_free_opt(option);
}

void		main_display(t_infos *infos, t_err *error,
t_opt *option, char **files)
{
	if (error && files)
		display_err(error);
	if (infos != NULL)
	{
		if (option->flag & FLAG_D)
			;
		else
			option->n = display(infos, option, option->j);
	}
	if (option->flag & FLAG_D)
	{
		display(infos, option, 0);
		ft_free_opt(option);
		exit (0);
	}
	ft_ajustmaxsize(option);
	main_display2(infos, error, option);
}

static void set_opt_check(t_opt *opt)
{
	opt->n = 0;
	opt->flag = 0;
	opt->fmaj = 0;
	opt->total = 0;
	opt->max_nlink = 0;
	opt->max_uid = 0;
	opt->max_gid = 0;
	opt->max_size = 0;
	opt->max_maj = 0;
	opt->max_min = 0;
	opt->yolo = 0;
	opt->rtime = 0;
	opt->tmpsub = NULL;
	opt->realtime = NULL;
	opt->opt_d = NULL;
}

int			main(int argc, char **argv)
{
	char			**files;
	t_infos			*infos;
	t_opt			*option;
	t_err			*error;

	infos = NULL;
	error = NULL;
	if (!(option = (t_opt*)malloc(sizeof(t_opt))))
		print_err(1, '-');
	option->j = 1;
	set_opt_check(option);
	option->flag = chk_options(argc, argv);
	files = get_files(argc, argv, NULL);
	if (option->flag & FLAG_D && !files)
	{
		option->j = 0;
		files = get_files(1, NULL, ".");
		infos = get_arglist(option, &error, files);
	}
	else if (!files || files[0] == '\0')
		infos = ft_listdir(".", ".", option);
	else
		infos = get_arglist(option, &error, files);
	main_display(infos, error, option, files);
	return (0);
}
