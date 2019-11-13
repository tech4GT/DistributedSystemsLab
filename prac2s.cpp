//NAMED PIPES Sender process

#include <bits/stdc++.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main()
{

    // FIFO file path

    int fd;

    // FIFO file path
    string fifo = "/tmp/myfifo";
    // Creating the named file(FIFO)
    // mkfifo(<pathname>, <permission>)
    mkfifo(fifo.c_str(), 0666);

    //char arr1[80], arr2[80];
    while (1)
    {
        // Open FIFO for write only
        fd = open(fifo.c_str(), O_WRONLY);

        string s;
        cin >> s;

        // Write the input arr2ing on FIFO
        // and close it
        write(fd, s.c_str(), s.length() + 1);
        close(fd);
    }

    return 0;
}