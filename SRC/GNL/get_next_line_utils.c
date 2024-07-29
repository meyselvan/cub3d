#include "../../INC/cub3d.h"

char	*ft_gnl_strjoin(char *dest, char *src)
{
	char	*new_str;
	size_t	i;
	size_t	j;
	int		len;

	if (!dest)
	{
		dest = (char *)malloc(sizeof(char));
		dest[0] = 0;
	}
	len = ft_strlen(dest) + ft_strlen(src) + 1;
	new_str = (char *)malloc(sizeof(char) * len);
	if (!new_str)
		return (NULL);
	i = -1;
	j = 0;
	while (dest[++i] != '\0')
		new_str[i] = dest[i];
	while (src[j] != '\0')
		new_str[i++] = src[j++];
	new_str[i] = '\0';
	free(dest);
	return (new_str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	char	i;

	i = (char)c;
	if (!str)
		return (0);
	if (i == '\0')
		return ((char *)str);
	while (*str)
	{
		if (*str == i)
			return ((char *)str);
		str++;
	}
	return (0);
}
