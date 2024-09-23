/*
Program Number : 01 - b
Name : Akash Upadhyay
Register Number : MT2024013
Date : 21/09/2024
Description : Program (for ITIMER_VIRTUAL) to set a interval timer in 10sec and 10 micro second.
*/

#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

void handler()
{
    printf("Signal received\n");
}

int main()
{
    struct itimerval it;
    signal(SIGVTALRM, handler);

    /* Time to the next timer expiration.  */
    it.it_value.tv_sec = 10;
    it.it_value.tv_usec = 10;

    /* Value to put into `it_value' when the timer expires.  */
    it.it_interval.tv_sec = 10;
    it.it_interval.tv_usec = 10;

    setitimer(ITIMER_VIRTUAL, &it, NULL);

    while (1)
    {
    }
}

// akash@DESKTOP-LD4J4EM:~/HandsOnList2$ ./a.out
// Signal received
// Signal received
// ^C