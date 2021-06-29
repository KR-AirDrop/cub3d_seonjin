#include "libft.h"

int find_len(long n)
{
	int len;
	len = 0;
	if(n < 0)
	{
		n = n * -1;
		len++;
	}
	if (n == 0)
		return(1);
	while(n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
char *ft_itoa(int n)
{
	char *number_arry;
	long number;
	int len;
	number = (long) n;
	len = find_len(n);
	if(!(number_arry = (char*)malloc(sizeof(char) * (len+1))))
		return(NULL);
	number_arry[--len] = '\0';
	if( number == 0)
	{
		number_arry[0]  = '0';
		return(number_arry);
	}
	if(number <0)
	{
		number_arry[0] = '-';
		number = number * -1;
	}
	while(number > 0)
	{
		number_arry[len] = 48 + (number % 10);
		number = number / 10;
		len--;
	}
	len = find_len(n);
	number_arry[len] = '\0';
	return(number_arry);
}
