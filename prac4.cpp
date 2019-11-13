#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>

using namespace std;

struct sembuf sem_lock = {0, -1, SEM_UNDO};

int main()
{
    int pid, mutex = 1;
    key_t key = 1234; /* key to pass to semget() */
    int nsems = 1;    /* nsems to pass to semget() */
    int s_id = semget(key, nsems, IPC_CREAT | 0666);

    if (s_id == -1)
    {
        cout << "Could not create semaphore";
        return -1;
    }

    if ((pid = fork()) < 0)
    {
        perror("fork");
        return 1;
    }
    else if (pid == 0)
    {
        sem_wait(&s_id);
        cout << "From child process"
             << "\n";
        mutex++;
        printf("value of shared variable =%d\n", mutex);
        sem_post(&s_id);
        return 0;
    }
    sem_wait(&s_id);
    cout << "From parent process"
         << "\n";
    mutex--;
    printf("value of shared variable =%d\n", mutex);
    sem_post(&s_id);
    return 0;
}