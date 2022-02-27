/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 13:45:37 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/22 15:10:13 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static char	*ft_splitdup(const char *s, size_t start, size_t finish)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (finish - start + 1));
	if (!dest)
		return (NULL);
	while (start < finish)
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}

/*
  NAME
  ****
  ft_process_string ---> line counter
  SYNOPSIS
  ***********
  included in the ft_split() function
  static char	**ft_process_string(char **dest, const char *str, char c);
  DESCRIPTION
  ***********
  The function ft_process_string() counts the number of strings that result from
  dividing str based on the character c.
  At first, checks if str starts with one or more delimiter characters to ignore
  them. Once this check is done, it loops through str until it reaches the end of 
  str or until it finds other one or more delimiter characters to ignore them again.
  After doing these checks, it makes sure that there is at least one substring, so
  it counts one and repeat the process until str reaches the end.
  
  This functions che
  
  PARAMETERS
  **********
  str ---> The string to check.
  c   ---> The delimiting character.
  RETURN VALUE
  ************
  - The number of string that result from dividing str based on the character c.
*/

static char	**ft_process_string(char **dest, const char *str, char c)
{
	size_t	i;
	size_t	p1;
	size_t	start;

	i = 0;
	p1 = 0;
	start = 0;
	while (str[i])
	{
		while (str[i] != c && str[i])
		{
			i++;
			if (str[i] == c || i == ft_strlen(str))
				dest[p1++] = ft_splitdup(str, start, i);
		}
		while (str[i] == c && str[i])
		{
			i++;
			start = i;
		}
	}
	dest[p1] = NULL;
	return (dest);
}

/*
  NAME
  ****
  ft_line_counter---> line counter
  SYNOPSIS
  ***********
  included in the ft_split() function
  static size_t	ft_line_counter(const char *str, char c);
  DESCRIPTION
  ***********
  The function ft_line_counter() counts the number of strings that result from
  dividing str based on the character c.
  At first, checks if str starts with one or more delimiter characters to ignore
  them. Once this check is done, it loops through str until it reaches the end of 
  str or until it finds other one or more delimiter characters to ignore them again.
  After doing these checks, it makes sure that there is at least one substring, so
  it counts one and repeat the process until str reaches the end.
  
  PARAMETERS
  **********
  str ---> The string to check.
  c   ---> The delimiting character.
  RETURN VALUE
  ************
  - The number of string that result from dividing str based on the character c.
*/


static size_t	ft_line_counter(const char *str, char c)
{
	size_t	count;

	count = 0;
	while (*str == c && *str)
		s++;
	while (*str)
	{
		while (*str && *str != c)
			str++;
		while (*str && *str == c)
			str++;
		count++;
	}
	return (count);
}

/*
  NAME
  ****
  ft_split ---> split string
  SYNOPSIS
  ***********
  #include "libft.h"
  char	**ft_split(const char *str, char c);
  DESCRIPTION
  ***********
  The function ft_split() divides the string pointed to by str into multiple
  strings delimited by each occurrence of the 'c' character. These strings will
  be stored in a two-dimensional string, which will end with a NULL string.
  
  BUILT-IN FUNCTIONS
  ******************
  - ft_line_counter ---> counts the number of strings to be stored in the two
    dimensional string.
  - ft_process_string ---> iterates through the string and stores in each loop
    the start and end of each substring.
  - ft_fill_substrings ---> fill each substring
  
  PARAMETERS
  **********
  str ---> The string to split.
  c   ---> The delimiting character.
  RETURN VALUE
  ************
  - If the character 'c' is not in str, a two-dimensional string made up of the
    string pointed to by str plus a NULL string. 
  - If the character 'c' is in str, a two-dimensional string made up of the
    substrings plus a NULL string.
  - If str is NULL, return NULL,
*/

char	**ft_split(const char *s, char c)
{
	char	**dest;

	if (!s)
		return (NULL);
	dest = (char **)malloc(sizeof(char *) * (ft_line_counter(s, c) + 1));
	if (!dest)
		return (NULL);
	ft_fill_split(dest, s, c);
	return (dest);
}