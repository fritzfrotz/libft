/*
*mem for arry size nmemb * size, init with 0
*@param[nmemb] size of arraz member
*@param[size] number of elements in arr
*@return[] 
*/
#include "libft.h"

void	*calloc(size_t nmemb, size_t size)
{
	unsigned char	*mem;
	size_t	total_size;
	
	total_size = nmemb * size;
	mem = malloc(total_size);
	if (mem == NULL)
		return (NULL);
	
	ft_bzero(mem, total_size);
	return (mem);
}
