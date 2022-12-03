/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 02:02:03 by tsedigi           #+#    #+#             */
/*   Updated: 2015/03/23 06:03:52 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ch(char *realtime)
{
	if (ft_strlen(realtime) > 25)
		return (0);
	return (1);
}

void	t4_display_l(char *realtime, t_opt *option)
{
	option->yolo = 3;
	while (option->yolo++ < 10 && (realtime))
		ft_putchar(realtime[option->yolo]);
	ft_putchar(' ');
	option->yolo = 23;
	while (option->yolo++ < 28 && (realtime))
		ft_putchar(realtime[option->yolo]);
}

int		check_long_flag(t_opt *option)
{
	if (option->flag & FLAG_L || option->flag & FLAG_T\
			|| option->flag & FLAG_CAP_S || option->flag & FLAG_CAP_A\
			|| option->flag & FLAG_G || option->flag & FLAG_O ||\
			option->flag & FLAG_CAP_F || option->flag & FLAG_CAP_G)
		return (1);
	return (0);
}

void	ft_fill_uid(struct stat *sts, t_infos *node)
{
	struct passwd	*uid;
	struct group	*gid;

	uid = getpwuid(sts->st_uid);
	gid = getgrgid(sts->st_gid);
	if ((uid = getpwuid(sts->st_uid)) == NULL)
		node->uid = ft_itoa(sts->st_uid);
	else
		node->uid = ft_strdup(uid->pw_name);
	if ((gid = getgrgid(sts->st_gid)) == NULL)
		node->group = ft_itoa(sts->st_gid);
	else
		node->group = ft_strdup(gid->gr_name);
}

// void	ft_xattr(char *rights, char *path)
// {
// 	acl_t		facl;
// 	acl_entry_t	ae;

// 	facl = acl_get_link_np(path, ACL_TYPE_EXTENDED);
// 	if (facl && (acl_get_entry(facl, ACL_FIRST_ENTRY, &ae) == -1))
// 		rights[10] = (' ');
// 	else if (listxattr(path, NULL, 5, XATTR_NOFOLLOW) > 0)
// 		rights[10] = ('@');
// 	else if (facl != NULL)
// 		rights[10] = ('+');
// 	else
// 		rights[10] = (' ');
// }
