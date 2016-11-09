#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "config.h"

int main(int argc, char** argv){
    char *p;
    char *chunk[10] = {0};
    int i = 0;
    
    int new_size = C_SIZE_0 + C_SIZE_1 + C_SIZE_2 + 16;
    chunk[5] = malloc(C_SIZE_0);
    chunk[6] = malloc(C_SIZE_1);
    chunk[7] = malloc(C_SIZE_2);
    
    printf("> Malloc chunk #0,#1,#2\tsize: %d, %d, %d\n", C_SIZE_0, C_SIZE_1, C_SIZE_2);
    printf("> Pointer to chunk #0 is at %p\n", &chunk[5]);
    for(i = 5; i < 8; i++){
        strcpy(chunk[i], "AAAAAAAAAA");
    }
    
    for(i = 5; i < 8; i++){
        free(chunk[i]);
    }
    printf("> Free chunk #0,#1,#2\tsize: %d, %d, %d\n", C_SIZE_0, C_SIZE_1, C_SIZE_2);
    printf("> Malloc chunk #0\tsize: %d\n", new_size);
    printf("> Put your data in chunk #0\n");
    p = malloc(new_size);
    read(0, p, new_size);
    
    printf("> Press [ENTER] to free the chunk #1\n");
    getchar();
    //The double free happens here! Exploit it if you can
    free(chunk[6]);
    
    printf(">Now you got the flag:\n\n");
    system("/bin/cat flag");
    
    return 0;
}
