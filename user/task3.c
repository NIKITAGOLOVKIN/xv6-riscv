#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char* argv[]) {

   // pipefd[0] - дескриптор для чтения, pipefd[1] - дескриптор для записи
   int pipefd[2];
   int i;
   char *wcargv[] = {"/wc", 0};

  pipe(pipefd);
    
   int pid = fork();

   if (pid == 0) {
      close(0);
      dup(pipefd[0]);
      close(pipefd[0]);
      close(pipefd[1]);

      exec("/wc", wcargv);
      exit(1);
   }

   close(pipefd[0]);

   for (i = 1; i < argc; i++) {
      write(pipefd[1], argv[i], strlen(argv[i]));
      write(pipefd[1], "\n", 1);
   }

   close(pipefd[1]);

   wait(0);
   exit(0);
}