#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    
	char *message = "and that piece of art is useful - Dora Korpar, 2015-10-19\n";
    
	size_t len = strlen(message);
    
    
	if (write(STDERR_FILENO, message, len) != len) {
        
	perror("write");
    
	return 1;
    }

    return 1;
}

