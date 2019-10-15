#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>
#include <errno.h>

struct msg_st
{
    long int msg_type;
    char text[BUFSIZ];
};

int main(int argc, char **argv)
{
    int msgid = -1;
    struct msg_st data;
    long int msgtype = 0;   // 注�?1

    // 建�?消息?��?
    msgid = msgget((key_t)1234, 0666 | IPC_CREAT);

    // 从�??�中?��?消息，直?��??�end消息为止
    while (1)
    {
        if (msgrcv(msgid, (void *)&data, BUFSIZ, msgtype, 0) == -1)
        {
            fprintf(stderr, "msgrcv failed width erro: %d", errno);
        }

        printf("You wrote: %s\n", data.text);

        // ?�到end结�?
        if (strncmp(data.text, "exit\n", 3) == 0)
        {
            break;
        }
    }

    exit(EXIT_SUCCESS);
}
