/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 13:27:38 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/14 22:47:34 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*extract_token(char *str, int start, int len)
{
	char	*token;
	int		i;

	token = malloc(len + 1);
	if (!token)
		return (NULL);
	i = 0;
	while (i < len)
	{
		token[i] = str[start + i];
		i++;
	}
	token[i] = '\0';
	return (token);
}

int	count_tokens(char *str)
{
	int	count;
	int	in_token;
	int	i;

	count = 0;
	in_token = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != ' ' && !in_token)
		{
			in_token = 1;
			count++;
		}
		else if (str[i] == ' ')
			in_token = 0;
		i++;
	}
	return (count);
}

char	*get_token_at(char *str, int index)
{
	int	i;
	int	count;
	int	start;

	i = 0;
	count = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (!str[i])
			break ;
		start = i;
		while (str[i] && str[i] != ' ')
			i++;
		if (count == index)
			return (extract_token(str, start, i - start));
		count++;
	}
	return (NULL);
}

void	process_token(char *token, t_stack *a, t_bench *bench)
{
	int	value;
	int	error;

	if (!is_number(token))
	{
		free(token);
		error_exit(a, NULL, bench);
	}
	error = 0;
	value = ft_atoi_safe(token, &error);
	free(token);
	if (error)
		error_exit(a, NULL, bench);
	stack_push(a, value, 0);
}
