/*
Program Number : 29
Name : Akash Upadhyay
Register Number : MT2024013
Date : 21/09/2024
Description : Program to remove the message queue.
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

// Remove a message queue.
int main()
{
    key_t key = ftok(".", 'a');
    int msqid = msgget(key, 0);

    (msgctl(msqid, IPC_RMID, NULL) == -1) ? printf("Delete unsuccessful\n") : printf("Delete successful\n");
    
    return (0);
}