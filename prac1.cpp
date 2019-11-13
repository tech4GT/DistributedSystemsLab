//Pipes
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
using namespace std;
int main()
{
    // Squaring a number from parent process
    int fd1[2], fd2[2];
    // fd1 for parent to child msg
    // fd2 for child to parent msg
    pid_t p;

    if (pipe(fd1) == -1)
    {
        cout << "First pipe Failed" << endl;
        return 1;
    }
    if (pipe(fd2) == -1)
    {
        cout << "Second pipe Failed" << endl;
        return 1;
    }
    int d; // number to be squared
    cout << "Enter a number to be squared : ";
    cin >> d;
    p = fork();

    if (p < 0)
    {
        cout << "fork() Failed" << endl;
        return 1;
    }

    // Parent process
    else if (p > 0)
    {
        close(fd1[0]); // Close reading end of first pipe
        write(fd1[1], &d, sizeof(d));
        close(fd1[1]);

        // Wait for child to send result.
        wait(NULL);

        close(fd2[1]); // Close writing end of second pipe
        int sq;
        read(fd2[0], &sq, sizeof(sq));
        cout << "Square of " << d << " returned by child : " << sq << endl;
        close(fd2[0]);
    }

    // child process
    else
    {
        int d, sq;
        cout << "Child process started..." << endl;
        close(fd1[1]); // Close writing end of first pipe
        read(fd1[0], &d, sizeof(d));
        close(fd1[0]);
        sq = d * d;
        close(fd2[0]);
        write(fd2[1], &sq, sizeof(sq));
        close(fd2[1]);
        cout << "Child process ended..." << endl;
        exit(0);
    }
    return 0;
}
