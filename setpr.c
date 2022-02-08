#include "types.h"
#include "user.h"
#include "stat.h"

int stdout = 1;
int stderr = 2;

int
main(int argc, char *argv[])
{
  int priority, pid;
  if(argc < 3) {
    printf(stderr, "Invalid command. Usage: setpr {pid} {priority}\n");
    exit();
  }

  pid = atoi(argv[1]);
  priority = atoi(argv[2]);
  if (priority < 1 || priority > 10){
    printf(stderr, "The priority must be a number from 1 to 10!\n");
    exit();
  }

  setprio(pid, priority);
  exit();
}
