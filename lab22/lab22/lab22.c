#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "Fix.h"
#include <io.h>

int main()
{
    int pid, file;
    char* args[] = {
        "ps",
        NULL
    };

    file = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC);

    if (file == -1)
    {
        perror("open()");
        exit(EXIT_FAILURE);
    }
    if (dup2(file, STDOUT_FILENO) == -1)
    {
        perror("dup2()");
        exit(EXIT_FAILURE);
    }


    pid = fork();
    if (pid == 0) {
        execvp("ps", args); //потомок
    }
    else if (pid > 0) { //родитель
        execvp("ps", args);
        sleep(1);
        wait(pid);
    }
    else {
        perror("Fork error ");
        return -1;
    }
    return 0;

}
