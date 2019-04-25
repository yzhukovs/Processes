// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 12 ;
    pid_t pid = fork() ;
if (pid == 0) {
    printf("x is %d in the child\n", x) ;
    x = 100 ;
    printf("x is changed to %d in the child process\n", x) ;
}
    if ( pid > 0) {
        printf("x is %d in the parent\n", x) ;
        x = 200 ;
        printf("x is changed to %d in the parent process\n", x) ;
    }
    
    return 0;
}
