/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:17:13 by amaarifa          #+#    #+#             */
/*   Updated: 2022/11/19 11:27:06 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

char	*ft_substr2(char *s, unsigned int start, size_t len);
int		get_nl(const char *s);
char	*ft_strdup(const char	*src);
size_t	ft_strlen(const char *s);
char	*ft_strjoin2(char *s1, char *s2);
char	*get_next_line(int fd);
char	*get_line(char **s);

#endif
