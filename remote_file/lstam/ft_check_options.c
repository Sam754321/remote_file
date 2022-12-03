/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 01:58:51 by tsedigi           #+#    #+#             */
/*   Updated: 2015/02/02 01:58:52 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_err(int n, char c)
{
	if (n == 0)
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(c, 2);
		ft_putchar_fd('\n', 2);
		ft_putendl_fd("usage: ft_ls [-AFGSTRUacdfgloprtu] [file ...]", 2);
		exit (-1);
	}
	if (n == 1)
	{
		ft_putendl_fd("malloc has failed", 2);
		exit (-1);
	}
	if (n == 2)
	{
		ft_putendl_fd("ft_ls: fts_open: No such file or directory", 2);
		exit (-1);
	}
}

static int	chk_validarg(char *s)
{
	int i;

	i = 0;
	while (*s)
	{
		if (*s == '-')
		{
			s++;
			i++;
		}
		if (i == 1)
			return (0);
		if ((*s != 'l') && (*s != 'R') && (*s != 'G')\
			&& (*s != 'r') && (*s != 't') && (*s != 'a') && (*s != '1')\
			&& (*s != 'p') && (*s != 'U') && (*s != 'c') && (*s != 'S')\
			&& (*s != 'u') && (*s != 'A') && (*s != 'f') && (*s != 'T')\
			&& (*s != 'g') && (*s != 'o') && (*s != 'F') && (*s != 'd')\
			&& (*s != 'C'))
		{
			print_err(0, *s);
			return (1);
		}
		s++;
	}
	return (0);
}

static int	chk_score(char *argv)
{
	int		i;
	int		x;

	i = 0;
	while (argv[i] == '-')
		i++;
	if (i == 1)
		return (0);
	x = i;
	while (argv[x])
	{
		if (argv[x] == '-')
			print_err(0, '-');
		x++;
	}
	if ((i == 2) && (argv[i] != '\0'))
		print_err(0, '-');
	if (i == 2)
		return (1);
	if (i > 2)
		print_err(0, '-');
	return (0);
}

static int	reco_options(char *argv)
{
	int		flag;

	flag = 0;
	if (*argv == '-')
		while (*argv)
		{
			if (chk_score(argv) != 0)
				break ;
			if (chk_validarg(argv) != 0)
				print_err(0, '-');
			flag = fillflag1(*argv, flag);
			flag = fillflag2(*argv, flag);
			flag = fillflag3(*argv, flag);
			argv++;
		}
	return (flag);
}

int			chk_options(int argc, char **argv)
{
	int		i;
	int		flag;

	flag = 0;
	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			if (argv[i][0] == '-')
			{
				if ((chk_score(argv[i]) != 0))
					break ;
				flag = flag | reco_options(argv[i]);
				i++;
			}
			else
				break ;
		}
	}
	return (flag);
}
