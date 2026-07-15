/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 11:57:11 by mcalleja          #+#    #+#             */
/*   Updated: 2026/07/15 11:57:19 by mcalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"

void	sh_swap(t_stack *s);
void	sh_push(t_stack *src, t_stack *dest);
void	sh_rotate(t_stack *s);
void	sh_rev_rotate(t_stack *s);

int		execute_cmd(char *cmd, t_stack *a, t_stack *b, t_bench *bench);
int		read_line(char *buffer);
void	checker_error(t_stack *a, t_stack *b);

#endif
