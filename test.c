#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	char *str = "aaabbbaaddeaae";
	char *set = "ae";
	char *re = ft_strtrim(str, set);
	size_t i = 0;
	printf("%s\n",re);
	while (re[i])
	{
		printf("%c\n",re[i]);
		i++;
	}
	printf("%d\n",re[i]);
	return (0);
}
