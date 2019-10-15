#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/msg.h>
#include <errno.h>
 
#define MAX_TEXT 512
 
struct msg_st
{
    long int msg_type;
    char text[MAX_TEXT];
};
 
int main(int argc, char **argv)
{
    struct msg_st data;
    char buffer[BUFSIZ];
    int msgid = -1;
 
    // 建立消息?列
    msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
 
    // 向消息?里中?消息，直到?入end
    while (1)
    {
        printf("Enter some text: \n");
        fgets(buffer, BUFSIZ, stdin);
        data.msg_type = 1; // 注意2
        strcpy(data.text, buffer);
 
        // 向?列里?送?据
        if (msgsnd(msgid, (void *)&data, MAX_TEXT, 0) == -1)
        {
            fprintf(stderr, "msgsnd failed\n");
            exit(EXIT_FAILURE);
        }
 
        // ?入end?束?入
        if (strncmp(buffer, "exit\n", 3) == 0)
        {
            break;
        }
 
        sleep(1);
    }
 
    exit(EXIT_SUCCESS);
}