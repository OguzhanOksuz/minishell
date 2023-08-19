/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:00:07 by ooksuz            #+#    #+#             */
/*   Updated: 2023/08/19 14:45:16 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_word(t_data *data, int *i)
{
		int		j;

		j = 0;
		while (data->line[*i + j] == ' ')
				j++;
		while (data->line[*i + j] && data->line[*i + j] != ' ')
				j++;
		*i += j;
		return (ft_substr(data, data->line + *i - j, j));
}
/*
char	*get_dollar(t_data *data, int *i)
{
}

char	*get_single_quotes(t_data *data, int *i)
{
	int	j;

	j = 1;
	while (data->line[*i + j] != '\'' && data->line[*i + j])
			j++;
	if (data->line[*i + j] == 0)
	{
			data->err_code = QUOTE;
			*i += j;
	}
	else
	{
			*i += j + 1;
			return (ft_substr(data, data->line + *i - j - 1, j));
	}
	return (NULL);
}

char	*get_double_quotes(t_data *data, int *i)
{

}
*/
void	tokenizer(t_data *data)
{
	int		i;

	i = -1;
	while (data->line[++i])
	{
			/*
		if (data->line[i] == '\'')
			arr_add_back(data->tokens, get_single_quotes(data, &i), data);
		else if (data->line[i] == '"')
			arr_add_back(data->tokens, get_double_quotes(data, &i), data);
		else if (data->line[i] == '$')
			arr_add_back(data->tokens, get_dollar(data, &i), data);
		else
		*/
			arr_add_back(data->tokens, get_word(data, &i), data);
	}
}
