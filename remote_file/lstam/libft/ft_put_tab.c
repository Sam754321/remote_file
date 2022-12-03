/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 07:59:25 by tsedigi           #+#    #+#             */
/*   Updated: 2015/03/18 07:59:26 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_put_tab(char **tab, char c)
{
	if (!tab)
		return ;
	while (*tab)
	{
		ft_putstr(*tab);
		if (c)
			ft_putchar(c);
		tab++;
	}
}
