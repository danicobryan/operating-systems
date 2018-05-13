#include <unistd.h>
#include <sys/syscall.h>
#include <string.h>
#include <fcntl.h> 
#include <stdio.h> 

int main (int argc, char** argv) {
	char buffer[1024];
	int bytes_read;
    for(int i = 1; i < argc; i++){
    	int file = open(argv[i], O_RDONLY);
		
		
		int buffLen = strlen(buffer); 
	    //buffer[buffLen]   = '\n';
	    buffer[buffLen+1] = '\0';

	    while ((bytes_read = read(file, buffer, sizeof(buffer))) > 0) {
	    	write(1, buffer, strlen(buffer));
	    }
	    
	    close(file);
	    memset(&buffer[0], 0, sizeof(buffer));

    }
    
}  