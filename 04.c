/*
Program Number : 04
Name : Akash Upadhyay
Register Number : MT2024013
Date : 21/09/2024
Description : Program to measure how much time is taken to execute 100 getppid() system call using time stamp counter.
*/

#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

unsigned long long rdtsc()
{
    unsigned long long dst;
    __asm__ __volatile__("rdtsc" : "=A"(dst));
    return dst;
}

int main()
{
    long long start, end;
    start = rdtsc();

    for (int i = 0; i < 100; i++)
    {
        getppid();
    }

    end = rdtsc();
    long long int duration = end - start;

    // 1741.650 MHZ is the cpu MHZ from /proc/cpuinfo
    printf("Time taken for 100 getppid system calls: %llu clock cycles\n", duration);
    printf("Time taken for 100 getppid system calls: %f seconds\n", duration / (1741.650 * 1e6));
    return 0;
}

// akash@DESKTOP-LD4J4EM:~/HandsOnList2$ ./a.out
// Time taken for 100 getppid system calls: 73538 clock cycles
// Time taken for 100 getppid system calls: 0.000042 seconds