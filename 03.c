/*
Program Number : 03
Name : Akash Upadhyay
Register Number : MT2024013
Date : 21/09/2024
Description : Program to set (any one) system resource limit using setrlimit system call.
*/

#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>

// Use sudo.
int main()
{
    struct rlimit rlim;
    printf("Old limits\n");
    getrlimit(RLIMIT_NICE, &rlim);

    printf("Soft - %lu\n", rlim.rlim_cur);
    printf("Hard - %lu\n", rlim.rlim_max);

    rlim.rlim_cur = 2;
    rlim.rlim_max = 3;

    if (setrlimit(RLIMIT_NICE, &rlim) != -1)
    {
        printf("New limits\n");
        getrlimit(RLIMIT_NICE, &rlim);

        printf("Soft - %lu\n", rlim.rlim_cur);
        printf("Hard - %lu\n", rlim.rlim_max);
    }
    else
    {
        perror("Error");
    }

    return(0);
}

// akash@DESKTOP-LD4J4EM:~/HandsOnList2$ ./a.out
// Old limits
// Soft - 0
// Hard - 0
// Error: Operation not permitted

// akash@DESKTOP-LD4J4EM:~/HandsOnList2$ ./a.out
// Old limits
// Soft - 0
// Hard - 0
// New limits
// Soft - 2
// Hard - 3
// 