/*
Program Number : 19
Name : Akash Upadhyay
Register Number : MT2024013
Date : 21/09/2024
Description : Create a FIFO file by
                a. mknod command
                b. mkfifo command
                c. use strace command to find out, which command (mknod or mkfifo) is better.
                c. mknod system call
                d. mkfifo library function
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>


int main()
{
    char name[40];
    printf("Enter the name of fifo file: ");
    scanf("%s", name);

    int choice;
    printf("Choose an option:\n1.) mknod system call\n2.) mkfifo system call\n=> ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Using mknod system call...\n");

        if (mknod(name, __S_IFIFO | 0744, 0) == -1)
        {
            perror("Error: ");
            return -1;
        }
        printf("FIFO file created using mknod\n");
        break;
    case 2:
        printf("Using mkfifo system call...\n");

        if (mkfifo(name, 0744) == -1)
        {
            perror("Error: ");
            return -1;
        }
        printf("FIFO file created using mkfifo\n");
        break;

    default:
        printf("Invalid choice\n");
        break;
    }

    return (0);
}


// akash@DESKTOP-LD4J4EM:~/HandsOnList2$ ./a.out
// Enter the name of fifo file: fifo_pipe
// Choose an option:
// 1.) mknod system call
// 2.) mkfifo system call
// => 1
// Using mknod system call...
// FIFO file created using mknod
// akash@DESKTOP-LD4J4EM:~/HandsOnList2$ ./a.out
// Enter the name of fifo file: fifo_pipe2
// Choose an option:
// 1.) mknod system call
// 2.) mkfifo system call
// => 2
// Using mkfifo system call...
// FIFO file created using mkfifo