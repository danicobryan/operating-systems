#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#define MAX 1024 

int cd(char **tokens){
    char *path = tokens[1];
    char *actualpath;
    actualpath = realpath(path, NULL);
    
    chdir(actualpath);

    return 1;
}

int launch(char **tokens, int size){
	if (tokens[0] == NULL) {
		return 0;
	} 

	if (strcmp(tokens[0], "cd") == 0){
		return cd(tokens);
	}

	if (strcmp(tokens[0], "supworld") == 0){
		syscall(333, NULL);
	}

	pid_t pid, pid2;
  	int status;

  	if(strcmp(tokens[size - 1], "&") == 0){
  		//printf("WOOOOOOOOOOOOO");
  		tokens[size-1] = "\0";
  		pid = fork();
		if (pid == 0) {
		   	pid2 = fork();
		   	if(pid2 == 0){
		   		execvp(tokens[0], tokens);
		   	} else {
		   		exit(0);
		   	}
		} else {
		    int status;
	        wait(&status);
		}
  	} else {
  		pid = fork();
		if (pid == 0) {
		    // Child 
		   	execvp(tokens[0], tokens);
		} else {
		    // Parent 
		    int status;
	        wait(&status);
		}
  	}

	return 1;
}


int main(int argc, char **argv){

	char buffer[1024];
    
    chdir(getenv("HOME"));

    while(1){     
    	getwd(buffer);
	    printf("BUMP::%s:: ", buffer);

	    char buf[MAX];
	    fgets(buf, MAX, stdin);
	    int bufsize = MAX;
	    //printf("string is: %s\n", buf);

	   	const char s[6] = " \t\r\n\a";

	   	char **tokens = malloc(bufsize* sizeof(char*));
	   	int position = 0;

	   	char *token;
	   
	   	token = strtok(buf, s);
	   
	   	while( token != NULL ) {

	      	tokens[position] = token;
		    position++;

		    if (position >= bufsize) {
			    bufsize += 64;
			    tokens = realloc(tokens, bufsize * sizeof(char*));
		    }
	    
	      	token = strtok(NULL, s);
	   	}

	   	tokens[position] = NULL;

	   	int execute;
	   	
	   	execute = launch(tokens, position);
	 
	    
	}
	return 0;

}

