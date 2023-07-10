#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: pointer to the file to be read.
 * @text_content: pointer to the texts to be written.
 *
 * Return: If the function fails or filename is NULL - -1.
 *         If the file does not exist the user lacks write permissions - -1.
 *         Otherwise - 1.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int f_op, f_wd, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
		for (len = 0; text_content[len];)
			len++;

	f_op = open(filename, O_WRONLY | O_APPEND);
	f_wd = write(f_op, text_content, len);

	if (f_op == -1 || f_wd == -1)
		return (-1);

	close(f_op);
	return (1);
}
