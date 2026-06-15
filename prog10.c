#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct message
{
    long msg_type;
    char msg_text[100];
};

int main()
{
    key_t key = ftok("msgqfile", 65);

    int msgid = msgget(key, IPC_CREAT | 0666);

    if (msgid == -1)
    {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    struct message msg;
    msg.msg_type = 1;

    strcpy(msg.msg_text, "Hello, message queue!");

    if (msgsnd(msgid, &msg, sizeof(msg.msg_text), 0) == -1)
    {
        perror("msgsnd");
        exit(EXIT_FAILURE);
    }

    printf("Producer: Data sent = %s\n", msg.msg_text);

    if (msgrcv(msgid, &msg, sizeof(msg.msg_text), 1, 0) == -1)
    {
        perror("msgrcv");
        exit(EXIT_FAILURE);
    }

    printf("Consumer: Data received = %s\n", msg.msg_text);

    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
