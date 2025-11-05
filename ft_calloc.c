/*
*mem for arry size nmemb * size, init with 0
*@param[nmemb] size of arraz member
*@param[size] number of elements in arr
*@return[] 
*/
#include "libft.h"

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	total_size;

	if (nmemb == 0 || size == 0)
	{
		mem = malloc(1); 
		if (mem == NULL)
			return (NULL);
        ft_bzero(mem, 1); 
		return (mem);
	}
	total_size = nmemb * size;
	if (nmemb > (total_size / size))
		return (NULL);
	mem = malloc(total_size);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, total_size);
	return (mem);
}