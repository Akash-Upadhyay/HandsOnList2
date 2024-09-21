/*
Program Number : 13 - receive
Name : Akash Upadhyay
Register Number : MT2024013
Date : 21/09/2024
Description : Two programs: first program is waiting to catch SIGSTOP signal, the second program
              will send the signal (using kill system call). Find out whether the first program is able to catch
              the signal or not. (First).
*/

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <bits/sigaction.h>

void catch (int sig)
{
    printf("Signal Caught - %d\n", sig);
    exit(0);
}

int main()
{
    printf("pid (reciever): %d\n", getpid());

    struct sigaction ac;
    memset(&ac, 0, sizeof(ac));
    
    // The handler will be ignored, as SIGSTOP and SIGKILL can not be caught.
    ac.sa_handler = catch;
    for (;;)
    {
        sigaction(SIGSTOP, &ac, NULL);
    }
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