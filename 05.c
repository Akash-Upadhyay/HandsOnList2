/*
Program Number : 05
Name : Akash Upadhyay
Register Number : MT2024013
Date : 21/09/2024
Description : Program to print the system limitation of
                a. maximum length of the arguments to the exec family of functions.
                b. maximum number of simultaneous process per user id.
                c. number of clock ticks (jiffy) per second.
                d. maximum number of open files.
                e. size of a page.
                f. total number of pages in the physical memory.
                g. number of currently available pages in the physical memory.
*/

#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("---------------------System Limitations---------------------\n");
    printf("Maximum length of the arguments to the exec family of functions: %ld\n", sysconf(_SC_ARG_MAX));
    printf("Maximum number of simultaneous process per user id: %ld\n", sysconf(_SC_CHILD_MAX));
    printf("Maximum number of clock ticks (jiffy) per second: %ld\n", sysconf(_SC_CLK_TCK));
    printf("Maximum number of open files : %ld\n", sysconf(_SC_OPEN_MAX));
    printf("Maximum size of a page in bytes: %ld\n", sysconf(_SC_PAGE_SIZE));
    printf("Total number of pages in the physical memory: %ld\n", sysconf(_SC_PHYS_PAGES));
    printf("Number of currently available pages in the physical memory.: %ld\n", sysconf(_SC_AVPHYS_PAGES));
    return (0);
}

// akash@DESKTOP-LD4J4EM:~/HandsOnList2$ ./a.out
// ---------------------System Limitations---------------------
// Maximum length of the arguments to the exec family of functions: 2097152
// Maximum number of simultaneous process per user id: 7823
// Maximum number of clock ticks (jiffy) per second: 100
// Maximum number of open files : 1024
// Maximum size of a page in bytes: 4096
// Total number of pages in the physical memory: 4114430
// Number of currently available pages in the physical memory.: 1601491