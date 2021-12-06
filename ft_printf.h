/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: milan <milan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 17:59:30 by milan         #+#    #+#                 */
/*   Updated: 2021/09/29 13:05:58 by mgroen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_flags
{
	int	minus;
	int	num;
	int	decimal;
	int	zero;
	int	dot;
	int	asterisk;
}				t_flags;

int	ft_printf(const char *str, ...);
int	i_d_flag(int num, struct s_flags flag);
int	s_flag(char *str, struct s_flags flag);
int	c_flag(char c, struct s_flags flag);
int	x_flag(unsigned long int num, struct s_flags flag, char c);
int	u_flag(unsigned int num, struct s_flags flag);
int	p_flag(char *ptr, struct s_flags flag);

#endif
