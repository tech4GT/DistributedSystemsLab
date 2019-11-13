//NAMED PIPES Receiver process
#include <iostream>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main()
{
    int fd;

    // FIFO file path
    string fifo = "/tmp/myfifo";

    // Creating the named file(FIFO)
    // mkfifo(<pathname>, <permission>)
    mkfifo(fifo.c_str(), 0666);

    //char arr1[80], arr2[80];
    while (1)
    {

        char s[80];
        // Open FIFO for Read only
        fd = open(fifo.c_str(), O_RDONLY);

        // Read from FIFO
        read(fd, s, sizeof(s));

        // Print the read message
        cout << "Msg: " << s << endl;
        close(fd);
    }
    return 0;
}