#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads text file and prints it to the POSIX standard output.
 * @filename: file that contains text to be read.
 * @letter: number of letter to be read.
 * Return: actual number of bytes read and printed
 *          0 when there is error or NULL is returned.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    char *buffer;
    ssize_t of;
    ssize_t rf;
    ssize_t fw;

    of = open(filename, O_RDONLY);
    if (of == -1)
        return (0);
    buffer = malloc(sizeof(char) * letters);
    rf = read(of, buffer, letters);
    fw = write(STDOUT_FILENO, buffer, rf);

    free(buffer);
    close(of);
    return (fw);
}

