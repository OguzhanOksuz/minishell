/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_val.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:28:27 by ooksuz            #+#    #+#             */
/*   Updated: 2023/08/18 23:24:59 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_val(t_data *data, char **env, char *val)
{
	int		i;

	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], val, ft_strlen(val)) == 0)
		{
			free(val);
			return (ft_dupstr(data, env[i] + ft_strlen(val)));
		}
	}
	return (NULL);
}
