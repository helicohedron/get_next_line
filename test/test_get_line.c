#include <stdio.h>

char	*get_line(void *dst, const void *src)
{
	int					i;
	const unsigned char	*source;
	unsigned char		*destination;

	i = 0;
	source = src;
	destination = dst;
	while (source[i])
	{
		destination[i] = source[i];
		i++;
	}
	return (dst);
}

int	main(void)
{
	char	*copy = NULL;
	char	*string = "Hello";

	copy = get_line(copy, string);
	printf("%s", copy);
	return (0);
}