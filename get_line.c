#include "shell.h"

/**
 * get_line - a function that reads a line.
 * @data: program's data struct
 * Return: bytes.
 */
int get_line(program_data *data)
{
	char buff[BUFFER_SIZE] = {'\0'};
	static char *array_cmd[10] = {NULL};
	static char array_optr[10] = {'\0'};
	ssize_t bytes_read, i = 0;

	if (!array_cmd[0] || (array_optr[0] == '&' && errno != 0) ||
			(array_optr[0] == '|' && errno == 0))
	{
		for (i = 0; array_cmd[i]; i++)
		{
			free(array_cmd[i]);
			array_cmd[i] = NULL;
		}

		bytes_read = read(data->fd, &buff, BUFFER_SIZE - 1);
		if (bytes_read == 0)
			return (-1);

		i = 0;
		do

		{
			array_cmd[i] = str_d(str_tok(i ? NULL : buff, "\n;"));
			i = chc_op(array_cmd, i, array_optr);
		}

		while (array_cmd[i++]);
	}

	data->input = array_cmd[0];
	for (i = 0; array_cmd[i]; i++)
	{
		array_cmd[i] = array_cmd[i + 1];
		array_optr[i] = array_optr[i + 1];
	}

	return (str_l(data->input));
}
