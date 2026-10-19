#include <stdio.h>

int	is_line(char *string)
{
	int	i;
	
	i = 0;
	while (string[i])
	{
		if (string[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	main(void)
{
	char	*string = "Hello";
	printf("%d", is_line(string));
}