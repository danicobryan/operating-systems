#include <unistd.h>
#include <sys/syscall.h>
#include <string.h>
#include <fcntl.h> 
#include <stdio.h> 
#include <ctype.h>

int main (int argc, char** argv) {
    char buffer[16384];
	int bytes_read;
	unsigned lines = 0;
	unsigned words = 0;
	unsigned characters = 0;

	int file = open(argv[1], O_RDONLY);

	while ((bytes_read = read(file, buffer, sizeof(buffer))) > 0) {
	    for (int i=0; i<bytes_read; i++) {
	        if (buffer[i] == '\n') {
	            lines++;
	        }
	        if ((buffer[i] == ' ' && isalpha(buffer[i + 1])) || (buffer[i] == '\n' && isalpha(buffer[i + 1])) ) {
	            words++;
	        }
	        characters++; 
	    }
	}

	close(file);

    int buffLen = strlen(buffer); 
    buffer[buffLen]   = '\n';
    buffer[buffLen+1] = '\0';

    sprintf(buffer, "%d\n", lines);
    write(1, buffer, strlen(buffer));

    sprintf(buffer, "%d\n", words + 1);
    write(1, buffer, strlen(buffer));

    sprintf(buffer, "%d\n", characters);
    write(1, buffer, strlen(buffer));
    
}  