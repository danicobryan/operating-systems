#include <unistd.h>
#include <sys/syscall.h>
#include <string.h>
#include <fcntl.h> 
#include <stdio.h> 
#include <stdlib.h>

int main (int argc, char** argv) {
    char buffer[1024];

    char *path = argv[1];
    char *actualpath;
    actualpath = realpath(path, NULL);
    
    chdir(actualpath);


    getwd(buffer);

    int buffLen = strlen(buffer); 
    buffer[buffLen]   = '\n';
    buffer[buffLen+1] = '\0';     
      

    write(1, buffer, strlen(buffer));
    
}   