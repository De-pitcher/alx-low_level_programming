#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buf(char *file);
void close_file(int fd);

/**
 * create_buf - Creates and allocate bytes for a buffer.
 * @file: pointer to the chars to be parsed as buffer.
 *
 * Return: A pointer to a newly-allocated buffer.
 */

char *create_buff(char *file)
{
	char *buff;

	buff = malloc(sizeof(char) * 1024);

	if (!buff)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't write ot %s'n", file);
		exit(99);
	}
	return (buff);
}

/**
 * clos_file - Closes the file descriptor parsed as argument.
 * @fd: File descriptor to be closed.
 *
 * Return: Nothing.
 */

void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: Number of argument parsed to the program.
 * @argv: Pointers to the array of arguments parsed.
 *
 * Return: On success 0 and -1 on error.
 * Description: If the argument count is incorrect - exit code 97.
 *              If file_from does not exist or cannot be read - exit code 98.
 *              If file_to cannot be created or written to - exit code 99.
 *              If file_to or file_from cannot be closed - exit code 100.
 */

int main(int argc, char *argv[])
{
	char *buff;
	int fd_from, fd_to, r, w;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buff = create_buff(argv[2]);
	fd_from = open(argv[1], O_RDONLY);
	r = read(fd_from, buff, 1024);
	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (fd_from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't reaf from file %s\n", argv[1]);
			free(buff);
			exit(98);
		}

		w = write(fd_to, buff, r);
		if (fd_from == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", argv[2]);
			free(buff);
			exit(99);
		}

		r = read(fd_from, buff, 1024);
		fd_to = open(argv[2], O_WRONLY | O_APPEND);
	} while (r > 0);

	free(buff);
	close_file(fd_from);
	close_file(fd_to);

	return (0);
}
