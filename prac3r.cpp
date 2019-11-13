//Message queue receiver process
#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>

using namespace std;

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

    // msgget creates a message queue
    // and returns identifier
    msgid = msgget(key, 0666 | IPC_CREAT);

    // msgrcv to receive message
    msgrcv(msgid, &message, sizeof(message), 1, 0);

    // display the message
    cout << "Msg Received : " << message.text << endl;

    // to destroy the message queue
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
