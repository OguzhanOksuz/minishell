/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dupstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 22:33:39 by ooksuz            #+#    #+#             */
/*   Updated: 2023/08/19 11:21:52 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_dupstr(t_data *data, char *str)
{
		char	*rt;
		int		i;

		rt = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
		if (!rt)
				ft_exit("Malloc ERROR\n", data);
		i = -1;
		while (str[++i])
				rt[i] = str[i];
		rt[i] = 0;
		return (rt);
}
