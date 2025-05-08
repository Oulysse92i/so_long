/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <ugaudich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:10:19 by ugaudich          #+#    #+#             */
/*   Updated: 2024/12/03 09:09:05 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_get_line(int fd, char *line, char *buf);
size_t	gnl_strlen(char *str);
char	*ft_strchr(char *str, int c);
char	*gnl_strjoin(char *line, char *buf);
char	*ft_get_rest(char *line);
char	*trim_prev_line(char *line);
char	*get_next_line(int fd);

#endif
