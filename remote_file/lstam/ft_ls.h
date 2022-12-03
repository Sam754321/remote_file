/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 02:00:42 by tsedigi           #+#    #+#             */
/*   Updated: 2015/02/02 02:07:11 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <grp.h>
# include <pwd.h>
# include <time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <dirent.h>
# include <stdio.h>
# include <stdlib.h>
//# include <sys/acl.h>
# include <errno.h>
# include <string.h>
# include <unistd.h>
# include <sys/ioctl.h>

# define YELLOW			"\e[33m"
# define RED			"\e[31m"
# define GREEN			"\e[32m"
# define BLUE			"\e[34m"
# define MAGENT			"\e[35m"
# define CYAN			"\e[36m"
# define WHITE			"\e[37m"
# define BLACK			"\e[30m"

# define BG_YELLOW		"\e[33m"
# define BG_RED			"\e[31m"
# define BG_GREEN		"\e[32m"
# define BG_BLUE		"\e[34m"
# define BG_MAGENT		"\e[35m"
# define BG_CYAN		"\e[36m"
# define BG_WHITE		"\e[37m"
# define BG_BLACK		"\e[30m"

# define VAL			15778463

/*
**obligatoires
*/

# define FLAG_L		   	   1
# define FLAG_CAP_R	   	   2
# define FLAG_A		   	   4
# define FLAG_T		   	   8
# define FLAG_R		  	  16

/*
**options
*/

# define FLAG_P  	   	   32
# define FLAG_U 	   	   64
# define FLAG_C 	  	  128
# define FLAG_CAP_S   	  256
# define FLAG_MIN_U   	  512
# define FLAG_CAP_A  	 1024
# define FLAG_F		 	 2048
# define FLAG_CAP_T	 	 4096
# define FLAG_G		 	 8192
# define FLAG_O	    	16384
# define FLAG_CAP_F 	32768
# define FLAG_D	    	65536
# define FLAG_CAP_G    131072
# define FLAG_COL	   262144

typedef struct		s_opt
{
	int				flag;
	int				max_nlink;
	int				max_uid;
	int				max_gid;
	int				max_size;
	int				max_maj;
	int				max_min;
	int				fmaj;
	int				total;
	int				yolo;
	int				j;
	int				n;
	time_t			rtime;
	char			*tmpsub;
	char			*realtime;
	char			*opt_d;
}					t_opt;

typedef struct		s_err
{
	char			*err_name;
	struct s_err	*nxt;
}					t_err;

typedef	struct		s_infos
{
	char			rights[12];
	char			*extend;
	char			*uid;
	char			*path;
	char			*group;
	char			*name;
	int				type;
	int				maj;
	int				min;
	int				argornot;
	time_t			date;
	int				nlinks;
	int				size;
	struct s_infos	*nxt;
}					t_infos;

/*
** checks options
*/

int					fillflag1(char argv, int flag);
int					fillflag2(char argv, int flag);
int					fillflag3(char argv, int flag);
void				print_err(int n, char c);
int					chk_options(int argc, char **argv);

/*
** getfiles
*/

char				**get_files(int argc, char **argv, char *opt_d);

/*
** sort
*/

t_infos				*ft_sort_a(t_infos *llist, t_infos *node);
t_infos				*ft_sort_ar(t_infos *llist, t_infos *node);
t_infos				*ft_sort(t_infos *llist, t_infos *node, int option);
t_infos				*ft_sort_rt(t_infos *llist, t_infos *node);
t_infos				*ft_sort_cap_sr(t_infos *lst, t_infos *node);
t_infos				*ft_sort_t(t_infos *llist, t_infos *node);
t_infos				*ft_sort_cap_s(t_infos *lst, t_infos *node);
t_infos				*ft_pushback(t_infos *llist, t_infos *node);

/*
** fillstats
*/

char				*createpath(char *name, char *path);
void				ft_fillstats(t_infos *node, struct stat *sts,\
	t_opt *option);
t_infos				*ft_newl(t_infos *llist, struct dirent *ret,\
	t_opt *option, char *path);
t_infos				*ft_listdir(char *path, char *name, t_opt *option);
void				ft_fill_uid(struct stat *sts, t_infos *node);
void				fillrights(int type, int st_mode, char *rights, char *path);
void				ft_set_max(t_opt *opt, t_infos *node);
int					typedefine(unsigned char c);

/*
** display
*/

int					display_l(t_infos *llist, t_opt *option, int fold);
int					normaldisplay(t_infos *llist, t_opt *option, int fold);
int					display(t_infos *llist, t_opt *option, int fold);
void				display_err(t_err *error);
void				displaydirs(t_infos *infos, t_opt *option, int n);
int					display_recursive(t_infos *infos,\
	t_opt *option, int n, int i);
void				first_display_l(t_infos *tmp, t_opt *option);
void				second_display_l(t_infos *tmp, t_opt *option);
void				t3_display_l(t_infos *tmp, t_opt *option,\
	time_t rtime, char *rea);
void				fourth_display_l(t_infos *tmp, t_opt *option,\
	char tab[1024]);
void				full_display_l(t_infos *tmp, t_opt *option, char tab[1024]);

/*
** arglists
*/

t_infos				*ft_arglentry(t_infos *llist,\
	t_opt *option, char *name, t_err **error);
t_infos				*get_arglist(t_opt *option, t_err **error, char **tab);
int					typedefineargs(int n);
t_err				*ft_fillerror(char *name, t_err **error);

/*
** tools
*/

int					ft_isvoid(t_infos *llist);
int					ft_checkpoints(char *name);
void				ft_putcapf(char *s, int flag);
void				ft_putspace(int nb, int max);
void				ft_put_total(int fold, t_opt *option, t_infos *llist);
int					check_long_flag(t_opt *opt);
void				ft_xattr(char *rights, char *path);
void				ft_freellist(t_infos *llist);
void				ft_putnull(t_infos *node);
void				set_color(int type, int opt, char *rights);
void				reset_color(int opt);
void				ft_ajustmaxsize(t_opt *option);
int					ft_sizeint(int i);
void				ft_free_opt(t_opt *otpion);
void				ft_free_files(char **files);
void				t4_display_l(char *realtime, t_opt *option);
int					ch(char *realtime);
int					display_col(t_infos *llist, t_opt *option, int fold);
int					ft_size_tab(char **tab);
void				print_tab_c_cap(char **tab, int max, int x_max, int col);

#endif
