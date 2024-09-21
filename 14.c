/*
Program Number : 14
Name : Akash Upadhyay
Register Number : MT2024013
Date : 21/09/2024
Description : Simple program to create a pipe, write to the pipe, read from pipe and display on
			  the monitor.
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd[2];
	
	pipe(fd);
	printf("pipe created with fd1: %d, fd2: %d\n", fd[0], fd[1]);

	char buf[1024];
	
    char str[1024];
    printf("Enter text to print\n");
     fgets(str, sizeof(str), stdin);
	write(fd[1], str, sizeof(str));
	read(fd[0], buf, sizeof(str));

	printf("Buffer:  %s", buf);
    printf("\n");
	getchar();

	return(0);
}


// akash@DESKTOP-LD4J4EM:~/HandsOnList2$ ./a.out
// pipe created with fd1: 3, fd2: 4
// Enter text to print
// HEllo World
// Buffer:  HEllo World

