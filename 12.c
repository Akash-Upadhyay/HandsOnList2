/*
Program Number : 12
Name : Akash Upadhyay
Register Number : MT2024013
Date : 21/09/2024
Description : Program to create an orphan process. Use kill system call to send SIGKILL signal to 
              the parent process from the child process.
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    // Child Process
    if (!fork())
    {
        sleep(5);
        printf("Child is waiting, pid: %d\n", getpid());
        kill(getppid(), 9);
        printf("Parent process killed\n");
        sleep(10);
    }
    else
    {
        printf("Parent Process, pid: %d\n", getpid());
        sleep(15);
    }

    return 0;
}


// akash@DESKTOP-LD4J4EM:~/HandsOnList2$ ./a.out
// Parent Process, pid: 7707
// Child is waiting, pid: 7708
// Parent process killed
// Killed