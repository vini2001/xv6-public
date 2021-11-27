#include "types.h"
#include "user.h"

int stdout = 1;
int stderr = 2;

int main(int argc, char *argv[]) {

  if(argc < 2){
    printf(2, "Usage: time command args\n");
    exit();
  }

  int commandArgCount = argc-1;
  char **otherArgs = (char**) malloc(sizeof(char*) * (commandArgCount));
  for(int i = 1; i < argc; i++){
    otherArgs[i-1] = argv[i];
  }

  uint xticks = 0;

  // fork the process, so we can create a child process to measure the time for
  int pid = fork();

  if(pid != 0) {
    xticks = uptime();
    // wait for the child process (the command we want to measure the execution time for) to finish
    int systemTime;
    wait_t(&systemTime);
    
    // once it has finished, we can get the time it took to execute
    uint real = uptime() - xticks;
    uint userTime = real - systemTime;

    printf(1, "real: %d ms\n", real*10);
    printf(1, "user: %d ms\n", userTime*10);
    printf(1, "sys: %d ms\n", systemTime*10);

  }else{
    int execR = exec(argv[1], argv + 1);
    printf(stderr, "execR: %d\n", execR);

    if(execR < 1) {
      printf(stderr, "Something went wrong when executing %s\n", argv[1]);
    }
  }

  free(otherArgs);
  exit();
}