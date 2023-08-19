/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:41:14 by ooksuz            #+#    #+#             */
/*   Updated: 2023/08/19 14:26:42 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	arr_free(void **ptr)
{
		int		i;

		if (ptr)
		{
				i = -1;
				while (ptr[++i])
						free(ptr[i]);
				free(ptr);
		}
		ptr = 0;
}

void	ptr_free(void *ptr)
{
		if (ptr)
				free(ptr);
		ptr = 0;
}

void	ft_free(t_data *data)
{
		if (data)
		{
				arr_free((void **)data->tokens);
				ptr_free((void *)data->line);
		}
}
