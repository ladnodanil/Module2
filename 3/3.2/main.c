#include <stdio.h>
#include <stdlib.h>
#include "ipv4.h"

int main(int argc, char *argv[]){
    srand(time(NULL));
    if (argc != 4) {
        printf("Use: %s <IP> <MASK> <N>\n", argv[0]);
        return 1;
    }
    ip(argv[1],argv[2], argv[3]);
    return 0;
}