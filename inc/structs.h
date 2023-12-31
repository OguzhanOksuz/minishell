/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:25:50 by ooksuz            #+#    #+#             */
/*   Updated: 2023/08/21 23:15:02 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_token
{
		char			*val;
		int				code;
		struct s_token	*back;
		struct s_token	*next;
}	t_token;

typedef struct s_data
{
	struct s_token	*tokens;
	char			*line;
	char			**env;
	char			**path;
	int				err_code;

}	t_data;

#endif
