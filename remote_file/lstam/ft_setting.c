/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 02:01:10 by tsedigi           #+#    #+#             */
/*   Updated: 2015/02/02 02:01:11 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_sizeint(int i)
{
	int len;

	len = 1;
	while (i >= 10)
	{
		i /= 10;
		len++;
	}
	return (len);
}

void	the2ndpart(int st_mode, char *rights, char *path)
{
	rights[1] = (st_mode & S_IRUSR) ? 'r' : '-';
	rights[2] = (st_mode & S_IWUSR) ? 'w' : '-';
	if (st_mode & S_ISUID)
		rights[3] = (st_mode & S_IXUSR) ? 's' : 'S';
	else
		rights[3] = (st_mode & S_IXUSR) ? 'x' : '-';
	rights[4] = (st_mode & S_IRGRP) ? 'r' : '-';
	rights[5] = (st_mode & S_IWGRP) ? 'w' : '-';
	if (st_mode & S_ISGID)
		rights[6] = (st_mode & S_IXGRP) ? 's' : 'S';
	else
		rights[6] = (st_mode & S_IXGRP) ? 'x' : '-';
	rights[7] = (st_mode & S_IROTH) ? 'r' : '-';
	rights[8] = (st_mode & S_IWOTH) ? 'w' : '-';
	if (st_mode & S_ISVTX)
		rights[9] = (st_mode & S_IXOTH) ? 't' : 'T';
	else
		rights[9] = (st_mode & S_IXOTH) ? 'x' : '-';
	//ft_xattr(rights, path);
}

void	fillrights(int type, int st_mode, char *rights, char *path)
{
	rights[0] = (type == 0) ? '-' : rights[0];
	rights[0] = (type == 1) ? 'b' : rights[0];
	rights[0] = (type == 2) ? 'c' : rights[0];
	rights[0] = (type == 3) ? 'd' : rights[0];
	rights[0] = (type == 4) ? 'p' : rights[0];
	rights[0] = (type == 5) ? 'l' : rights[0];
	rights[0] = (type == 6) ? '-' : rights[0];
	rights[0] = (type == 7) ? 's' : rights[0];
	the2ndpart(st_mode, rights, path);
}

int		typedefine(unsigned char c)
{
	int		i;

	i = 0;
	i = (DT_BLK == c) ? 1 : i;
	i = (DT_CHR == c) ? 2 : i;
	i = (DT_DIR == c) ? 3 : i;
	i = (DT_FIFO == c) ? 4 : i;
	i = (DT_LNK == c) ? 5 : i;
	i = (DT_REG == c) ? 6 : i;
	i = (DT_SOCK == c) ? 7 : i;
	return (i);
}

void	ft_set_max(t_opt *opt, t_infos *node)
{
	int		i;

	if (node->name[0] != '.' || opt->flag & FLAG_A || opt->flag & FLAG_F)
	{
		i = ft_sizeint(node->nlinks);
		if (opt->max_nlink < i)
			opt->max_nlink = i;
		i = ft_sizeint(node->maj);
		if (opt->max_maj < i)
			opt->max_maj = i;
		i = ft_sizeint(node->min);
		if (opt->max_min < i)
			opt->max_min = i;
		i = ft_strlen(node->uid);
		if (opt->max_uid < i)
			opt->max_uid = i;
		i = ft_strlen(node->group);
		if (opt->max_gid < i)
			opt->max_gid = i;
		i = ft_sizeint(node->size);
		if (opt->max_size < i)
			opt->max_size = i;
	}
}
