#include <unistd.h>
#include <sys/syscall.h>
#include <string.h>
#include <fcntl.h> 
#include <stdio.h> 
#include <stdlib.h>

int main (int argc, char** argv) {



	if (strncmp(argv[2], ".", 1) == 0 || strncmp(argv[2], "/", 1) == 0 || strncmp(argv[2], "~", 1) == 0) {
		char *symlinkpath = argv[2];
		char *actualpath;
		actualpath = realpath(symlinkpath, NULL);

		char* str1;
		char* str2;
		char* str3;
		str1 = actualpath;
		str2 = "/";
		str3 = argv[1];
		char * str4 = (char *) malloc(1 + strlen(str1)+ strlen(str2) + strlen(str3) );
		strcpy(str4, str1);
		strcat(str4, str2);
		strcat(str4, str3);
		printf("%s", str4);
		rename(argv[1], str4);
	} else {
		rename(argv[1], argv[2]);
	}
	

	/*
	char buffer[1024];
	int bytes_read;
    
	int file = open(argv[i], O_RDONLY);
	
	
	int buffLen = strlen(buffer); 
    //buffer[buffLen]   = '\n';
    buffer[buffLen+1] = '\0';

    while ((bytes_read = read(file, buffer, sizeof(buffer))) > 0) {
    	write(1, buffer, strlen(buffer));
    }
    
    close(file);
    memset(&buffer[0], 0, sizeof(buffer));*/
    
}  