/*
Program Number : 13 - send
Name : Akash Upadhyay
Register Number : MT2024013
Date : 21/09/2024
Description : Two programs: first program is waiting to catch SIGSTOP signal, the second program
              will send the signal (using kill system call). Find out whether the first program is able to catch
              the signal or not. (Second).
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    int pid;
    printf("Enter pid of process to stop\n");
    scanf("%d", &pid);

    printf("Sending SIGSTOP signal to process: %d\n", pid);
    kill(pid, SIGSTOP);

    printf("SIGSTOP signal sent\n");
    printf("Exiting current process (sender)\n");
    return (0);
}

// akash@DESKTOP-LD4J4EM:~/HandsOnList2$ ./a.out
// Enter pid of process to stop
// 8091
// Sending SIGSTOP signal to process: 8091
// SIGSTOP signal sent
// Exiting current process (sender)

// akash@DESKTOP-LD4J4EM:~/HandsOnList2$ ./a.out
// pid (reciever): 8091

// [1]+  Stopped                 ./a.out