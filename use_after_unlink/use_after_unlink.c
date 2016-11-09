#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void get_flag(){
    printf(">Now you got the flag:\n\n");
    system("/bin/cat flag");
}

int main(int argc, char** argv){
    char *p;
    char *chunk[10] = {0};
    int i = 0;
    printf(">This is a broken binary. Normally it will end up with a crash.\n\tTry to get the flag by exploiting it!\n");
    for(i = 5; i < 8; i++){
        chunk[i] = malloc(128);
    }
    printf(">Three chunks have been allocated\n");
    printf(">The first chunk pointer is at %p\n\n", &chunk[5]);
    for(i = 5; i < 8; i++){
        strcpy(chunk[i], "AAAAAAAAAA");
    }
    printf(">I've put some data in the chunks\n\n");
    
    for(i = 5; i < 8; i++){
        free(chunk[i]);
    }
    printf(">Now the three chunks have been freed\n");
    printf(">You have a chance to put magic in the chunks\n\n");
    p = malloc(400);
    read(0, p, 400);
    
    printf(">Now I am about to free the 2nd chunk.(Again!)\n\n");
    getchar();
    //The double free happens here! Exploit it if you can
    free(chunk[6]);
    printf(">The first chunk pointer value is %p, %p\n\n", chunk[5], &chunk[5]);
    //memcpy(chunk[5], "AAAABBBBCCCCDDDD", 16);
    fgets(chunk[5], 17, stdin);
    printf(">The first chunk pointer value is %p, %p\n\n", chunk[5], &chunk[5]);
    //Now I offer you a call to the pointer you can write
    ((void (*)(void)) chunk[5])();
    
    return 0;
}
