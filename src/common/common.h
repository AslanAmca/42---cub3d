/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:42:03 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/23 20:42:44 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
#define COMMON_H

#include <stdlib.h>

int ft_atoi(char *nptr);
int ft_is_digit(int c);
char **ft_split(char *string, char delimiter);
char *ft_strchr(char *s, int c);
int ft_strcmp(char *s1, char *s2);
char *ft_strdup(char *s);
int ft_strlcpy(char *dest, char *src, int n);
int ft_strlen(char *string);
int ft_strncmp(char *s1, char *s2, int n);
char *ft_strncpy(char *dest, char *src, int n);
char *ft_ft_strtrim_start(char *s1, char *set);
char *ft_strtrim(char *s1, char *set);
char *ft_substr(char *s, int start, int len);
void free_double_pointer(char **pointer);

#endif