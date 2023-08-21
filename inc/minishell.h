/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 00:17:06 by ooksuz            #+#    #+#             */
/*   Updated: 2023/08/19 23:50:21 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "structs.h"
# include "enum.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

void	ft_exit(char *msg, t_data *data);
void	ft_free(t_data *data);
void	tokenizer(t_data *data);
void	arr_add_back(char *str, t_data *data);

char	*get_env_val(t_data *data, char **env, char *str);

//UTILS
char	*ft_dupstr(t_data *data, char *str);
char	*ft_substr(t_data *data, char *str, int len);
int		ft_strlen(char *str);
int		ft_strncmp(char *s1, char *s2, int len);

#endif
