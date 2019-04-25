// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
 
           
            pid_t pid = fork() ;
            char *const envp[2] = {"STEPLIB=SASC.V6.LINKLIB", NULL};
            if (pid == 0) {
                //execle("/Applications/Utilities/Terminal.app", "newShell", NULL, envp);
                execl("/bin/ls", "ls", NULL) ;
                perror("exec");
                exit(1);
            } else {
                wait(NULL);
                printf("I am the parent my pid is %d\n", pid);
            }
        
            return 0 ;
        }


