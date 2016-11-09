#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv){
    char *p;
    char *chunk[10] = {0};
    int i = 0;
    char* tmp = "malloc";
    for(i = 5; i < 8; i++){
        chunk[i] = malloc(128);
    }
    printf("> Malloc chunk #0,#1,#2\tsize: 128\n");
    printf("> Pointer to chunk #0 is at %p\n", &chunk[5]);
    for(i = 5; i < 8; i++){
        strcpy(chunk[i], "AAAAAAAAAA");
    }
    
    for(i = 5; i < 8; i++){
        free(chunk[i]);
    }
    printf("> Free chunk #0,#1,#2\tsize: 128\n");
    printf("> Malloc chunk #0\tsize: 400\n");
    printf("> Put your data in chunk #0\n");
    p = malloc(400);
    read(0, p, 400);
    
    printf("> Press [ENTER] to free the chunk #1\n");
    getchar();
    //The double free happens here! Exploit it if you can
    free(chunk[6]);
    
    printf(">Now you got the flag:\n\n");
    system("/bin/cat flag");
    
    return 0;
}
