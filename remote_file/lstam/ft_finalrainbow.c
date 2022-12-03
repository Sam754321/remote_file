/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finalrainbow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 01:59:30 by tsedigi           #+#    #+#             */
/*   Updated: 2015/02/02 01:59:31 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	set_color(int type, int opt, char *rights)
{
	if (opt & FLAG_CAP_G && rights[8] == 'w')
	{
		(type == 2) ? ft_putstr(BG_CYAN) : ft_putstr(BLACK);
		(type == 3) ? ft_putstr(BG_BLACK) : ft_putstr(BLACK);
		(type == 4) ? ft_putstr(BG_YELLOW) : ft_putstr(BLACK);
		(type == 5) ? ft_putstr(BG_BLACK) : ft_putstr(BLACK);
		(type == 6) ? ft_putstr(GREEN) : ft_putstr(BLACK);
		(type == 7) ? ft_putstr(BG_RED) : ft_putstr(BLACK);
		(type == 1) ? ft_putstr(MAGENT) : ft_putstr("");
	}
	else if (opt & FLAG_CAP_G)
	{
		(type == 6 && (rights[9] == 'x')) ? ft_putstr(RED) : ft_putstr(WHITE);
		(type == 2) ? ft_putstr(WHITE) : ft_putstr("");
		(type == 0) ? ft_putstr(YELLOW) : ft_putstr("");
		(type == 3) ? ft_putstr(CYAN) : ft_putstr("");
		(type == 4) ? ft_putstr(WHITE) : ft_putstr("");
		(type == 5) ? ft_putstr(RED) : ft_putstr("");
		(type == 1) ? ft_putstr(MAGENT) : ft_putstr("");
		(type == 7) ? ft_putstr(WHITE) : ft_putstr("");
	}
}

void	reset_color(int opt)
{
	if (opt & FLAG_CAP_G)
		ft_putstr("\033[0m");
}
