/*
Program Number : 15
Name : Akash Upadhyay
Register Number : MT2024013
Date : 21/09/2024
Description : Simple program to send some data from parent to the child process using a pipe.
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd[2];
	pipe(fd);

    // Child process.
	if(!fork()){
        printf("In child process\n");
		int c_value = 1011;
		close(fd[0]);
        printf("Writing to pipe (in child process)\n");
		write(fd[1], &c_value, sizeof(int));
	}
    // Parent process.
	else{
        printf("In parent process\n");
		int p_value;
		close(fd[1]);
		read(fd[0], &p_value, sizeof(int));
		printf("Data from child in parent process: %d\n", p_value);
	}

	return(0);
}

// akash@DESKTOP-LD4J4EM:~/HandsOnList2$ ./a.out
// In parent process
// In child process
// Writing to pipe (in child process)
// Data from child in parent process: 1011
