//Message queue sender process
#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>

using namespace std;

// structure for message queue
struct buffer
{
    long type;
    char text[100];
} message;

int main()
{
    key_t key;
    int msgid;
    // ftok to generate unique key
    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);
    message.type = 1;

    cout << "Msg to be sent : ";

    cin >> message.text;
    msgsnd(msgid, &message, sizeof(message), 0);

    return 0;
}
