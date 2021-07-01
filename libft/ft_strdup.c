#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i, len;
	i = 0;
	len = 0;
	char *str;
	len = ft_strlen((char*)s);
	if(!(str = (char*)malloc(sizeof(char) * (len + 1))))
			return(NULL);
	while(i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return(str);
}