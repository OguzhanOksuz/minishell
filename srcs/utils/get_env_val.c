/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_val.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:28:27 by ooksuz            #+#    #+#             */
/*   Updated: 2023/08/17 23:34:02 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_val(char **env, char *val)
{
	int		i;

	i = -1;
	while (env[++i])
		if (ft_strncmp(env[i], val, ft_strlen(val)) == 0)
			return (env[i] + ft_strlen(val));
	return (NULL);
}
