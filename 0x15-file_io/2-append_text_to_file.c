#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * append_text_to_faile - append txt at the end of the file
 * @filename: filename
 * @text_content: added content
 * Return: 1 if the file exists, -1 if the file does not exist or if it fails
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int faile_d;
	int nletters;
	int rwr;

	if (!filename)
	{        
		return (-1);
	}
	faile_d = open(filename, O_WRONLY | O_APPEND);
	if (faile_d == -1)
	{
		return (-1);
	}
	if (text_content)
	{
		for (nletters = 0; text_content[nletters]; nletters++);
		rwr = write(faile_d, text_content, nletters);
		if (rwr == -1)
		{
            	return (-1);
        	}
	}
	close(faile_d);
    	return (1);
}

