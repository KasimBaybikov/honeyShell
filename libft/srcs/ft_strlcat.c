#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len1;
	size_t	j;

	i = 0;
	len1 = 0;
	j = 0;
	while (src[len1])
		len1++;
	while (dst[i] && i < dstsize)
	{
		i++;
	}
	while (src[j] && (i + j + 1) < dstsize)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < dstsize)
		dst[i + j] = '\0';
	return (len1 + i);
}
