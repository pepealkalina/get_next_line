/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:54:13 by preina-g          #+#    #+#             */
/*   Updated: 2022/10/10 19:26:33 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t			i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)c == s[i])
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if ((unsigned char)c == '\0')
	{
		return ((char *)&s[i]);
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*nstr;
	unsigned int	i;
	unsigned int	a;
	unsigned int	b;

	a = ft_strlen(s1);
	b = ft_strlen(s2);
	if (!s1 && !s2)
		return (NULL);
	nstr = (char *)malloc(sizeof(char) * (a + b + 1));
	if (!nstr)
		return (NULL);
	i = 0;
	while (a--)
	{
		nstr[i] = s1[i];
		i++;
	}
	a = i;
	i = 0;
	while (b--)
		nstr[a++] = s2[i++];
	nstr[a] = '\0';
	return (nstr);
}
/*Coloca el \n al final y el \0 despues del \n,
si el malloc creado es nnulo retorna NULL,
tambien comprueba el primmer caracter de lo que leemos*/

char	*ft_get_the_line(char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_read_next_line(char *buffer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (!buffer[i])
	{
		free (buffer);
		return (NULL);
	}
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * ft_strlen(buffer) - i + 1);
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		str[j++] = buffer[i++];
	str[j] = '\0';
	free (buffer);
	return (str);
}
