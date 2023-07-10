#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to
 * the POSIX standard output.
 * @filename: text to be read.
 * @letters: number of letters to be read
 *
 * Return: the actual number of letters it could read and print.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t f_op, f_rd, f_wd;

	f_op = open(filename, O_RDONLY);
	if (f_op == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	f_rd = read(f_op, buffer, letters);
	f_wd = write(STDOUT_FILENO, buffer, f_rd);

	free(buffer);
	close(f_op);
	return (f_wd);
}
