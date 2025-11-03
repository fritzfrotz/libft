/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhollman <fhollman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 07:55:37 by fhollman          #+#    #+#             */
/*   Updated: 2025/11/03 09:55:23 by fhollman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//include guards
#ifndef LIBFT_H
# define LIBFT_H

//system includes, always before user includes because of eventual dependencies.
#include <unistd.h>
#include <stdlib.h>


//user includes

//macros and constants

//type definitions


//function prototypes

// string functio
int		ft_isalnum(int	c);
int		ft_isalpha(int	c);
int		ft_isascii(char	c);
int		ft_isdigit(int	c);
int		ft_strlen(const char	*s);
int		ft_tolower(int	c);
int		ft_toupper(int	c);
int		ft_isprint(int	c);
char	*strchr(const char *s, int c);
int		strncmp(const char *s1, const char *s2, size_t n);
char	*strnstr(const char *big, const char *little, size_t len);
char	*strrchr(const char *s, int c);
size_t	strlcpy(char	*dest, const char	*src, size_t	size);

// memory functions
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);

//conversion
int	ft_atoi(const char *nptr);

// list functions

//fd functions

void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

//include guard end
#endif