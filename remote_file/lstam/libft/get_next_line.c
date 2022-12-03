/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 05:08:23 by tsedigi           #+#    #+#             */
/*   Updated: 2015/02/02 02:29:06 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static t_str_list	*new_t_str_node(int fd)
{
	t_str_list *node;

	if ((node = (t_str_list*)malloc(sizeof(t_str_list))) == NULL)
		return (NULL);
	else
	{
		node->fd = fd;
		node->cur = NULL;
		node->str = NULL;
		node->next = NULL;
	}
	return (node);
}

static int			ft_return(int ret, char **line, t_str_list *node)
{
	if (ret == -1)
		return (ret);
	if (node->str == NULL)
	{
		*line = NULL;
		return (0);
	}
	*line = ft_strdup(node->str);
	free(node->str);
	node->str = NULL;
	return (0);
}

static int			ft_assign(t_str_list *node, char **line, int ret, char *bf)
{
	if (node->str)
		if ((node->cur = ft_strchr(node->str, '\n')))
		{
			*node->cur = '\0';
			*line = ft_strdup(node->str);
			ft_strcpy(node->str, node->cur + 1);
			free(bf);
			return (1);
		}
	while ((ret = read(node->fd, bf, BUFF_SIZE)) > 0)
	{
		bf[ret] = '\0';
		if ((node->cur = ft_strchr(bf, '\n')))
		{
			*node->cur = '\0';
			*line = ft_strjoin(node->str, bf);
			free(node->str);
			node->str = ft_strdup(node->cur + 1);
			free(bf);
			return (1);
		}
		node->str = ft_strjoin(node->str, bf);
	}
	free(bf);
	return (ft_return(ret, line, node));
}

static int			search_ref(t_str_list **list, int fd, char **line)
{
	t_str_list	*temp;
	t_str_list	*temp1;
	int			ret;
	char		*bf;

	bf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	temp = *list;
	ret = 0;
	while (temp)
	{
		if (temp->fd == fd)
			return (ft_assign(temp, line, ret, bf));
		temp1 = temp;
		temp = temp->next;
	}
	if ((temp1->next = new_t_str_node(fd)) == NULL)
	{
		free(bf);
		return (-1);
	}
	return (ft_assign(temp1->next, line, ret, bf));
}

int					get_next_line(int fd, char **line)
{
	static t_str_list *list;

	if (fd < 0)
		return (-1);
	if (line == NULL)
		return (-1);
	if (list == NULL)
		list = new_t_str_node(-1);
	if (list == NULL || BUFF_SIZE < 1)
		return (-1);
	return (search_ref(&list, fd, line));
}
