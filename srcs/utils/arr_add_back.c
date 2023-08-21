/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:45:14 by ooksuz            #+#    #+#             */
/*   Updated: 2023/08/20 00:25:34 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	arr_add_back(char *str, t_data *data)
{
	char	**rt;
	int		i;

	if (data->tokens == 0)
	{
			data->tokens = (char **)malloc(sizeof(char *) * 1);
			if (!data->tokens)
					ft_exit("Malloc ERROR\n", data);
			data->tokens[0] = 0;
	}
	i = 0;
	while (data->tokens[i])
		i++;
	rt = (char **)malloc(sizeof(char *) * (i + 1 + 1));
	if (!rt)
		ft_exit("Malloc Error\n", data);
	i = -1;
	while (data->tokens[++i])
		rt[i] = data->tokens[i];
	rt[i++] = str;
	rt[i] = 0;
	if (data->tokens)
		free(data->tokens);
	data->tokens = rt;
}
