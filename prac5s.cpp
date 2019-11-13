//Shared memory sender process
#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

using namespace std;

int main()
{
    // ftok to generate unique key
    key_t key = ftok("shmfile", 65);

    // shmget returns an identifier in shmid
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    // shmat to attach to shared memory
    char *s = (char *)shmat(shmid, (void *)0, 0);

    cout << "Enter Data to be written : ";
    cin >> s;

    cout << "Data is written !!" << endl;

    shmdt(s);

    return 0;
}
