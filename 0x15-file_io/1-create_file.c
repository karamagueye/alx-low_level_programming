#include "main.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * create_file - Creates a new file and writes text content to it.
 * @filename: The name of the file to be created.
 * @text_content: The content to be written to the file.
 * Return: 1 if the operation is successful, -1 if it fails.
 */

int create_file(const char *filename, char *text_content)
{
	int file_d;
	int nletters;
	int rwr;

	if (!filename)
		return (-1);

	file_d = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (file_d == -1)

		text_content = "";
	for (nletters = 0; text_content[nletters]; nletters++)

		rwr = write(file_d, text_content, nletters);

	if (rwr == -1)
		return (-1);
	close(file_d);
	return (1);
}
