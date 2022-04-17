#include "utils.h"

bool	string_ends_with(const char *str, const char *end)
{
	unsigned int	i1;
	unsigned int	i2;
	unsigned int	i3;

	i1 = 0;
	while (str[i1] != '\0')
	{
		i2 = 0;
		i3 = 0;
		while (1)
		{
			if (str[i1 + i3] != end[i2])
				break ;
			if (end[i2] == '\0')
				return (true);
			i2++;
			i3++;
		}
		i1++;
	}
	return (false);
}
