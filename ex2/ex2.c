// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
   FILE *file = fopen("text.txt", "r+");
   fprintf(file, "Hello, file\n");
    pid_t pid = fork() ;
    if (pid == 0) {
        printf("starting to read file within child process\n") ;
        while(1) {
            int i = fgetc(file);
            if( feof(file) ) {
                break ;
            }
            printf("%c", i);
        }
     
        fprintf(file, "Inside the child process\n");
        
        fclose(file);
    }
    if ( pid > 0) {
        printf("starting to read file within parent process\n") ;
        while(1) {
            int i = fgetc(file);
            if( feof(file) ) {
                break ;
            }
            printf("%c", i);
        }
        
        fprintf(file, "Inside the parent process\n");
        
        fclose(file);
    }
    
    return 0;
    
  
}
