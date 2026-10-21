#include <stdio.h>
#include <stdlib.h>

static int	get_linesize(char *string);

char	*get_line(char *dst, char *src, int size)
{
	int					i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

int	main(void)
{
	char	*copy;
	char	*string = "HelloWorld";
	int		size = get_linesize(string);

	copy = malloc(size);
	copy = get_line(copy, string, size);
	printf("%s", copy);
	free(copy);
	return (0);
}

static int	get_linesize(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\n')
	{
		i++;
	}
	return (i);
}