/*
Program Number : 17
Name : Akash Upadhyay
Register Number : MT2024013
Date : 21/09/2024
Description : Write a program to execute ls -l | wc.
				a. use dup
				b. use dup2
				c. use fcntl
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd[2];
	pipe(fd);

	int choice = 0;
	printf("1.\t Using dup\n2.\t Using dup2\n3.\t Using fcntl\n\t Enter choice: ");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		// (a.)
		if (!fork())
		{
			int c_value = 101;
			close(fd[0]);
			close(1);
			dup(fd[1]);
			execl("/bin/ls", "/bin/ls", "-l", NULL);
		}
		else
		{
			int p_value;
			close(0);
			close(fd[1]);
			dup(fd[0]);
			execl("/bin/wc", "/bin/wc", NULL);
		}
		break;
	case 2:
		// (b.)
		if (!fork())
		{
			int c_value = 101;
			close(fd[0]);
			close(1);
			dup2(fd[1], 1);
			execl("/bin/ls", "/bin/ls", "-l", NULL);
		}
		else
		{
			int p_value;
			close(0);
			close(fd[1]);
			dup2(fd[0], 0);
			execl("/bin/wc", "/bin/wc", NULL);
		}
		break;
	case 3:
		// (c.)
		if (!fork())
		{
			int c_value = 101;
			close(fd[0]);
			close(1);
			fcntl(fd[1], F_DUPFD, 1);
			execl("/bin/ls", "/bin/ls", "-l", NULL);
		}
		else
		{
			int p_value;
			close(0);
			close(fd[1]);
			fcntl(fd[0], F_DUPFD, 0);
			execl("/bin/wc", "/bin/wc", NULL);
		}
		break;
	default:
		break;
	}

	return (0);
}


// akash@DESKTOP-LD4J4EM:~/HandsOnList2$ ./a.out
// 1.       Using dup
// 2.       Using dup2
// 3.       Using fcntl
//          Enter choice: 1
//      23     200    1108
// akash@DESKTOP-LD4J4EM:~/HandsOnList2$ ./a.out
// 1.       Using dup
// 2.       Using dup2
// 3.       Using fcntl
//          Enter choice: 2
//      23     200    1108
// akash@DESKTOP-LD4J4EM:~/HandsOnList2$ ./a.out
// 1.       Using dup
// 2.       Using dup2
// 3.       Using fcntl
//          Enter choice: 3
//      23     200    1108