#include "main.h"

/**
 * create_file - Creates a file.
 * @filename: pointer to the name of the file to create.
 * @text_content: pointer to the strings to be written.
 *
 * Return: On success 1, On failure -1.
 */

int create_file(const char *filename, char *text_content)
{
	int f_op, f_wd, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
		for (len = 0; text_content[len];)
			len++;

	f_op = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	f_wd = write(f_op, text_content, len);

	if (f_op == -1 || f_wd == -1)
		return (-1);

	close(f_op);
	return (1);
}
