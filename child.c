#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pid = getpid();
    system("pstree -s");
    return 0;
}
