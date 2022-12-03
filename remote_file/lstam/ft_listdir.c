/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 02:00:29 by tsedigi           #+#    #+#             */
/*   Updated: 2015/02/02 02:00:31 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*createpath(char *name, char *path)
{
	char		*realpath;
	char		*tmp;

	if (path[ft_strlen(path) - 1] != '/')
	{
		realpath = ft_strjoin(path, "/");
		tmp = ft_strdup(realpath);
		free (realpath);
	}
	else
		tmp = ft_strdup(path);
	realpath = ft_strjoin(tmp, name);
	free (tmp);
	return (realpath);
}

t_infos	*ft_sort(t_infos *llist, t_infos *node, int option)
{
	if (option & FLAG_F)
		return (ft_pushback(llist, node));
	if (option & FLAG_R)
	{
		if (option & FLAG_CAP_S)
			return (ft_sort_cap_sr(llist, node));
		else if (option & FLAG_T)
			return (ft_sort_rt(llist, node));
		else
			return (ft_sort_ar(llist, node));
	}
	else
	{
		if (option & FLAG_CAP_S)
			return (ft_sort_cap_s(llist, node));
		else if (option & FLAG_T)
			return (ft_sort_t(llist, node));
		else
			return (ft_sort_a(llist, node));
	}
}

void	ft_fillstats(t_infos *node, struct stat *sts, t_opt *option)
{
	ft_fill_uid(sts, node);
	if ((sts->st_rdev) && (sts->st_size == 0))
		option->fmaj = 1;
	node->nlinks = sts->st_nlink;
	node->size = sts->st_size;
	fillrights(node->type, sts->st_mode, node->rights, node->path);
	if (option->flag & FLAG_U)
		node->date = sts->st_ctime;
	else if (option->flag & FLAG_C)
		node->date = sts->st_ctime;
	else if (option->flag & FLAG_MIN_U)
		node->date = sts->st_atime;
	else
		node->date = sts->st_mtime;
	//node->maj = major(sts->st_rdev);
	//node->min = minor(sts->st_rdev);
	if (node->name[0] != '.' || option->flag & FLAG_A ||\
		option->flag & FLAG_CAP_A || option->flag & FLAG_F)
	{
		ft_set_max(option, node);
		option->total += sts->st_blocks;
	}
}

t_infos	*ft_newl(t_infos *llist, struct dirent *ret, t_opt *option, char *path)
{
	t_infos		*node;
	struct stat buf;

	if (!(node = (t_infos*)malloc(sizeof(t_infos))))
		print_err(1, '-');
	ft_putnull(node);
	ft_bzero(node->rights, 12);
	node->path = createpath(ret->d_name, path);
	if (lstat(node->path, &buf) == -1)
		perror("Erreur de lstat =");
	node->type = typedefine(ret->d_type);
	if (node->type == 0)
		node->type = typedefineargs(buf.st_mode);
	node->name = ft_strdup(ret->d_name);
	if (check_long_flag(option) == 1)
		ft_fillstats(node, &buf, option);
	if (!llist)
	{
		llist = node;
		node->nxt = NULL;
	}
	else
		llist = ft_sort(llist, node, option->flag);
	return (llist);
}

t_infos	*ft_listdir(char *path, char *name, t_opt *option)
{
	t_infos			*llist;
	DIR				*fd;
	struct dirent	*ret;

	llist = (t_infos *)malloc(sizeof(llist));
	llist = NULL;
	option->j = 0;
	if ((fd = opendir(path)) != NULL)
	{
		while ((ret = readdir(fd)) != NULL)
			llist = ft_newl(llist, ret, option, path);
	}
	else
	{
		ft_putchar('\n');
		ft_putstr_fd(path, 2);
		ft_putendl_fd(":", 2);
		ft_putstr_fd("ft_ls: ", 2);
		perror(name);
		return (NULL);
	}
	if (closedir(fd) == -1)
		print_err(1, '-');
	return (llist);
}
