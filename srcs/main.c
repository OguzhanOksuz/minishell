/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:15:18 by ooksuz            #+#    #+#             */
/*   Updated: 2023/08/19 14:39:34 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(char	*str, t_data *data)
{
	printf("%s", str);
	if (data)
	{
		if (data->line)
			free(data->line);
		free(data);
	}
	system("leaks minishell");
	exit(0);
}

void	ft_error(t_data *data)
{
		if (data->err_code == QUOTE)
				printf("An unclosed quote exist\n");
}

void	set_data(t_data *data)
{
	data->tokens = 0;
	data->line = 0;
	data->err_code = 0;
}

void	minishell(char **env)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		ft_exit("Malloc ERROR\n", data);
	set_data(data);
	while (1)
	{
		data->line = readline("Minishell-42.Ooksuz$ ");
		if (ft_strncmp(data->line, "exit", 4) == 0)
			ft_exit("exit\n", data);
		add_history(data->line);
		tokenizer(data);
		////
		if (data->tokens)
			for (int i = 0; data->tokens[i]; i++)
				printf("[%d] = %s\n", i, data->tokens[i]);
		////
		ft_free(data);
		if (data->err_code != 0)
				ft_error(data);
	}
	(void)env;
}

int	main(int ac, char **av, char **env)
{
	minishell(env);
	(void)ac;
	(void)av;
	(void)env;
	system("leaks minishell");
}
