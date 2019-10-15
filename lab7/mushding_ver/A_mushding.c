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
 
    // �إ߮���?�C
    msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
 
    // �V����?����?�����A����?�Jend
    while (1)
    {
        printf("Enter some text: \n");
        fgets(buffer, BUFSIZ, stdin);
        data.msg_type = 1; // �`�N2
        strcpy(data.text, buffer);
 
        // �V?�C��?�e?�u
        if (msgsnd(msgid, (void *)&data, MAX_TEXT, 0) == -1)
        {
            fprintf(stderr, "msgsnd failed\n");
            exit(EXIT_FAILURE);
        }
 
        // ?�Jend?��?�J
        if (strncmp(buffer, "exit\n", 3) == 0)
        {
            break;
        }
 
        sleep(1);
    }
 
    exit(EXIT_SUCCESS);
}