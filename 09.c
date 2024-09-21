/*
Program Number : 09
Name : Akash Upadhyay
Register Number : MT2024013
Date : 21/09/2024
Description : Program to ignore a SIGINT signal then reset the default action of the SIGINT signal using signal system call.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(){
    printf("Ignoring SIGINT signal\n");
    signal(SIGINT, SIG_IGN);
    // CTRL + C is ignored.
    sleep(7);
    printf("\nDefault action of SIGINT signal\n");
    signal(SIGINT, SIG_DFL);
    // CTRL + C is no longer ignored.
    sleep(7);
    return(0);
}


// akash@DESKTOP-LD4J4EM:~/HandsOnList2$ ./a.out
// Ignoring SIGINT signal

// Default action of SIGINT signal