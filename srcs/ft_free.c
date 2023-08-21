/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:41:14 by ooksuz            #+#    #+#             */
/*   Updated: 2023/08/20 00:24:43 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	arr_free(char **ptr)
{
		int		i;

		if (ptr)
		{
				i = -1;
				while (ptr[++i])
						free(ptr[i]);
				free(ptr);
		}
}

void	ptr_free(char *ptr)
{
		if (ptr)
				free(ptr);
}

void	ft_free(t_data *data)
{
		if (data)
		{
				arr_free(data->tokens);
				data->tokens = 0;
				ptr_free(data->line);
				data->line = 0;
		}
}
