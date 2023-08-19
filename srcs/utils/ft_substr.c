/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 20:19:06 by ooksuz            #+#    #+#             */
/*   Updated: 2023/08/18 16:53:19 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_substr(t_data *data, char *str, int len)
{
		char	*rt;
		int		i;

		rt = (char *)malloc(sizeof(char) * (len + 1));
		if (!rt)
				ft_exit("Malloc ERROR\n", data);
		i = 0;
		while(str[i] && i < len)
		{
				rt[i] = str[i];
				i++;
		}
		rt[i] = 0;
		return (rt);
}
