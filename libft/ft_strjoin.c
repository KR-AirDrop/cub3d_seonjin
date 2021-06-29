#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int len = 0;
	char *new_str;

	len = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	if(s1 == 0 || s2 == 0)
		return(NULL);
	if(!(new_str = (char*)malloc(sizeof(char)*len + 1)))
		return(NULL);
	i = 0;
	while(i < len && s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while(i+j < len && s2[j] != '\0')
	{
		new_str[i + j] = s2[j];
		j++;
	}
	new_str[i+j] = '\0';
	return(new_str);
}
