#include "../../INC/cub3D.h"

char	*ft_read_fd(char *str, int fd)
{
	int		byte;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	byte = 1;
	while (!ft_strchr(str, '\n') && byte)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
		{
			free (buffer);
			if (str)
				free (str);
			return (NULL);
		}
		buffer[byte] = '\0';
		str = ft_gnl_strjoin(str, buffer);
	}
	free (buffer);
	return (str);
}

char	*ft_getline_fd(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_update_fd(char *str)
{
	int		i;
	int		j;
	char	*updated_lines;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	if (!str[i])
	{
		free (str);
		return (NULL);
	}
	updated_lines = (char *)malloc(sizeof(char) * ft_strlen(str) - i + 1);
	if (!updated_lines)
		return (NULL);
	while (str[i])
		updated_lines[j++] = str[i++];
	updated_lines[j] = '\0';
	free (str);
	return (updated_lines);
}

char	*get_next_line(int fd)
{
	char		*re_line;
	static char	*all_lines;

	if (fd < 0 && BUFFER_SIZE < 0)
		return (NULL);
	all_lines = ft_read_fd(all_lines, fd);
	if (!all_lines)
		return (NULL);
	re_line = ft_getline_fd(all_lines);
	all_lines = ft_update_fd(all_lines);
	return (re_line);
}
