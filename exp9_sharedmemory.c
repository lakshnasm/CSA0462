#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main()
{
    key_t key = ftok("shmfile", 65);

    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);

    if (shmid == -1)
    {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    char *shm_ptr = (char*)shmat(shmid, NULL, 0);

    if (shm_ptr == (char*)(-1))
    {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    strcpy(shm_ptr, "Hello, shared memory!");

    printf("Data written to shared memory: %s\n", shm_ptr);

    shmdt(shm_ptr);

    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
