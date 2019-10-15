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
    long int msgtype = 0;   // æ³¨æ?1

    // å»ºç?æ¶ˆæ¯?Ÿå?
    msgid = msgget((key_t)1234, 0666 | IPC_CREAT);

    // ä»é??—ä¸­?·å?æ¶ˆæ¯ï¼Œç›´?°é??°endæ¶ˆæ¯ä¸ºæ­¢
    while (1)
    {
        if (msgrcv(msgid, (void *)&data, BUFSIZ, msgtype, 0) == -1)
        {
            fprintf(stderr, "msgrcv failed width erro: %d", errno);
        }

        printf("You wrote: %s\n", data.text);

        // ?‡åˆ°endç»“æ?
        if (strncmp(data.text, "exit\n", 3) == 0)
        {
            break;
        }
    }

    exit(EXIT_SUCCESS);
}
