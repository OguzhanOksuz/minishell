/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:00:07 by ooksuz            #+#    #+#             */
/*   Updated: 2023/08/22 00:24:35 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_dollar(t_data *data, int *i)
{
		char	*rt;
		int		len;
		
		len = get_dollar_len(data, i);

}

char	*get_double_quote(t_data *data, int *i)
{
	char	*rt;
	int		j;

	*i = 1;
	while (*(data->line + *i) && *(data->line + *i) != '"')
	{
			if (*(data->line + *i) == '$')
					*i += get_dollar_len(data, i);
			*i++;
	}
	if (*(data->line + *i) == 0)
	{
			data->err_code = QUOTE_ERR;
			return (NULL);
	}
}

char	*get_single_quote(t_data *data, int *i)
{
	char	*rt;
	int		j;

	*i = 1;
	while (*(data->line + *i) && *(data->line + *i) != '\'')
			*i++;
	if (*(data->line + *i) == 0)
	{
			data->err_code = QUOTE_ERR;
			return (NULL);
	}
	rt = (char *)malloc(sizeof(char) * (*i));
	if (!rt)
			ft_exit("Malloc ERROR\n", data);
	j = -1;
	while (++j < i - 1)
			rt[j] = data->line[j + 1];
	data->line[j] = 0;
}

int	get_str(t_data *data)
{
	int	i;

	i = 0;
	if (*data->line == '\'')
			data->tokens->val = get_single_quote(data, &i);
	else if (*data->line == '"')
			data->tokens->val = get_double_quote(data, &i);
	else if (*data->line == '$')
			data->tokens->val = get_dollar(data, &i);
	else
			data->tokens->val = get_word(data, &i);
}

void	get_token(t_data *data, int code)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
			ft_exit("Malloc ERROR\n", data);
	token->code = code;
	token->next = 0;
	if (data->tokens == 0)
	{
			data->tokens->prev = 0;
	}
	else
	{
			token->prev = data->tokens;
			data->tokens->next = token;
	}
	data->tokens = token;
	if (code == STR)
			data->line += get_str(data);
	else
	{
			token->val = ft_substr(data, data->line, len);
			data->line += ft_strlen(data->tokens->val);
	}
}

void	tokenizer(t_data *data)
{
	while (*data->input)
	{
			if (*data->input == '&' && *(data->input + 1) == '&')
					get_token(data, AND);
			else if (*data->input == '<' && *(data->input + 1) == '<')
					get_token(data, DOC);
			else if (*data->input == '<' && *(data->input + 1) != '<')
					get_token(data, SMALL);
			else if (*data->input == '>' && *(data->input + 1) == '>')
					get_token(data, APP);
			else if (*data->input == '>' && *(data->input + 1) != '>')
					get_token(data, GREAT);
			else if (*data->input == '|' && *(data->input + 1) == '|')
					get_token(data, OR);
			else if (*data->input == '|' && *(data->input + 1) != '|')
					get_token(data, PIPE);
			else if (*data->input == '(')
					get_token(data, OPEN);
			else if (*data->input == ')')
					get_token(data, CLOSE);
			else
					get_token(data, STR);
	}
}
