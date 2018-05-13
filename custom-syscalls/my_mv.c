#include <unistd.h>
#include <sys/syscall.h>
#include <string.h>
#include <fcntl.h> 
#include <stdio.h> 
#include <stdlib.h>

int main (int argc, char** argv) {

	if (strncmp(argv[2], ".", 1) == 0 || strncmp(argv[2], "/", 1) == 0 || strncmp(argv[2], "~", 1) == 0) {
		char *path = argv[2];
		char *actualpath;
		actualpath = realpath(path, NULL);

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
		//printf("%s", str4);
		rename(argv[1], str4);
	} else {
		rename(argv[1], argv[2]);
	}
    
}  