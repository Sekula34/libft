/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:08:04 by fseles            #+#    #+#             */
/*   Updated: 2023/09/08 12:08:06 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	number_of_elements (char const *s, char c)
{
	size_t noe;
	size_t i;

	i = 0;
	noe = 0;
	while(s[i] != '\0')
	{
		if(s[i] != c)
		{
			noe ++;
			while ((s[i] != c) && (s[i] != '\0'))
				i++;
		}
		i++;
	}
	return (noe); 
	
}

static char *get_me_word(char const *s, char c)
{
	int i;
	char *p;
	int j;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++; 
	}
	p = ft_calloc(i, sizeof(char)); 
	if(p == NULL)
		return (NULL); 
	j = 0;
	while(j < i)
	{
		p[j] = s[j]; 
		j++;
	}
	return (p);
}

char **ft_split(char const *s, char c)
{
	char **p;
	size_t noe;
	size_t i;
	size_t j;

	j = 0;
	i = 0;
	noe = number_of_elements(s,c);
	p = malloc(sizeof(char **) * (noe + 1));
	if(p == NULL)
		return (NULL); 
	while(j < noe)
	{
		while(s[i] == c && s[i] != '\0')
			i++;
		p[j] = get_me_word(s[i], c);
		j++;
		while(s[i] != c && s[i] != '\0')
			i++;
	}
	p[j] == NULL;
	return (p);
}

#include "libft.h"
#include <stdio.h> 

int main()
{
	char s1[] = "Filip.a.b..c."; 
	printf("%zu", number_of_elements(s1, '.'));
	return (0);
}