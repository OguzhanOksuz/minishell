/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:45:14 by ooksuz            #+#    #+#             */
/*   Updated: 2023/08/19 14:38:13 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	arr_add_back(char **arr, char *str, t_data *data)
{
	char	**rt;
	int		i;

	i = 0;
	if (!arr)
	{
			arr = (char **)malloc(sizeof(char *) * 1);
			if (!arr)
					ft_exit("Malloc ERROR\n", data);
			arr[0] = 0;
	}
	while (arr[i])
		i++;
	rt = (char **)malloc(sizeof(char *) * (i + 2));
	if (!rt)
		ft_exit("Malloc Error\n", data);
	i = -1;
	while (arr[++i])
		rt[i] = arr[i];
	rt[i++] = str;
	rt[i] = 0;
	if (arr)
		free(arr);
	arr = rt;
}
