#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    pid_t pid = fork();
    int status;
    if (pid) {
              printf("parent\n");
              wait(&status);
    }
    else {
          execl("/home/orsay/Desktop/OS/process/child.exe", "child.exe", (char*)NULL);
    }
    return 0;
}
